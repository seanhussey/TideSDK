/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/


#include <tideutils/boot_utils.h>
#include <tideutils/file_utils.h>
#include <tideutils/application.h>
#include <tideutils/environment_utils.h>

namespace TideUtils
{
namespace BootUtils
{
    std::vector<std::string>& GetComponentSearchPaths()
    {
        static std::vector<std::string> componentSearchPaths;
        if (componentSearchPaths.empty())
        {
            // Allow the user to force an override to the runtime home by setting the
            // appropriate environment variable -- this will be the first path searched
            if (EnvironmentUtils::Has("KR_SEARCH_PATH"))
            {
                componentSearchPaths.push_back(EnvironmentUtils::Get("KR_SEARCH_PATH"));
            }

            componentSearchPaths.push_back(FileUtils::GetUserRuntimeHomeDirectory());
            componentSearchPaths.push_back(FileUtils::GetSystemRuntimeHomeDirectory());
        }
        return componentSearchPaths;
    }

    bool RunInstaller(
        vector<SharedDependency> missing,
        SharedApplication application,
        std::string updateFile,
        std::string installerPath,
        bool quiet,
        bool forceInstall)
    {
        if (installerPath.empty())
        {
            installerPath = application->path;
        }

        string exec = FileUtils::Join(
            installerPath.c_str(),
            "installer",
            "Installer App.app",
            "Contents", 
            "MacOS",
            "Installer App", NULL);

        if (!FileUtils::IsFile(exec))
        {
            return false;
        }

        vector<string> args;
        args.push_back("-appPath");
        args.push_back(application->path);

        if (!updateFile.empty())
        {
            args.push_back("-updateFile");
            args.push_back(updateFile);
        }

        if (quiet)
        {
            args.push_back("-quiet");
        }

        std::vector<SharedDependency>::iterator di = missing.begin();
        while (di != missing.end())
        {
            SharedDependency d = *di++;
            string url = application->GetURLForDependency(d);
            args.push_back(url);
        }

        FileUtils::RunAndWait(exec, args);
        return true;
    }
}
}
