/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/


#include <tideutils/posix/posix_utils.h>

namespace TideUtils
{
    std::wstring UTF8ToWide(const std::string& in)
    {
        // TODO: Eventually we want this function to convert to a non-UTF8
        // wide string, but do this for now, just so that on non-Win32 platforms
        // we can use the same code.
        std::wstring result(in.length(), L' ');
        std::copy(in.begin(), in.end(), result.begin());
        return result;
    }

    std::wstring UTF8ToWide(const char* in)
    {
        std::string inString(in);
        return UTF8ToWide(inString);
    }

    std::string WideToUTF8(const std::wstring& in)
    {
        // TODO: Eventually we want this function to convert from Unicode
        // characters to UTF-8 characters, but do this for now, just so
        // that on non-Win32 platforms we can use the same code.
        std::string result(in.length(), ' ');
        std::copy(in.begin(), in.end(), result.begin());
        return result;
    }

    std::string WideToUTF8(const wchar_t* in)
    {
        std::wstring inString(in);
        return WideToUTF8(inString);
    }

    TIDE_UTILS_API std::string UTF8ToSystem(const std::string& in)
    {
        // Assume the system character set is UTF-8 for now.
        return in;
    }

    TIDE_UTILS_API std::string UTF8ToSystem(const char* in)
    {
        // Assume the system character set is UTF-8 for now.
        return in;
    }
}
