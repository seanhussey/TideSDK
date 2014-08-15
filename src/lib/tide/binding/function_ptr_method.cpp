/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "../tide.h"

namespace tide
{
    FunctionPtrMethod::FunctionPtrMethod(KFunctionPtrCallback callback) :
        callback(callback)
    {
        this->object = new StaticBoundObject();
    }

    FunctionPtrMethod::~FunctionPtrMethod()
    {
    }

    ValueRef FunctionPtrMethod::Call(const ValueList& args)
    {
        return this->callback(args);
    }

    void FunctionPtrMethod::Set(const char *name, ValueRef value)
    {
        this->object->Set(name, value);
    }

    ValueRef FunctionPtrMethod::Get(const char *name)
    {
        return this->object->Get(name);
    }

    SharedStringList FunctionPtrMethod::GetPropertyNames()
    {
        return this->object->GetPropertyNames();
    }
}
