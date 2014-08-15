/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include <tide/tide.h>
#include "filesystem_module.h"
#include "filesystem_binding.h"

using namespace tide;
using namespace ti;

namespace ti
{
    TIDE_MODULE(FilesystemModule, STRING(MODULE_NAME), STRING(MODULE_VERSION));

    void FilesystemModule::Initialize()
    {
        // load our variables
        this->binding= new FilesystemBinding(host,host->GetGlobalObject());

        // set our ti.Filesystem
        ValueRef value = Value::NewObject(this->binding);
        host->GetGlobalObject()->Set("Filesystem",value);
    }

    void FilesystemModule::Stop()
    {

    }
}
