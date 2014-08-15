/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef TI_DATABASE_MODULE_H_
#define TI_DATABASE_MODULE_H_

#include <tide/tide.h>

#if defined(OS_OSX) || defined(OS_LINUX)
#define EXPORT __attribute__((visibility("default")))
#define TIDESDK_DATABASE_API EXPORT
#elif defined(OS_WIN32)
#ifdef TIDESDK_DATABASE_API_EXPORT
#define TIDESDK_DATABASE_API __declspec(dllexport)
#else
#define TIDESDK_DATABASE_API __declspec(dllimport)
#endif
#define EXPORT __declspec(dllexport)
#endif

namespace ti 
{
    /**
     * Database module which exposes a synchronous API for Database
     * access and interoperates with the WebKit Database seamlessly.
     *
     * You can interchangeably use the WebKit HTML 5 Database API or
     * this API on the same database.  Additionally, if you create 
     * databases in this API, they will be exposed in the Web
     * Inspector.
     *
     */
    class TIDESDK_DATABASE_API DatabaseModule : public tide::Module, public StaticBoundObject
    {
        TIDE_MODULE_CLASS(DatabaseModule)

    private:
        tide::TiObjectRef binding;
        void Open(const ValueList& args, ValueRef result);
        void OpenFile(const ValueList& args, ValueRef result);
    };
}

#endif
