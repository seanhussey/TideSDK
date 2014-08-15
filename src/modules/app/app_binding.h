/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _APP_BINDING_H_
#define _APP_BINDING_H_

#include <tide/tide.h>


namespace ti
{
	class AppBinding : public AccessorObject
	{
	public:
		AppBinding(Host *host,TiObjectRef);
		virtual ~AppBinding();

	private:
		Host* host;
		TiObjectRef global;

		void GetID(const ValueList& args, ValueRef result);
		void GetName(const ValueList& args, ValueRef result);
		void GetVersion(const ValueList& args, ValueRef result);
		void GetPublisher(const ValueList& args, ValueRef result);
		void GetCopyright(const ValueList& args, ValueRef result);
		void GetDescription(const ValueList& args, ValueRef result);
		void GetURL(const ValueList& args, ValueRef result);
		void GetGUID(const ValueList& args, ValueRef result);
		void GetIcon(const ValueList& args, ValueRef result);
		void GetStreamURL(const ValueList& args, ValueRef result);
		void GetPath(const ValueList& args, ValueRef result);
		void GetHome(const ValueList& args, ValueRef result);
		void GetArguments(const ValueList& args, ValueRef result);
		void AppURLToPath(const ValueList& args, ValueRef result);
		void SetMenu(const ValueList& args, ValueRef result);
		void Exit(const ValueList& args, ValueRef result);
		void Restart(const ValueList& args, ValueRef result);
		void StdOut(const ValueList& args, ValueRef result);
		void StdErr(const ValueList& args, ValueRef result);
		void StdIn(const ValueList& args, ValueRef result);

		void CreateProperties(const ValueList& args, ValueRef result);
		void LoadProperties(const ValueList& args, ValueRef result);
		void GetSystemProperties(const ValueList& args, ValueRef result);

	protected:
		void Setup();
	};
}

#endif
