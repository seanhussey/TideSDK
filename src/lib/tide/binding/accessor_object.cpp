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
    AccessorObject::AccessorObject(const char* name)
        : StaticBoundObject(name)
    {
    }

    bool AccessorObject::HasProperty(const char* name)
    {
        return StaticBoundObject::HasProperty(name) || this->HasGetterFor(name);
    }

    void AccessorObject::Set(const char* name, ValueRef value)
    {
        if (!this->UseSetter(name, value, StaticBoundObject::Get(name)))
            StaticBoundObject::Set(name, value);
    }

    ValueRef AccessorObject::Get(const char* name)
    {
        return this->UseGetter(name, StaticBoundObject::Get(name));
    }
}
