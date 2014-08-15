/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _HTTP_SERVER_RESPONSE_H_
#define _HTTP_SERVER_RESPONSE_H_

#include <tide/tide.h>
#include <Poco/Net/HTTPServerResponse.h>

namespace ti
{
    class HttpServerResponse : public StaticBoundObject
    {
    public:
        HttpServerResponse(Poco::Net::HTTPServerResponse &response);
        virtual ~HttpServerResponse();
        
    private:
        Poco::Net::HTTPServerResponse& response;

        void SetStatus(const ValueList& args, ValueRef result);
        void SetReason(const ValueList& args, ValueRef result);
        void SetStatusAndReason(const ValueList& args, ValueRef result);
        void SetContentType(const ValueList& args, ValueRef result);
        void SetContentLength(const ValueList& args, ValueRef result);
        void AddCookie(const ValueList& args, ValueRef result);
        void SetHeader(const ValueList& args, ValueRef result);
        void Write(const ValueList& args, ValueRef result);

    };
}

#endif
