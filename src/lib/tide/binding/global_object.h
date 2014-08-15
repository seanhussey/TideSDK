/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _GLOBAL_OBJECT_H_
#define _GLOBAL_OBJECT_H_

namespace tide
{
    class TIDE_API GlobalObject : public EventObject
    {
    public:
        GlobalObject();
        ~GlobalObject();
        static void TurnOnProfiling();

        inline static AutoPtr<GlobalObject> GetInstance()
        {
            return GlobalObject::instance;
        }

        inline static void Initialize()
        {
            instance = new GlobalObject();
        }

    private:
        static AutoPtr<GlobalObject> instance;

        void GetVersion(const ValueList& args, ValueRef result);
        void GetPlatform(const ValueList& args, ValueRef result);
    };
}

#endif
