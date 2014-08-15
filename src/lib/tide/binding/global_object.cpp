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
    AutoPtr<GlobalObject> GlobalObject::instance;

    GlobalObject::GlobalObject() :
        EventObject(PRODUCT_NAME)
    {
        // @tiapi(method=True,type=String,name=getVersion,since=0.8)
        // @tiapi Return the TideSDK runtime version.
        // @tiresult[String] The runtime version.
        this->SetMethod("getVersion", &GlobalObject::GetVersion);

        // @tiapi(method=True,type=String,name=getPlatform,since=0.8)
        // @tiapi Return the current platform, usually one of
        // @tiapi 'osx', 'win32', or 'linux'.
        // @tiresult[String] The current platform.
        this->SetMethod("getPlatform", &GlobalObject::GetPlatform);

        Event::SetEventConstants(this);
        Script::Initialize();
    }

    GlobalObject::~GlobalObject()
    {

    }

    void GlobalObject::GetVersion(const ValueList& args, ValueRef result)
    {
        result->SetString(PRODUCT_VERSION);
    }

    void GlobalObject::GetPlatform(const ValueList& args, ValueRef result)
    {
        result->SetString(OS_NAME);
    }

    /*static*/
    void GlobalObject::TurnOnProfiling()
    {
        instance = new ProfiledGlobalObject(instance);
    }
}
