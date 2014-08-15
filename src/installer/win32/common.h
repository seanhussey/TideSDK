/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _TIDE_INSTALLER_COMMON_H_
#define _TIDE_INSTALLER_COMMON_H_

#include <tideutils/base.h>

void ShowError(const std::string& msg);
void ShowError(const std::wstring& wmsg);
void ShutdownNetConnection();
bool DownloadDependency(SharedApplication app, SharedDependency dependency);
bool InstallDependency(SharedApplication app, SharedDependency dependency);

#endif
