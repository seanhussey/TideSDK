/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _JAVASCRIPT_MODULE_INSTANCE_H_
#define _JAVASCRIPT_MODULE_INSTANCE_H_

namespace tide
{
    class TIDE_API JavaScriptModuleInstance : public Module
    {
    public:
        JavaScriptModuleInstance(Host *host, std::string path, 
            std::string dir, std::string name);
        void Initialize () {}
        void Stop();
        void Run();
        static void GarbageCollect();

    protected:
        std::string path;
        JSGlobalContextRef context;
        JSObjectRef global;
    };
}

#endif
