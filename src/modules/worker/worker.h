/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _WORKER_H_
#define _WORKER_H_

#include <tide/tide.h>
#include <Poco/Thread.h>
#include <Poco/RunnableAdapter.h>
#include <Poco/Mutex.h>
#include <Poco/ScopedLock.h>
#include <queue>

namespace ti
{
    class WorkerContext;

    class Worker : public EventObject
    {
    public:
        Worker(std::string& code);
        ~Worker();
        void Error(ValueRef value);
        void SendMessageToMainThread(ValueRef message);
        virtual void Set(const char* name, ValueRef value);

    private:
        std::string code;
        AutoPtr<WorkerContext> workerContext;
        Poco::Thread thread;
        Poco::RunnableAdapter<Worker>* adapter;
        std::queue<ValueRef> inbox;
        Poco::Mutex inboxLock;

        void Run();
        void HandleInbox();
        void DeliverMessage(ValueRef message);
        void _Start(const ValueList& args, ValueRef result);
        void _Terminate(const ValueList& args, ValueRef result);
        void _PostMessage(const ValueList& args, ValueRef result);
    };
}

#endif
