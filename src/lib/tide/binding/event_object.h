/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _EVENT_OBJECT_H_
#define _EVENT_OBJECT_H_

#include <list>
#include <Poco/Mutex.h>

namespace tide
{
    class EventListener;
    typedef std::list<EventListener*> EventListenerList;

    class TIDE_API EventObject : public AccessorObject
    {
    public:
        EventObject(const char* name = "EventObject");
        virtual ~EventObject();

        AutoPtr<Event> CreateEvent(const std::string& eventName);

        virtual void AddEventListener(const char* event, TiMethodRef listener);
        virtual void AddEventListener(std::string& event, TiMethodRef listener);
        virtual void RemoveEventListener(std::string& event, TiMethodRef listener);
        virtual void RemoveAllEventListeners();

        void FireEvent(const char* event);
        virtual void FireEvent(const char* event, const ValueList& args);
        virtual bool FireEvent(std::string& event, bool synchronous=true);
        virtual bool FireEvent(AutoPtr<Event>, bool synchronous=true);
        void FireErrorEvent(std::exception& e);

        void _AddEventListener(const ValueList&, ValueRef result);
        void _RemoveEventListener(const ValueList&, ValueRef result);
        void _RemoveAllEventListeners(const ValueList&, ValueRef result);

    private:
        void ReportDispatchError(std::string& reason);

        EventListenerList listeners;
        Poco::FastMutex listenersMutex;
    };

    class EventListener
    {
    public:
        EventListener(std::string& targetedEvent, TiMethodRef callback);
        EventListener(const char* targetedEvent, TiMethodRef callback);

        bool Handles(const char* event);
        bool Dispatch(TiObjectRef thisObject, const ValueList& args, bool synchronous);
        TiMethodRef Callback();

    private:
        std::string targetedEvent;
        TiMethodRef callback;
    };
}

#endif
