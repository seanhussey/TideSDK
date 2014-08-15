/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _HTTP_SERVER_REQUEST_FACTORY_H_
#define _HTTP_SERVER_REQUEST_FACTORY_H_

#include <tide/tide.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPRequestHandler.h>

namespace ti
{
    class HttpServerRequestFactory : public Poco::Net::HTTPRequestHandlerFactory
    {
    public:
        HttpServerRequestFactory(Host *host, TiMethodRef callback);
        virtual ~HttpServerRequestFactory();
        
        Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest &request);
    private:
        Host *host;
        TiMethodRef callback;
    };
}

#endif
