/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include <tideutils/file_utils.h>
using namespace TideUtils;

#include "filesystem_utils.h"

#include <Poco/File.h>
#include <Poco/Path.h>
#include <Poco/FileStream.h>
#include <Poco/Exception.h>

namespace ti
{

namespace FilesystemUtils
{

    std::string FilenameFromValue(ValueRef v)
    {
        if (v->IsString())
        {
            return v->ToString();
        }
        else if (v->IsObject())
        {
            return *(v->ToObject()->DisplayString());
        }
        else
        {
            throw ValueException::FromFormat(
                "Can't convert object of type %s to filename", v->GetType().c_str());
        }
    }

    std::string FilenameFromArguments(const ValueList& args)
    {
        std::string filename;
        if (args.at(0)->IsList())
        {
            // you can pass in an array of parts to join
            TiListRef list(args.GetList(0));
            for (size_t c = 0; c < list->Size(); c++)
            {
                filename = FileUtils::Join(filename.c_str(), list->At(c)->ToString(), NULL);
            }
        }
        else
        {
            // you can pass in vararg of strings which acts like  a join
            for (size_t c = 0; c < args.size(); c++)
            {
                filename = FileUtils::Join(filename.c_str(), FilenameFromValue(args.at(c)).c_str(), 0);
            }
        }

        if (filename.empty())
            throw ValueException::FromString("Could not construct filename from arguments");

        return filename;
    }
}
}
