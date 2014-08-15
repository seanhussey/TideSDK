/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _WORKER_BINDING_H_
#define _WORKER_BINDING_H_

#include <tide/tide.h>

namespace ti
{
    class WorkerBinding : public StaticBoundObject
    {
    public:
        WorkerBinding();
        ~WorkerBinding();

    private:
        void _CreateWorker(const ValueList& args, ValueRef result);
    };
}

#endif
