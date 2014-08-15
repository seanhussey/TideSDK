/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _INTERFACE_BINDING_H_
#define _INTERFACE_BINDING_H_

#include <tide/tide.h>
#include <Poco/Net/NetworkInterface.h>
#undef interface

namespace ti
{
    class InterfaceBinding : public AccessorObject
    {
    public:
        InterfaceBinding(Poco::Net::NetworkInterface&);
        virtual ~InterfaceBinding();

    private:
        Poco::Net::NetworkInterface interface;
        void _GetAddress(const ValueList& args, ValueRef result);
        void _GetIPAddress(const ValueList& args, ValueRef result);
        void _GetName(const ValueList& args, ValueRef result);
        void _GetDisplayName(const ValueList& args, ValueRef result);
        void _GetSubnetMask(const ValueList& args, ValueRef result);
        void _SupportsIPv4(const ValueList& args, ValueRef result);
        void _SupportsIPv6(const ValueList& args, ValueRef result);
    };
}

#endif
