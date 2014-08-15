/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _MEDIA_WIN32_H_
#define _MEDIA_WIN32_H_

#include <tide/tide.h>
#include <windows.h>
#include "../sound.h"
#include "../media_binding.h"
#include "win32_sound.h"

using namespace tide;

namespace ti
{
    class Win32MediaBinding : public MediaBinding
    {
        public:
        Win32MediaBinding(TiObjectRef);
        ~Win32MediaBinding();

        protected:
        void Beep();
        TiObjectRef CreateSound(std::string&);
    };
}

#endif
