/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/


#ifndef _ENVIRONMENT_UTILS_H_
#define _ENVIRONMENT_UTILS_H_
#include <string>
#include <tideutils/base.h>

namespace TideUtils
{
    namespace EnvironmentUtils
    {
        /*
         * @returns whether or not the named environment variable exists.
         */
        TIDE_UTILS_API bool Has(std::string name);

        /*
         * @returns the given environment variable or empty string if it does
         * not exist.
         */
        TIDE_UTILS_API std::string Get(std::string name);

        /*
         * Set an environment variable given a value and a name
         */
        TIDE_UTILS_API void Set(std::string name, std::string value);

        /*
         * Unset an environment variable given a name
         */
        TIDE_UTILS_API void Unset(std::string name);

        /*
         * Get the environment
         */
        TIDE_UTILS_API std::map<std::string, std::string> GetEnvironment();
    };
}

#endif
