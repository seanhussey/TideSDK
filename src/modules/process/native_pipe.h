/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _NATIVE_PIPE_H_
#define _NATIVE_PIPE_H_

#include "pipe.h"
#include <tide/tide.h>
#include <Poco/Thread.h>
#include <Poco/RunnableAdapter.h>

namespace ti
{
    class NativePipe : public Pipe
    {
    public:
        NativePipe(bool isReader);
        ~NativePipe();
        void StartMonitor();
        void StartMonitor(TiMethodRef readCallback);
        virtual void StopMonitors();
        virtual int Write(BytesRef bytes);
        void PollForWriteIteration();
        virtual void Close();
        virtual void CloseNative();
        virtual void CloseNativeRead() = 0;
        virtual void CloseNativeWrite() = 0;
        inline void SetReadCallback(TiMethodRef cb) { this->readCallback = cb; }

    protected:
        bool closed;
        bool isReader;
        std::vector<TiObjectRef> attachedObjects;
        Poco::RunnableAdapter<NativePipe>* writeThreadAdapter;
        Poco::RunnableAdapter<NativePipe>* readThreadAdapter;
        Poco::Thread writeThread;
        Poco::Thread readThread;
        TiMethodRef readCallback;
        Logger* logger;
        Poco::Mutex buffersMutex;
        std::queue<BytesRef> buffers;

        void PollForReads();
        void PollForWrites();
        virtual void RawWrite(BytesRef bytes);
        virtual int RawRead(char *buffer, int size) = 0;
        virtual int RawWrite(const char *buffer, int size) = 0;
    };
}

#endif
