/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _TINET_TCP_SOCKET_H_
#define _TINET_TCP_SOCKET_H_

#include <queue>
#include <string>

#include <Poco/Net/StreamSocket.h>
#include <Poco/Thread.h>
#include <Poco/Mutex.h>

#include <tide/tide.h>

namespace ti
{
    class TCPSocket : public EventObject
    {
    public:
        TCPSocket(std::string& host, int port);
        virtual ~TCPSocket();

        void Connect();
        bool Close();
        void Write(BytesRef data);
        void SetKeepAlive(bool enable);
        void SetTimeout(long milliseconds);

        void ReadThread();
        void WriteThread();

    private:
        void HandleError(Poco::Exception& e);

        void _Connect(const ValueList& args, ValueRef result);
        void _SetTimeout(const ValueList& args, ValueRef result);
        void _Close(const ValueList& args, ValueRef result);
        void _IsClosed(const ValueList& args, ValueRef result);
        void _Write(const ValueList& args, ValueRef result);
        void _OnRead(const ValueList& args, ValueRef result);
        void _OnReadComplete(const ValueList& args, ValueRef result);
        void _OnError(const ValueList& args, ValueRef result);
        void _OnTimeout(const ValueList& args, ValueRef result);

        Poco::Net::SocketAddress address;
        Poco::Net::StreamSocket socket;
        enum { CONNECTING, READONLY, WRITEONLY, DUPLEX, CLOSING, CLOSED } state;
        Poco::Thread readThread;
        Poco::RunnableAdapter<TCPSocket> reader, writer;
        std::queue<BytesRef> writeQueue;
        Poco::FastMutex mutex;
    };
}

#endif
