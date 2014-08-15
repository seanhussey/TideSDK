/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _MAIN_THREAD_JOB_H
#define _MAIN_THREAD_JOB_H

#include <Poco/Semaphore.h>

namespace tide
{
    class TIDE_API MainThreadJob
    {
    public:
        MainThreadJob(TiMethodRef method, TiObjectRef thisObject,
            const ValueList& args, bool waitForCompletion);
        void Lock();
        void Wait();
        void Execute();
        ValueRef GetResult();
        ValueException GetException();
        bool ShouldWaitForCompletion();
        void PrintException();

    private:
        TiMethodRef method;
        TiObjectRef thisObject;
        const ValueList args;
        bool waitForCompletion;
        ValueRef returnValue;
        ValueException exception;
        Poco::Semaphore semaphore;
    };
}

#endif
