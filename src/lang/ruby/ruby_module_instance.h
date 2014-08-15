/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _RUBY_MODULE_INSTANCE_H
#define _RUBY_MODULE_INSTANCE_H

#include "ruby_module.h"

namespace tide
{
    class RubyModuleInstance : public Module
    {
    public:
        RubyModuleInstance(Host *host, std::string path, std::string dir, std::string name);
    protected:
        virtual ~RubyModuleInstance();
    public:
        void Initialize ();
        void Destroy ();
    private:
        std::string path;
        DISALLOW_EVIL_CONSTRUCTORS(RubyModuleInstance);
    };
}

#endif
