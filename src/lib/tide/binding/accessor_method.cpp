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

namespace tide
{
    AccessorMethod::AccessorMethod(MethodCallback* callback, const char *type)
        : StaticBoundMethod(callback, type)
    {
    }

    bool AccessorMethod::HasProperty(const char* name)
    {
        return StaticBoundMethod::HasProperty(name) || this->HasGetterFor(name);
    }

    void AccessorMethod::Set(const char* name, ValueRef value)
    {
        if (!this->UseSetter(name, value, StaticBoundMethod::Get(name)))
            StaticBoundMethod::Set(name, value);
    }

    ValueRef AccessorMethod::Get(const char* name)
    {
        return this->UseGetter(name, StaticBoundMethod::Get(name));
    }
}
