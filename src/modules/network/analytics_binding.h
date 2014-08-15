/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _ANALYTICS_BINDING_H_
#define _ANALYTICS_BINDING_H_

#include <tide/tide.h>
#include <Poco/Thread.h>
#include <Poco/Runnable.h>
#include <Poco/Mutex.h>
#include <Poco/Condition.h>
#include <curl/curl.h>
#include <queue>

namespace ti
{
    class AnalyticsBinding : public EventObject, public Poco::Runnable
    {
    public:
        AnalyticsBinding();
        ~AnalyticsBinding();
        void Shutdown();

    private:
        bool running;
        std::string url;
        std::string baseData;
        CURL* curlHandle;
        Poco::Thread thread;
        std::queue<std::string> events;
        Poco::Mutex eventsLock;
        TiMethodRef startCallback;

        void run();
        void SendEventToAPIServer(std::string& eventData);
        void _SendEvent(const ValueList& args, ValueRef result);
        void _StartAnalyticsThread(const ValueList &args, ValueRef result);
    };
}

#endif
