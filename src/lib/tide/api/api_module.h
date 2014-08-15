/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _API_PLUGIN_H
#define _API_PLUGIN_H

#include <tide/tide.h>
#include "api_binding.h"

namespace tide
{
    class TIDE_API APIModule : public Module
    {
    public:
        APIModule(Host* host, const char* path) :
            Module(host, path, STRING(MODULE_NAME), STRING(MODULE_VERSION))
        {

        }

        ~APIModule()
        {

        }

        void Initialize();
        void Stop();

    protected:
        AutoPtr<APIBinding> binding;
    };
}
#endif
