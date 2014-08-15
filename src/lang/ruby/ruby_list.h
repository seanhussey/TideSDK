/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _RUBY_LIST_H_
#define _RUBY_LIST_H_

#include "ruby_module.h"

namespace tide
{
    class KRubyList : public TiList
    {
    public:
        KRubyList(VALUE);
        virtual ~KRubyList();

        void Append(ValueRef value);
        unsigned int Size();
        ValueRef At(unsigned int index);
        void SetAt(unsigned int index, ValueRef value);
        bool Remove(unsigned int index);
        void Set(const char* name, ValueRef value);
        ValueRef Get(const char* name);
        SharedStringList GetPropertyNames();
        SharedString DisplayString(int);
        VALUE ToRuby();

    /*
     * Determine if the given Ruby object equals this one
     * by comparing these objects's identity e.g. equals?()
     *  @param other the object to test
     *  @returns true if objects have reference equality, false otherwise
     */
    virtual bool Equals(TiObjectRef);

    protected:
        VALUE list;
        AutoPtr<KRubyObject> object;
        DISALLOW_EVIL_CONSTRUCTORS(KRubyList);
    };
}

#endif
