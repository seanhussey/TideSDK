/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include <tide/tide.h>
#include "../app_binding.h"
#include <windows.h>

namespace ti
{

void AppBinding::Restart(const ValueList& args, ValueRef result)
{
	Host* host = Host::GetInstance();
	std::wstring cmdline(::UTF8ToWide(host->GetApplication()->arguments.at(0)));

	STARTUPINFO si;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	PROCESS_INFORMATION pi;
	ZeroMemory(&pi, sizeof(pi));

	::CreateProcessW(NULL,
		(LPWSTR) cmdline.c_str(),
		NULL, /*lpProcessAttributes*/
		NULL, /*lpThreadAttributes*/
		FALSE, /*bInheritHandles*/
		NORMAL_PRIORITY_CLASS,
		NULL,
		NULL,
		&si,
		&pi);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	host->Exit(0);
}

void AppBinding::Setup() 
{
}

}
