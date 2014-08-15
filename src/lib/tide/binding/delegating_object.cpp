/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "../tide.h"
#include <cstring>

namespace tide
{
    DelegatingObject::DelegatingObject(TiObjectRef global) :
        global(global),
        local(new StaticBoundObject())
    {
    }

    DelegatingObject::DelegatingObject(
        TiObjectRef global, TiObjectRef local) :
        global(global),
        local(local)
    {
    }

    DelegatingObject::~DelegatingObject()
    {
    }

    ValueRef DelegatingObject::Get(const char *name)
    {
        Poco::Mutex::ScopedLock lock(mutex);

        ValueRef val = local->Get(name);
        if (!val->IsUndefined())
        {
            // We want properties of the local object to
            // override // properties set on the global object.
            return val;
        }
        else
        {
            // If the property isn't found on the local object, search
            // for it in the global object.
            return this->global->Get(name);
        }
    }

    void DelegatingObject::Set(const char *name, ValueRef value)
    {
        // We want to set the property on both
        // the local and the global object.
        Poco::Mutex::ScopedLock lock(mutex);
        local->Set(name, value);
        global->Set(name, value);
    }

    bool DelegatingObject::HasProperty(const char* name)
    {
        return global->HasProperty(name) || local->HasProperty(name);
    }

    SharedStringList DelegatingObject::GetPropertyNames()
    {
        Poco::Mutex::ScopedLock lock(mutex);

        SharedStringList globalList = global->GetPropertyNames();
        SharedStringList localList = local->GetPropertyNames();

        for (size_t i = 0; i < globalList->size(); i++)
        {
            bool found = false;
            for (size_t j = 0; j < localList->size(); j++)
            {
                if (globalList->at(i).get() == localList->at(j).get())
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                localList->push_back(globalList->at(i));
            }
        }
        return localList;
    }
}
