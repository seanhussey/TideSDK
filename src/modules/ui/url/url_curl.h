/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef URL_CURL_H_
#define URL_CURL_H_
#include <curl/curl.h>
extern struct Curl_local_handler CurlTiURLHandler;
extern struct Curl_local_handler CurlAppURLHandler;
namespace ti
{
    const char* TiURLToPathCurl(const char *url);
    const char* AppURLToPathCurl(const char *url);
}
#endif
