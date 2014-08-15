/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "../ui_module.h"
#include "url_curl.h"
#include "url.h"
#include <cstring>

struct Curl_local_handler CurlTiURLHandler = { "ti", ti::TiURLToPathCurl };
struct Curl_local_handler CurlAppURLHandler = { "app", ti::AppURLToPathCurl };

namespace ti
{
    /* TODO: Every URL will leak in the curl handlers 
     * unless curl frees the result of these calls */
    const char* TiURLToPathCurl(const char *url)
    {
        string stURL = url;
        if (stURL.find("ti://") != 0)
        {
            stURL = string("ti://") + stURL;
        }

        std::string path = URLUtils::TiURLToPath(stURL);
        return strdup(path.c_str());
    }

    const char* AppURLToPathCurl(const char *url)
    {
        string stURL = url;
        if (stURL.find("app://") != 0)
        {
            stURL = string("app://") + stURL;
        }

        std::string path = URLUtils::AppURLToPath(stURL);
        return strdup(path.c_str());
    }
}
