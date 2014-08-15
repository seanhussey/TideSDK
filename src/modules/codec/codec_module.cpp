/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include <tide/tide.h>
#include "codec_module.h"
#include "codec_binding.h"

using namespace tide;
using namespace ti;

namespace ti
{
    TIDE_MODULE(CodecModule, STRING(MODULE_NAME), STRING(MODULE_VERSION));
    
    void CodecModule::Initialize()
    {
        // load our variables
        this->binding = new CodecBinding(host->GetGlobalObject());

        // set our ti.Codec
        ValueRef value = Value::NewObject(this->binding);
        host->GetGlobalObject()->Set("Codec", value);
    }

    void CodecModule::Stop()
    {
    }
}
