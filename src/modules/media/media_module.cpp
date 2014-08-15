/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "media_module.h"
#include "media_binding.h"

#ifdef OS_LINUX
#include "gst/gst_media_binding.h"
#elif OS_WIN32
#include "win32/win32_media_binding.h"
#elif OS_OSX
#include "osx/osx_media_binding.h"
#endif

using namespace tide;
using namespace ti;

namespace ti
{
    TIDE_MODULE(MediaModule, STRING(MODULE_NAME), STRING(MODULE_VERSION));

    void MediaModule::Initialize()
    {
#ifdef OS_LINUX
        this->binding = new GstMediaBinding(host->GetGlobalObject());
#elif OS_WIN32
        this->binding = new Win32MediaBinding(host->GetGlobalObject());
#elif OS_OSX
        this->binding = new OSXMediaBinding(host->GetGlobalObject());
#endif
        ValueRef value = Value::NewObject(this->binding);
        host->GetGlobalObject()->Set("Media", value);
    }

    void MediaModule::Stop()
    {
    }
}
