/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "win32_media_binding.h"

namespace ti
{
    Win32MediaBinding::Win32MediaBinding(TiObjectRef global) :
        MediaBinding(global)
    {
    }

    Win32MediaBinding::~Win32MediaBinding()
    {
    }

    void Win32MediaBinding::Beep()
    {
        MessageBeep(MB_OK);
    }

    TiObjectRef Win32MediaBinding::CreateSound(std::string& url)
    {
        return new Win32Sound(url);
    }
}
