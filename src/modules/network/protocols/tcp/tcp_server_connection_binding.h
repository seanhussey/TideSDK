/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _TCP_SERVER_CONNECTION_BINDING_H_
#define _TCP_SERVER_CONNECTION_BINDING_H_

#include <tide/tide.h>
#include <Poco/Thread.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketReactor.h>
#include <Poco/Net/SocketAcceptor.h>
#include <Poco/Net/SocketNotification.h>
#include <Poco/NObserver.h>
#include <Poco/RunnableAdapter.h>
#include <queue>

namespace ti
{
    class TCPServerConnectionBinding : public StaticBoundObject
    {
    public:
        TCPServerConnectionBinding(Poco::Net::StreamSocket& s, Poco::Net::SocketReactor & reactor_);
        virtual ~TCPServerConnectionBinding();

    private:
        enum
        {
            BUFFER_SIZE = 1024
        };
        Poco::Net::StreamSocket socket;
        Poco::Net::SocketReactor& reactor;
        bool closed;
        TiMethodRef onRead;
        TiMethodRef onWrite;
        TiMethodRef onError;
        TiMethodRef onReadComplete;
        std::queue<BytesRef> sendData;
        Poco::Mutex sendDataMutex;
        size_t currentSendDataOffset;
        bool readStarted;
        bool writeReadyHandlerInstalled;

        void onReadable (const Poco::AutoPtr<Poco::Net::ReadableNotification>&);
        void onShutdown (const Poco::AutoPtr<Poco::Net::ShutdownNotification>&);
        void onWritable (const Poco::AutoPtr<Poco::Net::WritableNotification>&);
        void onErrored(const Poco::AutoPtr<Poco::Net::ErrorNotification>&);

        void Write(const ValueList& args, ValueRef result);
        void Close(const ValueList& args, ValueRef result);
        void IsClosed(const ValueList& args, ValueRef result);
        void SetOnRead(const ValueList& args, ValueRef result);
        void SetOnWrite(const ValueList& args, ValueRef result);
        void SetOnError(const ValueList& args, ValueRef result);
        void SetOnReadComplete(const ValueList& args, ValueRef result);

    };
    
}

#endif
