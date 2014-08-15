/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PROFILED_GLOBAL_OBJECT_H_
#define _PROFILED_GLOBAL_OBJECT_H_

namespace tide
{
    class TIDE_API ProfiledGlobalObject : public GlobalObject
    {
    public:
        ProfiledGlobalObject(TiObjectRef delegate);
        virtual ~ProfiledGlobalObject();

        virtual void Set(const char *name, ValueRef value);
        virtual ValueRef Get(const char *name);
        virtual SharedStringList GetPropertyNames();
        virtual SharedString DisplayString(int levels=3);
        virtual bool Equals(TiObjectRef other);
        bool HasProperty(const char* name);

    protected:
        AutoPtr<ProfiledBoundObject> profiledObject;
    };
}

#endif
