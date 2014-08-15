/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include <tide/tide.h>
#include "worker_module.h"
#include "worker_binding.h"

using namespace tide;
using namespace ti;

TIDE_MODULE(WorkerModule, STRING(MODULE_NAME), STRING(MODULE_VERSION));

namespace ti
{
    void WorkerModule::Initialize()
    {
        GlobalObject::GetInstance()->SetObject("Worker", new WorkerBinding());
    }

    void WorkerModule::Stop()
    {
        GlobalObject::GetInstance()->SetNull("Worker");
    }
}
