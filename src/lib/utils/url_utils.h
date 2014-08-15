/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/


#ifndef _URL_UTILS_H_
#define _URL_UTILS_H_

#include <tideutils/base.h>

namespace TideUtils
{
    namespace URLUtils
    {
        /**
         * Encodes a URI value
         */
        TIDE_UTILS_API std::string EncodeURIComponent(std::string value);

        /**
         * Decodes a URI value
         */
        TIDE_UTILS_API std::string DecodeURIComponent(std::string value);

        /**
         * Convert a file URL to an absolute path
         */
        TIDE_UTILS_API std::string FileURLToPath(std::string url);

        /**
         * Convert an path to a file URL
         */
        TIDE_UTILS_API std::string PathToFileURL(std::string path);
    };
}

#endif
