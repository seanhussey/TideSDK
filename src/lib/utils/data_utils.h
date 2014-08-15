/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/


#ifndef _DATA_UTILS_H_
#define _DATA_UTILS_H_
#include <tideutils/base.h>
namespace TideUtils
{
    namespace DataUtils
    {
        /*
         * @returns the hexidecimal MD5 hash of a string
         */
        TIDE_UTILS_API std::string HexMD5(std::string);

        /**
         * Generate a new UUID
         * @returns a new UUID as a string
         */
        TIDE_UTILS_API std::string GenerateUUID();
    }
}
#endif
