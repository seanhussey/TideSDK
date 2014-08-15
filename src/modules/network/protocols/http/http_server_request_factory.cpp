/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "http_server_request.h"
#include "http_server_response.h"
#include "http_server_request_factory.h"

namespace ti
{
    class HTTPRequestHandler : public Poco::Net::HTTPRequestHandler {
        public:
            HTTPRequestHandler(TiMethodRef callback)
                : m_callback(callback)
            {
            }

            virtual void handleRequest(Poco::Net::HTTPServerRequest&, Poco::Net::HTTPServerResponse&);

        private:
            TiMethodRef m_callback;
    };

    void HTTPRequestHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) {
        // XXX(Josh): The request and response object's lifetime is limited to this functions call.
        // If the developer should keep a reference to these around past the callback lifetime and then
        // attempts to access it may result in a crash!
        ValueList args;
        args.push_back(Value::NewObject(new HttpServerRequest(request)));
        args.push_back(Value::NewObject(new HttpServerResponse(response)));
        RunOnMainThread(m_callback, args);
    }

    HttpServerRequestFactory::HttpServerRequestFactory(Host *host, TiMethodRef callback) :
        host(host),
        callback(callback)
    {
    }

    HttpServerRequestFactory::~HttpServerRequestFactory()
    {
    }

    Poco::Net::HTTPRequestHandler* HttpServerRequestFactory::createRequestHandler(
            const Poco::Net::HTTPServerRequest& request)
    {
        return new HTTPRequestHandler(callback);
    }
}
