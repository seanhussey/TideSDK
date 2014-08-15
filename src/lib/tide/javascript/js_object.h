/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _JS_OBJECT_H_
#define _JS_OBJECT_H_

#include "javascript_module.h"

#include <vector>
#include <string>
#include <map>

namespace tide
{
    class TIDE_API KKJSObject : public TiObject
    {
        public:
        KKJSObject(JSContextRef context, JSObjectRef js_object);
        ~KKJSObject();

        virtual void Set(const char *name, ValueRef value);
        virtual ValueRef Get(const char *name);
        virtual SharedStringList GetPropertyNames();
        virtual bool HasProperty(const char* name);
        virtual bool Equals(TiObjectRef);

        bool SameContextGroup(JSContextRef c);
        JSObjectRef GetJSObject();

        protected:
        JSGlobalContextRef context;
        JSObjectRef jsobject;

        private:
        DISALLOW_EVIL_CONSTRUCTORS(KKJSObject);
    };
}

#endif
