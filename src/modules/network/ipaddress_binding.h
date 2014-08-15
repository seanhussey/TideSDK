/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _IPADDRESS_BINDING_H_
#define _IPADDRESS_BINDING_H_

#include <tide/tide.h>
#include <Poco/Net/IPAddress.h>
#include "Poco/Net/NetException.h"

using Poco::Net::IPAddress;
using Poco::Net::InvalidAddressException;

namespace ti
{
    class IPAddressBinding : public AccessorObject
    {
    public:
        IPAddressBinding(std::string);
        IPAddressBinding(IPAddress);
        virtual ~IPAddressBinding();
        const bool IsInvalid() const { return invalid; }
        const IPAddress* GetAddress() const { return address; }


    private:
        bool invalid;
        SharedPtr<IPAddress> address;
        void Init();
        void ToString(const ValueList& args, ValueRef result);
        void IsInvalid(const ValueList& args, ValueRef result);
        void IsIPV4(const ValueList& args, ValueRef result);
        void IsIPV6(const ValueList& args, ValueRef result);
        void IsWildcard(const ValueList& args, ValueRef result);
        void IsBroadcast(const ValueList& args, ValueRef result);
        void IsLoopback(const ValueList& args, ValueRef result);
        void IsMulticast(const ValueList& args, ValueRef result);
        void IsUnicast(const ValueList& args, ValueRef result);
        void IsLinkLocal(const ValueList& args, ValueRef result);
        void IsSiteLocal(const ValueList& args, ValueRef result);
        void IsWellKnownMC(const ValueList& args, ValueRef result);
        void IsNodeLocalMC(const ValueList& args, ValueRef result);
        void IsLinkLocalMC(const ValueList& args, ValueRef result);
        void IsSiteLocalMC(const ValueList& args, ValueRef result);
        void IsOrgLocalMC(const ValueList& args, ValueRef result);
        void IsGlobalMC(const ValueList& args, ValueRef result);
    };
}

#endif
