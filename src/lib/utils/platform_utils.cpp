/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/


#include <tideutils/data_utils.h>
#include <tideutils/platform_utils.h>
#include <string.h>
#include <stdio.h>

namespace TideUtils
{
namespace PlatformUtils
{
    std::string GetFirstMACAddress()
    {
        MACAddress address;
        memset(&address, 0, sizeof(MACAddress));

        try
        {
            PlatformUtils::GetFirstMACAddressImpl(address);
        }
        catch(...)
        {
            // Just return zeros.
        }

        char result[18];
        sprintf(result, "%02x:%02x:%02x:%02x:%02x:%02x",
            address[0], address[1], address[2], address[3],
            address[4], address[5]);
        return std::string(result);
    }

    std::string GetMachineId()
    {
        static std::string machineID;
        if (machineID.empty())
        {
            machineID = DataUtils::HexMD5(GetFirstMACAddress());
        }
        return machineID;
    }
}
}
