/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _WORKER_CONTEXT_H_
#define _WORKER_CONTEXT_H_

#include <tide/tide.h>
#include <Poco/Thread.h>
#include <Poco/RunnableAdapter.h>
#include <Poco/Event.h>
#include <Poco/Mutex.h>
#include <JavaScriptCore/JSBase.h>
#include <queue>

namespace ti
{
    class Worker;
    class WorkerContext : public EventObject
    {
    public:
        WorkerContext(Worker* worker);
        ~WorkerContext();
        virtual ValueRef Get(const char*);
        virtual void Set(const char*, ValueRef);
        void StartWorker(const std::string& code);
        void Terminate();
        void SendMessageToWorker(ValueRef message);
        void _PostMessage(const ValueList &args, ValueRef result);
        void _ImportScripts(const ValueList &args, ValueRef result);
        void _Sleep(const ValueList &args, ValueRef result);

    private:
        Worker* worker;
        JSGlobalContextRef jsContext;
        bool running;
        std::queue<ValueRef> inbox;
        Poco::Mutex inboxLock;
        Poco::Event messageEvent;
        Poco::Event terminateEvent;

        void DeliverMessage(ValueRef message);
        void MessageLoop();
    };
}

#endif
