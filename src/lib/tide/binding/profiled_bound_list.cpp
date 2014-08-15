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
    ProfiledBoundList::ProfiledBoundList(TiListRef delegate) :
        ProfiledBoundObject(delegate),
        list(delegate),
        count(1)
    {
    }

    ProfiledBoundList::~ProfiledBoundList()
    {
    }

    void ProfiledBoundList::Append(ValueRef value)
    {
        list->Append(value);
    }

    unsigned int ProfiledBoundList::Size()
    {
        return list->Size();
    }

    ValueRef ProfiledBoundList::At(unsigned int index)
    {
        return list->At(index);
    }

    void ProfiledBoundList::SetAt(unsigned int index, ValueRef value)
    {
        list->SetAt(index,value);
    }

    bool ProfiledBoundList::Remove(unsigned int index)
    {
        return list->Remove(index);
    }

    void ProfiledBoundList::Set(const char *name, ValueRef value)
    {
        list->Set(name, value);
    }

    ValueRef ProfiledBoundList::Get(const char *name)
    {
        return list->Get(name);
    }

    SharedStringList ProfiledBoundList::GetPropertyNames()
    {
        return list->GetPropertyNames();
    }

    bool ProfiledBoundList::HasProperty(const char* name)
    {
        return list->HasProperty(name);
    }
}
