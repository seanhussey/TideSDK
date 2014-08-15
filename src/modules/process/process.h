/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <tide/tide.h>
#include <sstream>
#include "pipe.h"
#include "native_pipe.h"

namespace ti
{
    class Process;
    typedef AutoPtr<Process> AutoProcess;
    class Process : public EventMethod
    {
    public:
        Process();
        virtual ~Process();
        static AutoProcess CreateProcess();
        virtual TiObjectRef CloneEnvironment();
        virtual void LaunchAsync();
        virtual BytesRef LaunchSync();
        virtual void ExitMonitorAsync();
        virtual void ExitMonitorSync();
        std::string ArgumentsToString();
        void SetOnRead(TiMethodRef method);
        void SetOnExit(TiMethodRef onExit);
        void Exited(bool async);
        void ExitCallback(const ValueList& args, ValueRef result);
        virtual ValueRef Call(const ValueList& args);
        static TiObjectRef GetCurrentEnvironment();

        void SetStdin(AutoPipe stdinPipe);
        void SetStdout(AutoPipe stdoutPipe);
        void SetStderr(AutoPipe stderrPipe);
        inline bool IsRunning() { return running; }
        inline void SetPID(int pid) { this->pid = pid; }
        virtual inline void SetArguments(TiListRef args) { this->args = args; }
        inline void SetEnvironment(TiObjectRef env) { this->environment = env; }
        inline int GetPID() { return this->pid; }
        inline AutoPipe GetStdin() { return this->stdinPipe; }
        inline AutoPipe GetStdout() { return this->stdoutPipe; }
        inline AutoPipe GetStderr() { return this->stderrPipe; }
        inline TiListRef GetArgs() { return this->args; };
        inline TiObjectRef GetEnvironment() { return this->environment; }
        void SetEnvironment(const char *name, const char *value)
        {
            environment->SetString(name, value);
        }

        virtual void Terminate() = 0;
        virtual void Kill() = 0;
        virtual void SendSignal(int signal) = 0;
        virtual void ForkAndExec() = 0;
        virtual void MonitorAsync() = 0;
        virtual BytesRef MonitorSync() = 0;
        virtual int Wait() = 0;
        virtual void RecreateNativePipes() = 0;
        virtual AutoPtr<NativePipe> GetNativeStdin() = 0;
        virtual AutoPtr<NativePipe> GetNativeStdout() = 0;
        virtual AutoPtr<NativePipe> GetNativeStderr() = 0;
        void AttachPipes(bool async);

    protected:
        void _GetPID(const ValueList& args, ValueRef result);
        void _GetExitCode(const ValueList& args, ValueRef result);
        void _GetArguments(const ValueList& args, ValueRef result);
        void _GetEnvironment(const ValueList& args, ValueRef result);
        void _SetEnvironment(const ValueList& args, ValueRef result);
        void _CloneEnvironment(const ValueList& args, ValueRef result);
        void _Launch(const ValueList& args, ValueRef result);
        void _Terminate(const ValueList& args, ValueRef result);
        void _Kill(const ValueList& args, ValueRef result);
        void _SendSignal(const ValueList& args, ValueRef result);
        void _GetStdin(const ValueList& args, ValueRef result);
        void _GetStdout(const ValueList& args, ValueRef result);
        void _GetStderr(const ValueList& args, ValueRef result);
        void _IsRunning(const ValueList& args, ValueRef result);
        void _SetOnRead(const ValueList& args, ValueRef result);
        void _SetOnExit(const ValueList& args, ValueRef result);
        void _ToString(const ValueList& args, ValueRef result);
        void DetachPipes();

        AutoPipe stdoutPipe;
        AutoPipe stderrPipe;
        AutoPipe stdinPipe;
        TiObjectRef environment;
        TiListRef args;
        int pid;
        ValueRef exitCode;
        TiMethodRef onRead;
        TiMethodRef onExit;
        Poco::RunnableAdapter<Process>* exitMonitorAdapter;
        Poco::Thread exitMonitorThread;
        TiMethodRef exitCallback;
        bool running;
    };
}

#endif
