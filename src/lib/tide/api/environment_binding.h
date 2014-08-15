/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _ENVIRONMENT_BINDING_H_
#define _ENVIRONMENT_BINDING_H_

#include <tide/tide.h>

namespace tide
{
    class EnvironmentBinding : public TiObject
    {
    public:
        EnvironmentBinding() : TiObject("API.Environment") {}
        
        virtual ValueRef Get(const char *name);
        virtual SharedStringList GetPropertyNames();
        virtual void Set(const char *name, ValueRef value);
        virtual SharedString DisplayString(int levels=3);
    };
}
#endif
