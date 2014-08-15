/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "osx_media_binding.h"

namespace ti
{
    OSXMediaBinding::OSXMediaBinding(TiObjectRef global) : MediaBinding(global)
    {
    }
    OSXMediaBinding::~OSXMediaBinding()
    {
    }
    void OSXMediaBinding::Beep()
    {
        NSBeep();
    }
    TiObjectRef OSXMediaBinding::CreateSound(std::string& url)
    {
        return new OSXSound(url);
    }
}
