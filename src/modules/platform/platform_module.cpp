/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include <tide/tide.h>
#include "platform_module.h"
#include "platform_binding.h"

using namespace tide;
using namespace ti;

namespace ti
{
    TIDE_MODULE(PlatformModule, STRING(MODULE_NAME), STRING(MODULE_VERSION));

    void PlatformModule::Initialize()
    {
        this->binding = new PlatformBinding();
        host->GetGlobalObject()->SetObject("Platform", this->binding);
        host->GetGlobalObject()->SetObject("Desktop", this->binding);
    }

    void PlatformModule::Start()
    {
        // Duplicate the network module address, macaddress and interfaces here for
        // backward compatibility. The network module should be initialized when
        // Start() is called.
        if (!GlobalObject::GetInstance()->GetObject("Network").isNull())
        {
            TiObjectRef network = GlobalObject::GetInstance()->GetObject("Network");
            this->binding->Set("getAddress", network->Get("getAddress"));
            this->binding->Set("getMACAddress", network->Get("getMACAddress"));
            this->binding->Set("getInterfaces", network->Get("getInterfaces"));
        }
    }

    void PlatformModule::Stop()
    {
        host->GetGlobalObject()->SetNull("Platform");
        host->GetGlobalObject()->SetNull("Desktop");
    }
    
}
