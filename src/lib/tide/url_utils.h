/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _TIDE_URL_UTILS_H_
#define _TIDE_URL_UTILS_H_

#include <tide/base.h>

namespace TideUtils
{
    namespace URLUtils
    {
        /**
         * Normalize a URL. If this url is an app:// URL, ensure that it
         * has the app id as the hostname
         */
        TIDE_API std::string NormalizeURL(const std::string& url);

        /**
         * Convert a URL to a path if it is an app://, ti:// or file://
         * URL. If this URL cannot be converted to a path, return the original URL
         */
        TIDE_API std::string URLToPath(const std::string& url);

        /**
         * Path portion of URL which is guauranteed to be a local and * blank file.
         */
        TIDE_API std::string& BlankPageURL();

        TIDE_API std::string TiURLToPath(const std::string& url);
        TIDE_API std::string AppURLToPath(const std::string& url);
    };
}

#endif
