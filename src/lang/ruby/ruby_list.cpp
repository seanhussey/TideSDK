/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "ruby_module.h"
#include <cstring>

namespace tide
{
    KRubyList::KRubyList(VALUE list) :
        TiList("Ruby.KRubyList"),
        list(list),
        object(new KRubyObject(list))
    {
        rb_gc_register_address(&list);
    }

    KRubyList::~KRubyList()
    {
        rb_gc_unregister_address(&list);
    }

    void KRubyList::Append(ValueRef value)
    {
        rb_ary_push(list, RubyUtils::ToRubyValue(value));
    }

    unsigned int KRubyList::Size()
    {
        return (unsigned int) RARRAY_LEN(list);
    }

    bool KRubyList::Remove(unsigned int index)
    {
        return (rb_ary_delete_at(list, index) != Qnil);
    }

    ValueRef KRubyList::At(unsigned int index)
    {
        if (index >= 0 && index < this->Size())
        {
            return RubyUtils::ToTiValue(rb_ary_entry(list, index));
        }
        else
        {
            return Value::Undefined;
        }
    }

    void KRubyList::Set(const char* name, ValueRef value)
    {
        if (TiList::IsInt(name))
        {
            this->SetAt(TiList::ToIndex(name), value);
        }
        else
        {
            this->object->Set(name, value);
        }
    }

    void KRubyList::SetAt(unsigned int index, ValueRef value)
    {
        VALUE rv = RubyUtils::ToRubyValue(value);

        // rb_ary_store will take care of sizing the list
        // appropriately in the case that index > current list size
        rb_ary_store(list, index, rv);
    }

    ValueRef KRubyList::Get(const char* name)
    {
        if (TiList::IsInt(name))
        {
            return this->At(TiList::ToIndex(name));
        }
        else
        {
            return object->Get(name);
        }
    }

    SharedStringList KRubyList::GetPropertyNames()
    {
        SharedStringList property_names = object->GetPropertyNames();
        for (size_t i = 0; i < this->Size(); i++)
        {
            std::string name = TiList::IntToChars(i);
            property_names->push_back(new std::string(name));
        }

        return property_names;
    }

    VALUE KRubyList::ToRuby()
    {
        return this->object->ToRuby();
    }

    SharedString KRubyList::DisplayString(int levels)
    {
        return this->object->DisplayString(levels);
    }

    bool KRubyList::Equals(TiObjectRef other)
    {
        AutoPtr<KRubyList> listOther = other.cast<KRubyList>();
        if (listOther.isNull())
            return false;
        return listOther->ToRuby() == this->ToRuby();
    }
}
