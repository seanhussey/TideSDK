/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _OSX_MEDIA_BINDING_H_
#define _OSX_MEDIA_BINDING_H_

#include <tide/tide.h>
#import <Cocoa/Cocoa.h>
#include "../sound.h"
#include "../media_binding.h"
#include "osx_sound.h"

using namespace tide;

namespace ti
{
    class OSXMediaBinding : public MediaBinding
    {
        public:
        OSXMediaBinding(TiObjectRef);
        ~OSXMediaBinding();

        protected:
        void Beep();
        TiObjectRef CreateSound(std::string&);
    };
}

#endif
