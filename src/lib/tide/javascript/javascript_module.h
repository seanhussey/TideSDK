/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _JAVASCRIPT_MODULE_H
#define _JAVASCRIPT_MODULE_H

#include <JavaScriptCore/JSObjectRef.h>
#include <JavaScriptCore/JSStringRef.h>
#include <JavaScriptCore/JSContextRef.h>
#include <cstring>
#include <map>
#include <tide/tide.h>

/* KJS <-> TideSDK bindings */
namespace tide 
{
    class KKJSObject;
    class KKJSMethod;
    class KKJSList;
    class JavaScriptModule;
    class JavaScriptModuleInstance;
}

#include "js_object.h"
#include "js_method.h"
#include "js_list.h"
#include "js_util.h"
#include "javascript_module_instance.h"
#include "javascript_methods.h"

namespace tide
{
    class TIDE_API JavaScriptModule : public Module, public ModuleProvider
    {
    public:
        JavaScriptModule(Host* host, const char* path) :
            Module(host, path, STRING(MODULE_NAME), STRING(MODULE_VERSION))
        {

        }

        ~JavaScriptModule()
        {

        }

        void Initialize();
        void Stop();
        virtual bool IsModule(std::string& path);
        virtual Module* CreateModule(std::string& path);

        Host* GetHost()
        {
            return host;
        }

        static JavaScriptModule* Instance()
        {
            return instance;
        }


    private:
        static JavaScriptModule *instance;
    };
}

#endif
