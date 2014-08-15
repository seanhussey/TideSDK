/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _ACCESSOR_LIST_H_
#define _ACCESSOR_LIST_H_

namespace tide
{
    /**
     * The AccessorList allows you to expose getters and setters as property access.
     * @see AccessorObject
     */
    class TIDE_API AccessorList : public StaticBoundList, public Accessor
    {
    public:
        AccessorList(const char* type = "AccessorList");
        virtual void Set(const char* name, ValueRef value);
        virtual ValueRef Get(const char* name);
        virtual bool HasProperty(const char* name);

    private:
        DISALLOW_EVIL_CONSTRUCTORS(AccessorList);
    };
}

#endif
