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
    StaticBoundObject::StaticBoundObject(const char* type)
        : TiObject(type)
    {
    }

    StaticBoundObject::~StaticBoundObject()
    {
    }

    bool StaticBoundObject::HasProperty(const char* name)
    {
        return properties.find(name) != properties.end();
    }
    
    ValueRef StaticBoundObject::Get(const char* name)
    {
        Poco::Mutex::ScopedLock lock(mutex);
        std::map<std::string, ValueRef>::iterator iter = 
            properties.find(std::string(name));

        if (iter == properties.end())
            return Value::Undefined;
        return iter->second;
    }

    void StaticBoundObject::Set(const char* name, ValueRef value)
    {
        Poco::Mutex::ScopedLock lock(mutex);
        this->properties[std::string(name)] = value;
    }

    void StaticBoundObject::Unset(const char* name)
    {
        Poco::Mutex::ScopedLock lock(mutex);
        std::map<std::string, ValueRef>::iterator iter = 
            properties.find(std::string(name));

        if (this->properties.end() == iter)
            return;
        this->properties.erase(iter);
    }

    SharedStringList StaticBoundObject::GetPropertyNames()
    {
        SharedStringList list(new StringList());
        Poco::Mutex::ScopedLock lock(mutex);
        std::map<std::string, ValueRef>::iterator iter = properties.begin();

        while (iter != properties.end())
            list->push_back(new std::string((iter++)->first));

        return list;
    }
}
