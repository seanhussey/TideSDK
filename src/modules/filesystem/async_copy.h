/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _TI_ASYNC_COPY_H
#define _TI_ASYNC_COPY_H

#include <tide/tide.h>

#ifdef OS_WIN32
#include <windows.h>
#elif OS_OSX
#import <Foundation/Foundation.h>
#endif

#include <string>
#include <vector>
#include <Poco/Thread.h>
#include <Poco/Exception.h>
#include <Poco/Path.h>
#include <Poco/File.h>
#include "filesystem_binding.h"


namespace ti
{
    class AsyncCopy : public StaticBoundObject
    {
    public:
        AsyncCopy(FilesystemBinding* parent,tide::Host *host,std::vector<std::string> files, std::string destination, TiMethodRef callback);
        virtual ~AsyncCopy();

    private:
        FilesystemBinding* parent;
        Host *host;
        std::vector<std::string> files;
        std::string destination;
        TiMethodRef callback;
        Poco::Thread *thread;
        bool stopped;

        static void Run(void*);

        void ToString(const ValueList& args, ValueRef result);
        void Cancel(const ValueList& args, ValueRef result);
        void Copy(Poco::Path &src, Poco::Path &dest);
    };
}

#endif
