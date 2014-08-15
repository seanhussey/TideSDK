/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _JS_LIST_H_
#define _JS_LIST_H_

#include "javascript_module.h"

namespace tide
{
    class TIDE_API KKJSList : public TiList
    {

        public:
        KKJSList(JSContextRef context, JSObjectRef jsObject);
        ~KKJSList();

        virtual void Set(const char* name, ValueRef value);
        virtual void SetAt(unsigned int index, ValueRef value);
        virtual ValueRef Get(const char* name);
        virtual SharedStringList GetPropertyNames();
        virtual bool HasProperty(const char* name);
        virtual bool Equals(TiObjectRef);
        virtual void Append(ValueRef value);
        virtual unsigned int Size();
        virtual ValueRef At(unsigned int index);
        virtual bool Remove(unsigned int index);

        bool SameContextGroup(JSContextRef c);
        JSObjectRef GetJSObject();

        protected:
        JSGlobalContextRef context;
        JSObjectRef jsobject;
        AutoPtr<KKJSObject> tiObject;

        private:
        DISALLOW_EVIL_CONSTRUCTORS(KKJSList);
    };
}

#endif
