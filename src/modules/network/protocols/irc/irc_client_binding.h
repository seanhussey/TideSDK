/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _IRC_CLIENT_BINDING_H_
#define _IRC_CLIENT_BINDING_H_

#include <tide/tide.h>
#include <Poco/Thread.h>
#ifdef OS_LINUX
#include <unistd.h>
#endif
#include "IRC.h"

namespace ti
{
    class IRCClientBinding : public StaticBoundObject
    {
    public:
        IRCClientBinding(Host*);
        virtual ~IRCClientBinding();
    private:
        Host* host;
        TiObjectRef global;
        IRC irc;
        TiMethodRef callback;
        Poco::Thread *thread;
        
        static void Run(void*);
        static int Callback(char *cmd, char* params, irc_reply_data* data, void* conn, void* pd);
        
        
        void Connect(const ValueList& args, ValueRef result);
        void Disconnect(const ValueList& args, ValueRef result);
        void Send(const ValueList& args, ValueRef result);
        void SetNick(const ValueList& args, ValueRef result);
        void GetNick(const ValueList& args, ValueRef result);
        void Join(const ValueList& args, ValueRef result);
        void Unjoin(const ValueList& args, ValueRef result);
        void IsOp(const ValueList& args, ValueRef result);
        void IsVoice(const ValueList& args, ValueRef result);
        void GetUsers(const ValueList& args, ValueRef result);

    };
}

#endif
