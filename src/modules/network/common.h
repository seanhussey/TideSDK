/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _CURL_COMMON_Hj
#define _CURL_COMMON_Hj

#include <tide/net/proxy_config.h>

#define SET_CURL_OPTION(handle, option, value) \
    {\
        CURLcode result = curl_easy_setopt(handle, option, value); \
        if (CURLE_OK != result) \
        { \
            GetLogger()->Error("Failed to set cURL handle option ("#option"): %s", \
                curl_easy_strerror(result)); \
        } \
    }

void SetCurlProxySettings(CURL* curlHandle, SharedProxy proxy);
void SetStandardCurlHandleOptions(CURL* handle);
BytesRef ObjectToBytes(TiObjectRef dataObject);

#endif
