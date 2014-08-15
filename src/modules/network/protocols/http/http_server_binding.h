/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _HTTP_SERVER_BINDING_H_
#define _HTTP_SERVER_BINDING_H_

#include <tide/tide.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>
#include <Poco/Thread.h>
#include <Poco/FileStream.h>

namespace ti
{
    class HTTPServerBinding : public StaticBoundObject
    {
    public:
        HTTPServerBinding(Host* host);
        virtual ~HTTPServerBinding();

    private:
        Host* host;
        TiObjectRef global;
        TiMethodRef callback;
        std::string ipaddress;
        int port;
        Poco::Thread *thread;
        Poco::Net::ServerSocket *socket;
        Poco::Net::HTTPServer *connection;
        
        static void Run(void*);
        
        void Bind(const ValueList& args, ValueRef result);
        void Close(const ValueList& args, ValueRef result);
        void IsClosed(const ValueList& args, ValueRef result);
        
        void Close();
        
    };
}

#endif
