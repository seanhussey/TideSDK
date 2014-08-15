/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/


#ifndef _WIN32_UTILS_H_
#define _WIN32_UTILS_H_

#include <tideutils/base.h>
#include <windows.h>

namespace TideUtils
{
    namespace Win32Utils
    {
        /*
         * Easily get the result of a FormatMessage
         * @param errorCode the error code to get the message for
         * @returns a normal, all-American std::string for once
         */
        TIDE_UTILS_API std::string QuickFormatMessage(
            DWORD errorCode,
            DWORD flags=FORMAT_MESSAGE_FROM_SYSTEM |
                FORMAT_MESSAGE_ALLOCATE_BUFFER |
                FORMAT_MESSAGE_IGNORE_INSERTS);
    };

    namespace FileUtils
    {
        TIDE_UTILS_API void CopyRecursive(const std::string &dir,
            const std::string &dest, const std::string& exclude = "");

        /* Some wchar versions of popular FileUtils functions */
        TIDE_UTILS_API bool IsFile(const std::wstring& path);
        TIDE_UTILS_API std::string ReadFile(const std::wstring& path);

        /**
         * Delete the file at the given path
         */
        TIDE_UTILS_API bool DeleteFile(const std::string &path);
    }

    TIDE_UTILS_API std::wstring UTF8ToWide(const std::string& in);
    TIDE_UTILS_API std::wstring UTF8ToWide(const char* in);
    TIDE_UTILS_API std::string WideToUTF8(const std::wstring& in);
    TIDE_UTILS_API std::string WideToUTF8(const wchar_t* in);
    TIDE_UTILS_API std::string UTF8ToSystem(const std::string& in);
    TIDE_UTILS_API std::string UTF8ToSystem(const char* in);
    TIDE_UTILS_API std::string WideToSystem(const std::wstring& in);
    TIDE_UTILS_API std::string WideToSystem(const wchar_t* in);

    TIDE_UTILS_API std::wstring MultiByteToWide(const std::string& in, UINT codePage);
    TIDE_UTILS_API std::wstring MultiByteToWide(const char* in, size_t length, UINT codePage);
    TIDE_UTILS_API std::string WideToMultiByte(const std::wstring& in, UINT codePage);
    TIDE_UTILS_API std::string WideToMultiByte(const wchar_t* in, size_t length, UINT codePage);
    TIDE_UTILS_API std::string MultiByteToMultiByte(const std::string& in, UINT codePageIn,
        UINT codePageOut);
}
#endif
