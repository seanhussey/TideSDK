/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _GST_MEDIA_BINDING_H_
#define _GST_MEDIA_BINDING_H_

#include <tide/tide.h>
#include <gst/gst.h>
#include "../sound.h"
#include "../media_binding.h"
#include "gst_sound.h"

using namespace tide;

namespace ti
{
    class GstMediaBinding : public MediaBinding
    {
        public:
        GstMediaBinding(TiObjectRef);
        ~GstMediaBinding();

        protected:
        void Beep();
        TiObjectRef CreateSound(std::string&);

    };
}

#endif
