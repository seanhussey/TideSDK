/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _JS_METHOD_H_
#define _JS_METHOD_H_

#include "javascript_module.h"

#include <vector>
#include <string>
#include <map>

namespace tide
{
    class TIDE_API KKJSMethod : public TiMethod
    {
        public:
        KKJSMethod(JSContextRef, JSObjectRef, JSObjectRef);
        ~KKJSMethod();

        virtual void Set(const char *name, ValueRef value);
        virtual ValueRef Get(const char *name);
        ValueRef Call(JSObjectRef thisObject, const ValueList& args);
        virtual ValueRef Call(const ValueList& args);
        virtual ValueRef Call(TiObjectRef thisObject, const ValueList& args);
        virtual SharedStringList GetPropertyNames();
        virtual bool HasProperty(const char* name);
        virtual bool Equals(TiObjectRef);

        virtual bool SameContextGroup(JSContextRef c);
        JSObjectRef GetJSObject();

        protected:
        JSGlobalContextRef context;
        JSObjectRef jsobject;
        JSObjectRef thisObject;
        AutoPtr<KKJSObject> tiObject;

        private:
        DISALLOW_EVIL_CONSTRUCTORS(KKJSMethod);
    };
}

#endif
