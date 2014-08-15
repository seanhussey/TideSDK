/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifdef OS_WIN32
#include <tideutils/win/win32_utils.h>
#else
#include <tideutils/posix/posix_utils.h>
#endif

#include <signal.h>
#include "ruby_module.h"
#include <Poco/Path.h>

extern "C" EXPORT RubyModule* CreateModule(Host *host, const char* path)
{
    return new RubyModule(host, path);
}

namespace tide
{
    RubyModule* RubyModule::instance_ = NULL;

    void RubyModule::Initialize()
    {
        RubyModule::instance_ = this;

        ruby_init();
        ruby_init_loadpath();

        // Add the application directoy to the Ruby include path so
        // that includes work in a intuitive way for application developers.
        ruby_incpush(UTF8ToSystem(host->GetApplication()->GetResourcesPath()).c_str());

        this->InitializeBinding();
        host->AddModuleProvider(this);
    }

    void RubyModule::Stop()
    {
        TiObjectRef global = this->host->GetGlobalObject();
        global->Set("Ruby", Value::Undefined);
        Script::GetInstance()->RemoveScriptEvaluator(this->binding);
        this->binding = NULL;
        RubyModule::instance_ = NULL;

        ruby_cleanup(0);
    }

    void RubyModule::InitializeBinding()
    {
        // Expose the Ruby evaluator into Tide
        TiObjectRef global = this->host->GetGlobalObject();
        this->binding = new RubyEvaluator();
        global->Set("Ruby", Value::NewObject(binding));
        Script::GetInstance()->AddScriptEvaluator(this->binding);
        
        // Bind the API global constant
        VALUE ruby_api_val = RubyUtils::TiObjectToRubyValue(Value::NewObject(global));
        rb_define_global_const(GLOBAL_NAMESPACE, ruby_api_val);
    }

    const static std::string ruby_suffix = "module.rb";
    bool RubyModule::IsModule(std::string& path)
    {
        return (path.substr(path.length()-ruby_suffix.length()) == ruby_suffix);
    }

    Module* RubyModule::CreateModule(std::string& path)
    {
        path = UTF8ToSystem(path);
        rb_load_file(path.c_str());
        ruby_exec();
        // TODO: Do we need to call ruby_cleanup() here?

        Poco::Path p(path);
        std::string basename = p.getBaseName();
        std::string name = basename.substr(0,basename.length()-ruby_suffix.length()+3);
        std::string moduledir = path.substr(0,path.length()-basename.length()-3);

        return new RubyModuleInstance(host, path, moduledir, name);
    }
}
