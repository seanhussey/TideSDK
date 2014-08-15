/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _HTTP_SERVER_REQUEST_H_
#define _HTTP_SERVER_REQUEST_H_

#include <tide/tide.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

namespace ti
{
    class HttpServerRequest : public StaticBoundObject
    {
    public:
        HttpServerRequest(Poco::Net::HTTPServerRequest& request);
        virtual ~HttpServerRequest();

    private:
        Poco::Net::HTTPServerRequest& request;

        void GetMethod(const ValueList& args, ValueRef result);
        void GetVersion(const ValueList& args, ValueRef result);
        void GetURI(const ValueList& args, ValueRef result);
        void GetContentType(const ValueList& args, ValueRef result);
        void GetContentLength(const ValueList& args, ValueRef result);
        void GetHeader(const ValueList& args, ValueRef result);
        void GetHeaders(const ValueList& args, ValueRef result);
        void HasHeader(const ValueList& args, ValueRef result);
        void Read(const ValueList& args, ValueRef result);
    };
}

#endif
