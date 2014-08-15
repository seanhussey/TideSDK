/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/


#ifndef _BOOT_H_
#define _BOOT_H_

// ensure that Tide API is never included to create
// an artificial dependency on Tide shared library
#ifdef _TIDE_H_
#error You should not have included the Tide api!
#endif

#define BOOTSTRAP_ENV "KR_BOOTSTRAPPED"

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <tideutils/boot_utils.h>
#include <tideutils/application.h>
#include <tideutils/environment_utils.h>
using namespace TideUtils;

using TideUtils::Application;
using TideUtils::Dependency;
using TideUtils::KComponent;
using TideUtils::SharedApplication;
using TideUtils::SharedDependency;
using TideUtils::SharedComponent;
using std::string;
using std::vector;
using std::map;

#ifdef OS_WIN32
#define MODULE_SEPARATOR ";"
#else
#define MODULE_SEPARATOR ":"
#endif

namespace TideBoot
{
    /**
     * Implemented platform independently
     */
    int Bootstrap();
    void FindUpdate();

    /**
     * Implemented platform specifically
     */
    void ShowError(std::string error, bool fatal=false);
    std::string GetApplicationHomePath();
    bool RunInstaller(vector<SharedDependency> missing, bool forceInstall=false);
    void BootstrapPlatformSpecific(string moduleList);
    int StartHost();
    string Blastoff();
    vector<SharedDependency> FilterForSDKInstall(
        vector<SharedDependency> dependencies);
    string GetApplicationName();
}
#endif
