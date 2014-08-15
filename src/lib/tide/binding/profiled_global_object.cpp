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
#include <iostream>
#include <sstream>
#include <Poco/Stopwatch.h>
#include <Poco/ScopedLock.h>

namespace tide
{
    ProfiledGlobalObject::ProfiledGlobalObject(TiObjectRef global) :
        profiledObject(new ProfiledBoundObject(global))
    {
    }

    ProfiledGlobalObject::~ProfiledGlobalObject()
    {
    }

    void ProfiledGlobalObject::Set(const char* name, ValueRef value)
    {
        profiledObject->Set(name, value);
    }

    ValueRef ProfiledGlobalObject::Get(const char* name)
    {
        return profiledObject->Get(name);
    }

    SharedStringList ProfiledGlobalObject::GetPropertyNames()
    {
        return profiledObject->GetPropertyNames();
    }

    SharedString ProfiledGlobalObject::DisplayString(int levels)
    {
        return profiledObject->DisplayString(levels);
    }

    bool ProfiledGlobalObject::HasProperty(const char* name)
    {
        return profiledObject->HasProperty(name);
    }

    bool ProfiledGlobalObject::Equals(TiObjectRef other)
    {
        return profiledObject->Equals(other);
    }
}
