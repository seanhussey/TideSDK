/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _WIN32_PIPE_H_
#define _WIN32_PIPE_H_

#include <tide/tide.h>
#include "../native_pipe.h"

namespace ti
{
    class Win32Pipe : public NativePipe
    {
    public:
        Win32Pipe(bool isReader);
        virtual void CreateHandles();
        virtual void Close();
        virtual void CloseNativeRead();
        virtual void CloseNativeWrite();
        void DuplicateWrite(HANDLE process, LPHANDLE handle);
        void DuplicateRead(HANDLE process, LPHANDLE handle);
        HANDLE GetReadHandle() { return readHandle; }
        HANDLE GetWriteHandle() { return writeHandle; }
        
    protected:
        virtual int RawRead(char *buffer, int size);
        virtual int RawWrite(const char *buffer, int size);
        
        Poco::Mutex mutex;
        HANDLE readHandle, writeHandle;
        Logger *logger;
    };
}

#endif
