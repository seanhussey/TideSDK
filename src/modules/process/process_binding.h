/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PROCESS_BINDING_H_
#define _PROCESS_BINDING_H_

#include <tide/tide.h>
#include <vector>
#include "process.h"
#include "pipe.h"

namespace ti
{
    class ProcessBinding : public AccessorObject
    {
    public:
        ProcessBinding();
        virtual ~ProcessBinding();
        static std::map<std::string,int> signals;

    private:
        void CreateProcess(const ValueList& args, ValueRef result);
        void CreatePipe(const ValueList& args, ValueRef result);
        void GetCurrentProcess(const ValueList& args, ValueRef result);
        void ExtendArgs(TiListRef dest, TiListRef args);
    };
}

#endif
