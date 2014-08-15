/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _SOCKET_BINDING_H_
#define _SOCKET_BINDING_H_

#include <tide/tide.h>


namespace ti
{
	class SocketBinding : public AccessorObject
	{
	public:
		SocketBinding(Host*);
		virtual ~SocketBinding();

		Host* GetHost();

	private:
		Host* host;
		TiObjectRef global;

		void _CreateTCPSocket(const ValueList& args, ValueRef result);
		void _getSSLTCPSocket(const ValueList& args, ValueRef result);
	};
}

#endif
