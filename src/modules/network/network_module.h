/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef TI_NETWORK_MODULE_H_
#define TI_NETWORK_MODULE_H_

#include <tide/tide.h>
#include <curl/curl.h>
#include "network_binding.h"
#include "analytics_binding.h"

#if defined(OS_OSX) || defined(OS_LINUX)
#define EXPORT __attribute__((visibility("default")))
#define TIDESDK_NETWORK_API EXPORT
#elif defined(OS_WIN32)
#ifdef TIDESDK_NETWORK_API_EXPORT
#define TIDESDK_NETWORK_API __declspec(dllexport)
#else
#define TIDESDK_NETWORK_API __declspec(dllimport)
#endif
#define EXPORT __declspec(dllexport)
#endif


namespace ti 
{
    class TIDESDK_NETWORK_API NetworkModule : public tide::Module
    {
        TIDE_MODULE_CLASS(NetworkModule)

    public:
        static std::string& GetRootCertPath();
        static CURLSH* GetCurlShareHandle();

    private:
        AutoPtr<NetworkBinding> networkBinding;
        AutoPtr<AnalyticsBinding> analyticsBinding;
    };

}
#endif
