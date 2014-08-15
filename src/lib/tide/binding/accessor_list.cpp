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
    AccessorList::AccessorList(const char* type)
        : StaticBoundList(type)
    {
    }

    bool AccessorList::HasProperty(const char* name)
    {
        return StaticBoundList::HasProperty(name) || this->HasGetterFor(name);
    }

    void AccessorList::Set(const char* name, ValueRef value)
    {
        if (!this->UseSetter(name, value, StaticBoundList::Get(name)))
            StaticBoundList::Set(name, value);
    }

    ValueRef AccessorList::Get(const char* name)
    {
        return this->UseGetter(name, StaticBoundList::Get(name));
    }
}
