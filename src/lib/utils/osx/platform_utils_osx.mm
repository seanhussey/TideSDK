/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/


#include <tideutils/platform_utils.h>
#include <tideutils/osx/osx_utils.h>

#include <Foundation/Foundation.h>
#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/network/IOEthernetInterface.h>
#include <IOKit/network/IONetworkInterface.h>
#include <IOKit/network/IOEthernetController.h>

namespace TideUtils
{
    void PlatformUtils::GetFirstMACAddressImpl(MACAddress& address)
    {
        CFMutableDictionaryRef matcher = IOServiceMatching(kIOEthernetInterfaceClass);
        if (!matcher)
            return;

        // Create a dictionary to match only the primary network interface.
        CFRef<CFMutableDictionaryRef> propertyMatcher(
            CFDictionaryCreateMutable(kCFAllocatorDefault, 0,
            &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks));
        if (!propertyMatcher.get())
            return;
        CFDictionarySetValue(matcher, CFSTR(kIOPropertyMatchKey), propertyMatcher);

        io_iterator_t serviceIterator;
        if (IOServiceGetMatchingServices(kIOMasterPortDefault, matcher, &serviceIterator) != KERN_SUCCESS)
            return;

        // Grab the first result, which should be the primary interface.
        io_object_t service = IOIteratorNext(serviceIterator);
        if (!service)
            return;

        // Grab the parent of the first result, which should be the actual IONetworkController.
        io_object_t controller;
        if (IORegistryEntryGetParentEntry(service, kIOServicePlane, &controller) != KERN_SUCCESS)
            return;

        CFDataRef addressData = (CFDataRef) IORegistryEntryCreateCFProperty(
            controller, CFSTR(kIOMACAddress), kCFAllocatorDefault, 0);
        if (!addressData)
        {
            IOObjectRelease(controller);
            IOObjectRelease(service);
            return;
        }

        UInt8 addressInts[kIOEthernetAddressSize];
        bzero(addressInts, sizeof(addressInts));

        CFDataGetBytes(addressData, CFRangeMake(0, MAC_ADDRESS_SIZE), addressInts);
        CFRelease(addressData);

        for (size_t i = 0; i < kIOEthernetAddressSize && i < MAC_ADDRESS_SIZE; i++)
            address[i] = addressInts[i];

        IOObjectRelease(controller);
        IOObjectRelease(service);
    }

    std::string PlatformUtils::GetUsername()
    {
        return std::string([NSUserName() UTF8String]);
    }

    int PlatformUtils::GetProcessorCount()
    {
        if (![NSProcessInfo instancesRespondToSelector:@selector(processorCount)])
            return 1; // Shucks!
    
        return [[NSProcessInfo processInfo] processorCount];
    }
}
