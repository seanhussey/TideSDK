/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Refer to LICENSE for details of distribution and use.
 **/

#include <sstream>

#include "tcp_socket_binding.h"
#include "ssl_tcp_socket_binding.h"
#include "socket_binding.h"

namespace ti
{
	SocketBinding::SocketBinding(Host* host) :
		AccessorObject("Socket"),
		host(host),
		global(host->GetGlobalObject())
	{
		this->SetMethod("createTCPSocket",&SocketBinding::_CreateTCPSocket);
		this->SetMethod("getSSLTCPSocket",&SocketBinding::_getSSLTCPSocket);
	}

	SocketBinding::~SocketBinding()
	{
	}

	void SocketBinding::_CreateTCPSocket(const ValueList& args, ValueRef result)
	{
		args.VerifyException("createTCPSocket", "ss");
		result->SetObject(new TCPSocketBinding(host, args.GetString(0), args.GetString(1)));
	}

	void SocketBinding::_getSSLTCPSocket(const ValueList& args, ValueRef result)
	{
		TCPSocketBinding * socket = args.GetObject(0).cast<TCPSocketBinding>();
		result->SetObject(new SecureTCPSocket(host, socket));
	}

	Host* SocketBinding::GetHost()
	{
		return this->host;
	}
}
