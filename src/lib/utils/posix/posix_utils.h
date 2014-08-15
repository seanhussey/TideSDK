/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/


#ifndef _POSIX_UTILS_H_
#define _POSIX_UTILS_H_

#include <tideutils/base.h>
#include <string>
namespace TideUtils
{
    TIDE_UTILS_API std::wstring UTF8ToWide(const std::string& in);
    TIDE_UTILS_API std::wstring UTF8ToWide(const char* in);
    TIDE_UTILS_API std::string WideToUTF8(const std::wstring& in);
    TIDE_UTILS_API std::string WideToUTF8(const wchar_t* in);
    TIDE_UTILS_API std::string UTF8ToSystem(const std::string& in);
    TIDE_UTILS_API std::string UTF8ToSystem(const char* in);
}
#endif
