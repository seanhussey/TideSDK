/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _POSIX_PIPE_H_
#define _POSIX_PIPE_H_

#include <tide/tide.h>
#include "../native_pipe.h"

namespace ti
{
    class PosixPipe : public NativePipe
    {
    public:
        PosixPipe(bool isReader);
        virtual void CreateHandles();
        virtual void Close();
        virtual void CloseNativeRead();
        virtual void CloseNativeWrite();
        inline int GetReadHandle() { return readHandle; }
        inline int GetWriteHandle() { return writeHandle; }

    protected:
        int readHandle;
        int writeHandle;
        virtual int RawRead(char *buffer, int size);
        virtual int RawWrite(const char *buffer, int size);
    };
}

#endif
