/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _HOST_EVENT_WINDOW_H
#define _HOST_EVENT_WINDOW_H

#include <vector>
#include <Poco/Mutex.h>

typedef bool (*MessageHandler)(HWND hwnd, unsigned int message, WPARAM wParam, LPARAM lParam);

namespace tide
{
    class Logger;
    class EventWindow
    {
    public:
        EventWindow();
        virtual ~EventWindow();
        void DestroyWindow();
        HWND AddMessageHandler(MessageHandler handler);
        LRESULT CALLBACK Handler(
            HWND hwnd, unsigned int message, WPARAM wParam, LPARAM lParam);
        HWND GetHandle() { return handle; }
        
    private:
        HWND handle;
        Logger* logger;
        std::vector<MessageHandler> handlers;
        Poco::Mutex handlersMutex;
    };
}

#endif
