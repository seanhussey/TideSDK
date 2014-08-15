/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _RUBY_MODULE_H
#define _RUBY_MODULE_H

#if defined(OS_OSX) || defined(OS_LINUX)
#define EXPORT __attribute__((visibility("default")))
#define TIDESDK_RUBY_API EXPORT
#elif defined(OS_WIN32)
# ifdef TIDESDK_RUBY_API_EXPORT
#  define TIDESDK_RUBY_API __declspec(dllexport)
# else
#  define TIDESDK_RUBY_API __declspec(dllimport)
# endif
#endif

#ifdef RUBY_METHOD_FUNC
#  define VALUEFUNC(f) RUBY_METHOD_FUNC(f)
#  define VOIDFUNC(f) ((RUBY_DATA_FUNC) f)
#else
#  if defined(OS_WIN32)
#    define VALUEFUNC(f) ((VALUE (*) (...))f)
#    define VOIDFUNC(f) ((void (*)(void *))f)
#  else
#    define VALUEFUNC(f) ((VALUE (*)(...))f)
#    define VOIDFUNC(f) ((void (*)(...))f)
#  endif
#endif

#include <tide/tide.h>

#ifdef OS_WIN32
#include <windows.h>
#include <Winsock2.h>
#endif

#include <string>
#include <vector>
#include <ruby.h>

#ifndef RARRAY_LEN
#  define RARRAY_LEN(x) (RARRAY(x)->len)
#endif

#undef sleep
#undef close
#undef shutdown

#include "ruby_object.h"
#include "ruby_hash.h"
#include "ruby_method.h"
#include "ruby_list.h"
#include "ruby_utils.h"
#include "ruby_evaluator.h"
#include "ruby_module_instance.h"

namespace tide
{
    class TIDESDK_RUBY_API RubyModule : public Module, public ModuleProvider
    {
    public:
        RubyModule(Host* host, const char* path) :
            Module(host, path, STRING(MODULE_NAME), STRING(MODULE_VERSION))
        {
        }

        ~RubyModule()
        {
        }
        void Initialize();
        void Stop();

        virtual bool IsModule(std::string& path);
        virtual Module* CreateModule(std::string& path);
        void InitializeBinding();

        Host* GetHost()
        {
            return host;
        }
        static RubyModule* Instance()
        {
            return instance_;
        }

    private:
        TiObjectRef binding;
        static RubyModule *instance_;
        DISALLOW_EVIL_CONSTRUCTORS(RubyModule);
    };
}

#endif
