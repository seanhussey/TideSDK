/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _EVENT_H_
#define _EVENT_H_

namespace tide
{
    class TIDE_API Event : public AccessorObject
    {
    public:
        Event(AutoPtr<EventObject> target, const std::string& eventName);
        void _GetTarget(const ValueList&, ValueRef result);
        void _GetType(const ValueList&, ValueRef result);
        void _GetTimestamp(const ValueList&, ValueRef result);
        void _StopPropagation(const ValueList&, ValueRef result);
        void _PreventDefault(const ValueList&, ValueRef result);
        static void SetEventConstants(TiObject* target);

        AutoPtr<EventObject> target;
        std::string eventName;
        Poco::Timestamp timestamp;
        bool stopped;
        bool preventedDefault;
        static std::string ALL;
        static std::string FOCUSED;
        static std::string UNFOCUSED;
        static std::string OPEN;
        static std::string OPENED;
        static std::string CLOSE;
        static std::string CLOSED;
        static std::string HIDDEN;
        static std::string SHOWN;
        static std::string REOPEN;
        static std::string FULLSCREENED;
        static std::string UNFULLSCREENED;
        static std::string MAXIMIZED;
        static std::string MINIMIZED;
        static std::string RESIZED;
        static std::string MOVED;
        static std::string PAGE_INITIALIZED;
        static std::string PAGE_LOADED;
        static std::string CREATED;
        static std::string ACTIVATE;
        static std::string CLICKED;
        static std::string DOUBLE_CLICKED;
        static std::string DOCK_ICON_CLICKED;
        static std::string EXIT;
        static std::string APP_EXIT;
        static std::string READ;
        static std::string HTTP_DONE;
        static std::string HTTP_STATE_CHANGED;
        static std::string HTTP_TIMEOUT;
        static std::string HTTP_REDIRECT;
        static std::string HTTP_ABORT;
        static std::string HTTP_DATA_SENT;
        static std::string HTTP_DATA_RECEIVED;
        static std::string OPEN_REQUEST;
    };
}

#endif
