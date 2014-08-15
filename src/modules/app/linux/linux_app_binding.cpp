/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/


#include <tide/tide.h>
#include "../app_binding.h"

namespace ti
{

void AppBinding::Restart(const ValueList& args, ValueRef result)
{
	Host* host = Host::GetInstance();
	std::string cmdline(host->GetApplication()->arguments.at(0));

	// Remove all quotes.
	size_t i = cmdline.find('\"');
	while (i != std::string::npos)
	{
		cmdline.replace(i, 1, "");
		i = cmdline.find('\"');
	}

	std::string script = "\"" + cmdline + "\" &";
	if (system(script.c_str()) == -1)
		throw ValueException::FromString("Failed to start new process.");

	host->Exit(0);
}

void AppBinding::Setup() 
{
}

}
