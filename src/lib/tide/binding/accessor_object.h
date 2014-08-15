/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _ACCESSOR_OBJECT_H_
#define _ACCESSOR_OBJECT_H_

namespace tide
{
    class TIDE_API AccessorObject : public StaticBoundObject, public Accessor
    {
    public:
        AccessorObject(const char* name = "AccessorObject");
        virtual void Set(const char* name, ValueRef value);
        virtual ValueRef Get(const char* name);
        virtual bool HasProperty(const char* name);

    private:
        DISALLOW_EVIL_CONSTRUCTORS(AccessorObject);
    };
}

#endif
