/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _VOID_PTR_H_
#define _VOID_PTR_H_

#include "../tide.h"

namespace tide
{
    /**
     * An object that represents an arbitrary amount of binary data§
     */
    class TIDE_API VoidPtr : public StaticBoundObject
    {
    public:
        VoidPtr(void* pointer) :
            StaticBoundObject("VoidPtr"),
            pointer(pointer) {}
        void* GetPtr() { return pointer; }

    private:
        void* pointer;
    };
}

#endif
