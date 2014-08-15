/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _NETWORK_BINDING_H_
#define _NETWORK_BINDING_H_

#include <tide/tide.h>

namespace ti
{
    class NetworkBinding;
    class HostBinding;
}

namespace ti
{
    class NetworkBinding : public AccessorObject
    {
    public:
        NetworkBinding(Host*);
        virtual ~NetworkBinding();

        Host* GetHost();
        static const std::string& GetFirstIPAddress();

    private:
        Host* host;
        TiObjectRef global;

        AutoPtr<HostBinding> GetHostBinding(std::string host);

        void _GetFirstMACAddress(const ValueList& args, ValueRef result);
        void _GetFirstIPAddress(const ValueList& args, ValueRef result);
        void _GetInterfaces(const ValueList& args, ValueRef result);
        void _CreateIPAddress(const ValueList& args, ValueRef result);
        void _CreateTCPSocket(const ValueList& args, ValueRef result);
        void _CreateTCPServerSocket(const ValueList& args, ValueRef result);
        void _CreateIRCClient(const ValueList& args, ValueRef result);
        void _CreateHTTPClient(const ValueList& args, ValueRef result);
        void _CreateHTTPServer(const ValueList& args, ValueRef result);
        void _CreateHTTPCookie(const ValueList& args, ValueRef result);
        void _EncodeURIComponent(const ValueList &args, ValueRef result);
        void _DecodeURIComponent(const ValueList &args, ValueRef result);
        void _GetHostByName(const ValueList& args, ValueRef result);
        void _GetHostByAddress(const ValueList& args, ValueRef result);
        void _SetHTTPProxy(const ValueList& args, ValueRef result);
        void _SetHTTPSProxy(const ValueList& args, ValueRef result);
        void _GetHTTPProxy(const ValueList& args, ValueRef result);
        void _GetHTTPSProxy(const ValueList& args, ValueRef result);
    };
}

#endif
