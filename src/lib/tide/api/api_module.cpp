/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include <string.h>
#include <iostream>
#include <vector>
#include "api_module.h"

namespace tide
{
    void APIModule::Initialize()
    {
        binding = new APIBinding(host);
        host->GetGlobalObject()->SetObject("API", binding);
    }

    void APIModule::Stop()
    {
        host->GetGlobalObject()->Set("API", Value::Undefined);
    }

}
