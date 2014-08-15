/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include <tide/tide.h>
#include "monkey_module.h"
#include "monkey_binding.h"

using namespace tide;
using namespace ti;

namespace ti
{
    TIDE_MODULE(MonkeyModule, STRING(MODULE_NAME), STRING(MODULE_VERSION));
    
    void MonkeyModule::Initialize()
    {
        // load our variables
        this->binding = new MonkeyBinding(host,host->GetGlobalObject());

        // set our ti.Monkey
        ValueRef value = Value::NewObject(this->binding);
        host->GetGlobalObject()->Set("Monkey", value);
    }

    void MonkeyModule::Stop()
    {
    }
}
