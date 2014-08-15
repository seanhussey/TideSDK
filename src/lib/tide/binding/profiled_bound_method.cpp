/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "../tide.h"
#include <cstdio>
#include <cstring>
#include <Poco/Stopwatch.h>

namespace tide
{
    ProfiledBoundMethod::ProfiledBoundMethod(TiMethodRef delegate, std::string& type) :
        ProfiledBoundObject(delegate),
        method(delegate),
        fullType(type),
        count(1)
    {
    }

    ProfiledBoundMethod::~ProfiledBoundMethod()
    {
    }

    ValueRef ProfiledBoundMethod::Call(const ValueList& args)
    {
        std::string type = this->GetType();

        ValueRef value;
        Poco::Stopwatch sw;
        sw.start();
        try {
            value = method->Call(args);
        } catch (...) {
            sw.stop();
            this->Log("call", type, sw.elapsed());
            throw;
        }

        sw.stop();
        this->Log("call", type, sw.elapsed());
        return this->Wrap(value, type);
    }

    void ProfiledBoundMethod::Set(const char *name, ValueRef value)
    {
        method->Set(name,value);
    }

    ValueRef ProfiledBoundMethod::Get(const char *name)
    {
        return method->Get(name);
    }

    SharedStringList ProfiledBoundMethod::GetPropertyNames()
    {
        return method->GetPropertyNames();
    }

    bool ProfiledBoundMethod::HasProperty(const char* name)
    {
        return method->HasProperty(name);
    }

    std::string& ProfiledBoundMethod::GetType()
    {
        return fullType;
    }
}
