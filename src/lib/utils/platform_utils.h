/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/


#ifndef _PLATFORM_UTILS_H_
#define _PLATFORM_UTILS_H_

#include <tideutils/base.h>
#include "poco/KTypes.h"
#define MAC_ADDRESS_SIZE 6

namespace TideUtils
{
    typedef KPoco::KUInt8 MACAddress[MAC_ADDRESS_SIZE]; /// Ethernet address.

    namespace PlatformUtils
    {
        /*
         * Get the first MAC address of this computer
         * @returns the first MAC address in standard dotted format
         */
        TIDE_UTILS_API std::string GetFirstMACAddress();

        /*
         * Get the first MAC address of this computer
         * @returns the first MAC address in standard dotted format
         */
        TIDE_UTILS_API void GetFirstMACAddressImpl(MACAddress&);

        /**
         * Generate an ID for this machine based on it's MAC Address.
         */
        TIDE_UTILS_API std::string GetMachineId();

        /**
         * Get the username of the current user.
         */
        TIDE_UTILS_API std::string GetUsername();

        /**
         * Get the number of processors on this machine.
         */
        TIDE_UTILS_API int GetProcessorCount();
    };
}
#endif
