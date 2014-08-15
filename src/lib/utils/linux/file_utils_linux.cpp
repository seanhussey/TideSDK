/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/


#include <tideutils/file_utils.h>
#include <cstdarg>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/utsname.h>
#include <libgen.h>

#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>

using std::string;

namespace TideUtils
{
namespace FileUtils
{
    std::string GetAppDataDirectory()
    {
        passwd *user = getpwuid(getuid());
        return std::string(user->pw_dir);
    }

    std::string GetUserRuntimeHomeDirectory()
    {
        string pname = PRODUCT_NAME;
        std::transform(pname.begin(), pname.end(), pname.begin(), tolower);
        pname = std::string(".") + pname;
    
        passwd *user = getpwuid(getuid());
        return Join(user->pw_dir, pname.c_str(), NULL);
    }

    std::string GetSystemRuntimeHomeDirectory()
    {
        // Try to be a little smart about where the system runtime home
        // is. If we can't find it, just give up and use the /opt location
        string pname = PRODUCT_NAME;
        std::transform(pname.begin(), pname.end(), pname.begin(), tolower);
        string path = Join("/opt", pname.c_str(), NULL);
        if (!IsDirectory(path))
            path = Join("/usr/local/lib", pname.c_str(), NULL);
        if (!IsDirectory(path))
            path = Join("/usr/lib", pname.c_str(), NULL);
        if (!IsDirectory(path))
            path = Join("/opt", pname.c_str(), NULL);
        return path;
    }

    void WriteFile(const std::string& path, const std::string& content)
    {
        std::ofstream f(path.c_str());
        f << content;
        f.close();
    }

    std::string ReadFile(const std::string& path)
    {
        std::ostringstream inputStream;

        std::ifstream inputFile(path.c_str());

        if (!inputFile.is_open())
            return inputStream.str();

        std::string line;
        while (!inputFile.eof())
        {
            getline(inputFile, line);
            inputStream << line << std::endl;
        }

        inputFile.close();
        return inputStream.str();
    }
}
}
