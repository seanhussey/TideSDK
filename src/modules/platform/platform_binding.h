/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PLATFORM_BINDING_H_
#define _PLATFORM_BINDING_H_
#include <tide/tide.h>

namespace ti
{
    class PlatformBinding : public AccessorObject
    {
    public:
        PlatformBinding();

    private:
        virtual ~PlatformBinding();
        std::string GetVersionImpl();
        bool OpenApplicationImpl(const std::string& path);
        bool OpenURLImpl(const std::string& url);
        void TakeScreenshotImpl(const std::string& targetFile);

        void _GetType(const ValueList& args, ValueRef result);
        void _GetName(const ValueList& args, ValueRef result);
        void _GetProcessorCount(const ValueList& args, ValueRef result);
        void _GetVersion(const ValueList& args, ValueRef result);
        void _GetArchitecture(const ValueList& args, ValueRef result);
        void _GetMachineId(const ValueList& args, ValueRef result);
        void _GetUsername(const ValueList& args, ValueRef result);
        void _CreateUUID(const ValueList& args, ValueRef result);
        void _OpenURL(const ValueList& args, ValueRef result);
        void _OpenApplication(const ValueList& args, ValueRef result);
        void _TakeScreenshot(const ValueList& args, ValueRef result);
    };
}

#endif
