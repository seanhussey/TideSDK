/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _NOTIFICATION_H_
#define _NOTIFICATION_H_

#include <tide/tide.h>

#ifdef OS_LINUX
typedef struct _NotifyNotification NotifyNotification;
typedef NotifyNotification* PlatformNotification;
#elif defined(OS_WIN32)
typedef long PlatformNotification;
#elif defined(OS_OSX)
// Unused.
typedef char PlatformNotification;
#endif

namespace ti
{

class Notification : public AccessorObject
{
public:
    Notification();
    ~Notification();
    void Configure(TiObjectRef properties);

    static bool InitializeImpl();
    static void ShutdownImpl();
    void CreateImpl();
    void DestroyImpl();
    bool ShowImpl();
    bool HideImpl();

private:
    std::string title;
    std::string message;
    std::string iconURL;
    int timeout;
    PlatformNotification notification;

    void _SetTitle(const ValueList& args, ValueRef result);
    void _SetMessage(const ValueList& args, ValueRef result);
    void _SetIcon(const ValueList& args, ValueRef result);
    void _SetTimeout(const ValueList& args, ValueRef result);
    void _Show(const ValueList& args, ValueRef result);
    void _Hide(const ValueList& args, ValueRef result);
};

typedef AutoPtr<Notification> AutoNotification;

}

#endif
