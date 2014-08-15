/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _HOST_BINDING_H_
#define _HOST_BINDING_H_

#include <tide/tide.h>
#include "Poco/Net/DNS.h"
#include "Poco/Net/HostEntry.h"
#include "Poco/Net/NetException.h"
#include "ipaddress_binding.h"

using Poco::Net::DNS;
using Poco::Net::IPAddress;
using Poco::Net::HostEntry;
using Poco::Net::InvalidAddressException;
using Poco::Net::HostNotFoundException;
using Poco::Net::ServiceNotFoundException;
using Poco::Net::NoAddressFoundException;

namespace ti
{
    class HostBinding : public StaticBoundObject
    {
    public:
        HostBinding(IPAddress);
        HostBinding(std::string);
        virtual ~HostBinding();
    protected:
        void Init();
    private:
        HostEntry host;
        std::string name;
        bool invalid;
        
    public:
        const bool IsInvalid() const { return invalid; }

    private:
        void ToString(const ValueList& args, ValueRef result);
        void IsInvalid(const ValueList& args, ValueRef result);
        void GetName(const ValueList& args, ValueRef result);
        void GetAliases(const ValueList& args, ValueRef result);
        void GetAddresses(const ValueList& args, ValueRef result);
    };
}

#endif
