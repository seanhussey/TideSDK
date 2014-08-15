/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "win32_pipe.h"

namespace ti
{
    Win32Pipe::Win32Pipe(bool isReader) :
        NativePipe(isReader),
        readHandle(INVALID_HANDLE_VALUE),
        writeHandle(INVALID_HANDLE_VALUE),
        logger(Logger::Get("Process.Win32Pipe"))
    {
    }

    void Win32Pipe::CreateHandles()
    {
        SECURITY_ATTRIBUTES attr;
        attr.nLength              = sizeof(attr);
        attr.lpSecurityDescriptor = NULL;
        attr.bInheritHandle       = FALSE;
        
        ::CreatePipe(&readHandle, &writeHandle, &attr, 0);
    }

    void Win32Pipe::Close()
    {
        NativePipe::Close();
    }

    int Win32Pipe::RawRead(char *buffer, int size)
    {
        if (readHandle != INVALID_HANDLE_VALUE)
        {
            DWORD bytesRead;
            BOOL ok = ReadFile(readHandle, buffer, size, &bytesRead, NULL);
            int error = GetLastError();
            if (ok)
            {
                return bytesRead;
            }
            else if (error == ERROR_BROKEN_PIPE)
            {
                return -1;
            }
            else
            {
                throw ValueException::FromString("Error writing anonymous pipe");
            }
        }
        return -1;
    }

    int Win32Pipe::RawWrite(const char *data, int size)
    {
        if (writeHandle != INVALID_HANDLE_VALUE)
        {
            DWORD bytesWritten;
            BOOL ok = WriteFile(writeHandle, (LPCVOID)data, size, &bytesWritten, NULL);
            if (ok || GetLastError() == ERROR_BROKEN_PIPE) {
                return bytesWritten;
            }
            else {
                throw ValueException::FromString("Error writing anonymous pipe");
            }
        }
        return 0;
    }

    void Win32Pipe::DuplicateRead(HANDLE process, LPHANDLE handle)
    {
        DuplicateHandle(process, readHandle, process, handle, 0, TRUE, DUPLICATE_SAME_ACCESS);
        this->CloseNativeRead();
    }

    void Win32Pipe::DuplicateWrite(HANDLE process, LPHANDLE handle)
    {
        DuplicateHandle(process, writeHandle, process, handle, 0, TRUE, DUPLICATE_SAME_ACCESS);
        this->CloseNativeWrite();
    }

    void Win32Pipe::CloseNativeRead()
    {
        if (readHandle != INVALID_HANDLE_VALUE)
        {
            CloseHandle(readHandle);
            readHandle = INVALID_HANDLE_VALUE;
        }
    }

    void Win32Pipe::CloseNativeWrite()
    {
        if (writeHandle != INVALID_HANDLE_VALUE)
        {
            CloseHandle(writeHandle);
            writeHandle = INVALID_HANDLE_VALUE;
        }
    }
}
