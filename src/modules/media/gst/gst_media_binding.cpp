/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include <tide/url_utils.h>
#include <tideutils/url_utils.h>

#include "gst_media_binding.h"
#include <gdk/gdk.h>

namespace ti
{
    GstMediaBinding::GstMediaBinding(TiObjectRef global) : MediaBinding(global)
    {
        char **argv;
        int argc = 0;
        gst_init(&argc, &argv);
    }

    GstMediaBinding::~GstMediaBinding()
    {
    }

    void GstMediaBinding::Beep()
    {
        gdk_beep();
    }

    TiObjectRef GstMediaBinding::CreateSound(std::string& url)
    {
        //This is a path so, turn it into a file:// URL
        std::string myurl = url;
        std::string path = URLUtils::URLToPath(url);
        if (path.find("://") == std::string::npos)
        {
            myurl = URLUtils::PathToFileURL(path);
        }
        return new GstSound(myurl);
    }
}
