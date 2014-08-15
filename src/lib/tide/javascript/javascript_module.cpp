/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include <iostream>
#include <signal.h>
#include "javascript_module.h"
#include <Poco/Path.h>

namespace tide
{
    JavaScriptModule* JavaScriptModule::instance = NULL;
    void JavaScriptModule::Initialize()
    {
        JavaScriptModule::instance = this;
        host->AddModuleProvider(this);
        
        TiObjectRef global(Host::GetInstance()->GetGlobalObject());
        JavaScriptMethods::Bind(global);
    }

    void JavaScriptModule::Stop()
    {
        JavaScriptModule::instance = NULL;
    }

    const static std::string jsSuffix = "module.js";
    bool JavaScriptModule::IsModule(std::string& path)
    {
        int plength = path.length();
        int slength = jsSuffix.length();
        if (path.length() > jsSuffix.length())
        {
            return (path.substr(plength - slength) == jsSuffix);
        }
        else
        {
            return false;
        }
    }

    Module* JavaScriptModule::CreateModule(std::string& path)
    {
        Poco::Path p(path);
        std::string basename = p.getBaseName();
        std::string name = basename.substr(0,basename.length()-jsSuffix.length()+3);
        std::string moduledir = path.substr(0,path.length()-basename.length()-3);

        Logger *logger = Logger::Get("JavaScript");
        logger->Info("Loading JS path=%s", path.c_str());

        JavaScriptModuleInstance* instance = new JavaScriptModuleInstance(this->host, path, moduledir, name);
        return instance;
    }
}
