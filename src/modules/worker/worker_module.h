/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef TI_WORKER_MODULE_H_
#define TI_WORKER_MODULE_H_

#include <tide/tide.h>

#if defined(OS_OSX) || defined(OS_LINUX)
#define EXPORT __attribute__((visibility("default")))
#define TIDESDK_WORKER_API EXPORT
#elif defined(OS_WIN32)
# ifdef TIDESDK_WORKER_API_EXPORT
#  define TIDESDK_WORKER_API __declspec(dllexport)
# else
#  define TIDESDK_WORKER_API __declspec(dllimport)
# endif
# define EXPORT __declspec(dllexport)
#endif

namespace ti 
{
    class TIDESDK_WORKER_API WorkerModule : public tide::Module
    {
        TIDE_MODULE_CLASS(WorkerModule)
        
    private:
        tide::TiObjectRef binding;
    };

}
#endif
