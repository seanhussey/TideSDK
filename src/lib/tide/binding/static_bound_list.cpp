/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "../tide.h"
#include <cmath>
#include <cstdio>
#include <cstring>

namespace tide
{
    StaticBoundList::StaticBoundList(const char *type) :
        TiList(type),
        object(new StaticBoundObject()),
        length(0)
    {
    }

    StaticBoundList::~StaticBoundList()
    {
    }

    void StaticBoundList::Append(ValueRef value)
    {
        std::string name = TiList::IntToChars(this->length);
        this->object->Set(name.c_str(), value);
        this->length++;
    }

    void StaticBoundList::SetAt(unsigned int index, ValueRef value)
    {
        std::string name = TiList::IntToChars(index);
        this->object->Set(name.c_str(), value);
        if (index >= this->length)
            this->length = index + 1;
    }

    bool StaticBoundList::Remove(unsigned int index)
    {
        if (index >= this->length)
            return false;

        std::string name = TiList::IntToChars(index);
        this->object->Unset(name.c_str());
        for (unsigned int i = index; i + 1 < this->length; i++)
            this->SetAt(i, this->At(i + 1));

        this->length--;
        return true;
    }

    unsigned int StaticBoundList::Size()
    {
        return this->length;
    }

    ValueRef StaticBoundList::At(unsigned int index)
    {
        std::string name = TiList::IntToChars(index);
        ValueRef value = this->object->Get(name.c_str());
        return value;
    }

    void StaticBoundList::Set(const char *name, ValueRef value)
    {
        int index = -1;
        if (TiList::IsInt(name) && (index = atoi(name)) >= 0)
        {
            this->SetAt(index, value);
        }
        else
        {
            this->object->Set(name, value);
        }
    }

    ValueRef StaticBoundList::Get(const char *name)
    {
        return this->object->Get(name);
    }

    SharedStringList StaticBoundList::GetPropertyNames()
    {
        return this->object->GetPropertyNames();
    }

    TiListRef StaticBoundList::FromStringVector(std::vector<std::string>& values)
    {
        TiListRef l = new StaticBoundList();
        std::vector<std::string>::iterator i = values.begin();
        while (i != values.end())
        {
            l->Append(Value::NewString(*i));
            i++;
        }
        return l;
    }
}
