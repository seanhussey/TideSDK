/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _WIN32_PROCESS_H_
#define _WIN32_PROCESS_H_

#include <sstream>
#include "win32_pipe.h"
#include "../process.h"

namespace ti
{
    class Win32Process : public Process
    {
    public:
        Win32Process();
        virtual ~Win32Process();

        inline virtual AutoPtr<NativePipe> GetNativeStdin() { return nativeIn; }
        inline virtual AutoPtr<NativePipe> GetNativeStdout() { return nativeOut; }
        inline virtual AutoPtr<NativePipe> GetNativeStderr() { return nativeErr; }

        virtual int GetPID();
        virtual void Terminate();
        virtual void Kill();
        virtual void SendSignal(int signal);
        virtual void ForkAndExec();
        virtual void MonitorAsync();
        virtual BytesRef MonitorSync();
        virtual int Wait();
        virtual std::string ArgumentsToString();
        void ReadCallback(const ValueList& args, ValueRef result);
        virtual void RecreateNativePipes();
        
    protected:
        std::string ArgListToString(TiListRef argList);
        
        Poco::Thread exitMonitorThread;
        Poco::RunnableAdapter<Win32Process>* exitMonitorAdapter;
        AutoPtr<Win32Pipe> nativeIn, nativeOut, nativeErr;
        Poco::Mutex mutex;
        
        Poco::Mutex processOutputMutex;
        std::vector<BytesRef> processOutput;
        
        int pid;
        HANDLE process;
        
        Logger* logger;
    };
}

#endif
