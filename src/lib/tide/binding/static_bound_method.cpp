/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "../tide.h"

namespace tide
{
    StaticBoundMethod::StaticBoundMethod(MethodCallback* callback, const char *type)
        : TiMethod(type), callback(callback)
    {
        this->object = new StaticBoundObject();
    }

    StaticBoundMethod::~StaticBoundMethod()
    {
    }

    ValueRef StaticBoundMethod::Call(const ValueList& args)
    {
        ValueRef tv = Value::NewUndefined();
        if (this->callback)
        {
            this->callback->Run(args, tv);
        }
        return tv;
    }

    void StaticBoundMethod::Set(const char *name, ValueRef value)
    {
        this->object->Set(name, value);
    }

    ValueRef StaticBoundMethod::Get(const char *name)
    {
        return this->object->Get(name);
    }

    SharedStringList StaticBoundMethod::GetPropertyNames()
    {
        return this->object->GetPropertyNames();
    }
}
