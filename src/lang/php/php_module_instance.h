/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PHP_MODULE_INSTANCE_H_
#define _PHP_MODULE_INSTANCE_H_

#include "php_module.h"

namespace tide
{
    class PHPModuleInstance : public Module
    {
        public:
        PHPModuleInstance(Host *host, std::string path, std::string dir, std::string name);
        void Initialize();
        void Destroy();

        protected:
        virtual ~PHPModuleInstance();

        private:
        std::string path;
        DISALLOW_EVIL_CONSTRUCTORS(PHPModuleInstance);
    };
}

#endif
