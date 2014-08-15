/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PIPE_H_
#define _PIPE_H_

#include <tide/tide.h>
#include <queue>
#include <Poco/Thread.h>
#include <Poco/ThreadTarget.h>

namespace ti
{
    class Pipe;
    typedef AutoPtr<Pipe> AutoPipe;

    class Pipe : public EventObject
    {
        public:
        Pipe(const char *type = "Process.Pipe");
        virtual ~Pipe();
        virtual int Write(BytesRef data);
        virtual void CallWrite(TiObjectRef target, BytesRef data);
        virtual void Close();
        virtual void CallClose(TiObjectRef target);
        virtual void Flush();
        void Attach(TiObjectRef object);
        void Detach(TiObjectRef object);
        bool IsAttached();
        AutoPipe Clone();
        std::vector<BytesRef> readData;
        static void FireEventAsynchronously(AutoPtr<Event> event);

        protected:
        int FindFirstLineFeed(char *data, int length, int *charsToErase);
        void _Close(const ValueList& args, ValueRef result);
        void _SetOnClose(const ValueList& args, ValueRef result);
        void _Attach(const ValueList& args, ValueRef result);
        void _Detach(const ValueList& args, ValueRef result);
        void _IsAttached(const ValueList& args, ValueRef result);
        void _Write(const ValueList& args, ValueRef result);
        void _Flush(const ValueList& args, ValueRef result);
        Poco::Mutex attachedMutex;
        std::vector<TiObjectRef> attachedObjects;
        Logger *logger;
    };
}

#endif
