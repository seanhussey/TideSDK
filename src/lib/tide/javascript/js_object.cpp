/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "javascript_module.h"

namespace tide
{
    KKJSObject::KKJSObject(JSContextRef context, JSObjectRef jsobject) :
        TiObject("JavaScript.KKJSObject"),
        context(NULL),
        jsobject(jsobject)
    {
        /* KJS methods run in the global context that they originated from
        * this seems to prevent nasty crashes from trying to access invalid
        * contexts later. Global contexts need to be registered by all modules
        * that use a KJS context. */
        JSObjectRef globalObject = JSContextGetGlobalObject(context);
        JSGlobalContextRef globalContext = JSUtil::GetGlobalContext(globalObject);

        // This context hasn't been registered. Something has gone pretty
        // terribly wrong and TideSDK will likely crash soon. Nonetheless, keep
        // the user up-to-date to keep their hopes up.
        if (globalContext == NULL)
            std::cerr << "Could not locate global context for a KJS method."  <<
            " One of the modules is misbehaving." << std::endl;

        this->context = globalContext;

        JSUtil::ProtectGlobalContext(this->context);
        JSValueProtect(this->context, this->jsobject);
    }

    KKJSObject::~KKJSObject()
    {
        JSValueUnprotect(this->context, this->jsobject);
        JSUtil::UnprotectGlobalContext(this->context);
    }

    JSObjectRef KKJSObject::GetJSObject()
    {
        return this->jsobject;
    }

    ValueRef KKJSObject::Get(const char *name)
    {
        JSStringRef jsName = JSStringCreateWithUTF8CString(name);
        JSValueRef exception = NULL;
        JSValueRef jsValue = JSObjectGetProperty(this->context, this->jsobject, jsName, NULL);
        JSStringRelease(jsName);

        if (exception != NULL) //exception thrown
        {
            ValueRef tv_exp = JSUtil::ToTiValue(exception, this->context, NULL);
            throw ValueException(tv_exp);
        }

        ValueRef kvalue = JSUtil::ToTiValue(jsValue, this->context, this->jsobject);
        return kvalue;
    }

    void KKJSObject::Set(const char *name, ValueRef value)
    {
        JSValueRef jsValue = JSUtil::ToJSValue(value, this->context);
        JSStringRef jsName = JSStringCreateWithUTF8CString(name);

        JSValueRef exception = NULL;
        JSObjectSetProperty(this->context, this->jsobject, jsName, jsValue,
            0, &exception);
        JSStringRelease(jsName);

        if (exception != NULL) // An exception was thrown.
        {
            ValueRef exceptionValue = JSUtil::ToTiValue(exception, this->context, NULL);
            throw ValueException(exceptionValue);
        }
    }

    bool KKJSObject::Equals(TiObjectRef other)
    {
        AutoPtr<KKJSObject> kjsOther = other.cast<KKJSObject>();
        if (kjsOther.isNull())
            return false;

        if (!kjsOther->SameContextGroup(this->context))
            return false;

        return JSValueIsStrictEqual(
            this->context, this->jsobject, kjsOther->GetJSObject());
    }

    SharedStringList KKJSObject::GetPropertyNames()
    {
        SharedStringList list(new StringList());

        JSPropertyNameArrayRef names =
            JSObjectCopyPropertyNames(this->context, this->jsobject);
        JSPropertyNameArrayRetain(names);

        size_t count = JSPropertyNameArrayGetCount(names);
        for (size_t i = 0; i < count; i++)
        {
            JSStringRef jsName = JSPropertyNameArrayGetNameAtIndex(names, i);
            list->push_back(new std::string(JSUtil::ToChars(jsName)));
        }

        JSPropertyNameArrayRelease(names);
        return list;
    }

    bool KKJSObject::HasProperty(const char* name)
    {
        JSStringRef jsName = JSStringCreateWithUTF8CString(name);
        bool hasProperty = JSObjectHasProperty(context, jsobject, jsName);
        JSStringRelease(jsName);
        return hasProperty;
    }

    bool KKJSObject::SameContextGroup(JSContextRef contextIn)
    {
        return JSContextGetGroup(this->context) == JSContextGetGroup(contextIn);
    }
}
