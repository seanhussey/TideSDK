/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PHP_LIST_H_
#define _PHP_LIST_H_

#include "php_module.h"

namespace tide
{
    class KPHPList : public TiList
    {
        public:
        KPHPList(zval *list);
        virtual ~KPHPList();

        ValueRef Get(const char* name);
        void Set(const char* name, ValueRef value);
        virtual bool Equals(TiObjectRef);
        SharedStringList GetPropertyNames();

        unsigned int Size();
        void Append(ValueRef value);
        virtual void SetAt(unsigned int index, ValueRef value);
        bool Remove(unsigned int index);
        ValueRef At(unsigned int index);

        zval* ToPHP();

        protected:
        zval *list;

        static void AddTideValueToPHPArray(ValueRef value, zval *phpArray, const char* key);
        static void AddTideValueToPHPArray(ValueRef value, zval *phpArray, unsigned int index);
        static void AddTideValueToPHPArray(ValueRef value, zval *phpArray);
        DISALLOW_EVIL_CONSTRUCTORS(KPHPList);
    };
}

#endif
