/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PYTHON_MODULE_INSTANCE_H
#define _PYTHON_MODULE_INSTANCE_H

#include "python_module.h"

namespace tide
{
    class PythonModuleInstance : public Module
    {
    public:
        PythonModuleInstance(Host *host, std::string path, std::string dir, std::string name);
    protected:
        virtual ~PythonModuleInstance();
    public:
        void Initialize ();
        void Destroy ();
    private:
        std::string path;
        DISALLOW_EVIL_CONSTRUCTORS(PythonModuleInstance);
    };
}

#endif
