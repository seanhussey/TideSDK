/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _TI_FILESYSTEM_UTILS_H_
#define _TI_FILESYSTEM_UTILS_H_

#include <tide/tide.h>

namespace ti
{
    namespace FilesystemUtils
    {
        std::string FilenameFromValue(ValueRef);
        std::string FilenameFromArguments(const ValueList& args);
    }
}

#endif
