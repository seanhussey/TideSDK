/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

/**
 * This file is the easiest way to gain access to the full TideSDK API
 * To use it, just do the following:
 * \code
 * #include <tide/tide.h>
 * \endcode
 */

#ifndef _TIDE_H_
#define _TIDE_H_

#include "base.h"
#include <Poco/SharedPtr.h>
#include <Poco/AutoPtr.h>
#include <vector>

using Poco::SharedPtr;
using Poco::AutoPtr;

#ifndef OS_WIN32
    // this is important which essentially marks all of
    // these classes below and the typedef/templates to be
    // visible outside of the library.  if you don't do this
    // you won't be able to catch exceptions of ValueRef for
    // example
    #pragma GCC visibility push(default)
#endif

namespace tide
{
    class Value;
    class TiObject;
    class TiMethod;
    class TiList;

    class StaticBoundObject;
    class StaticBoundMethod;
    class StaticBoundList;

    class GlobalObject;
    class ScopeMethodDelegate;
    class Bytes;
    class VoidPtr;
    class ValueReleasePolicy;
    class Logger;
    class ArgList;

    typedef AutoPtr<Value> ValueRef;
    typedef AutoPtr<TiObject> TiObjectRef;
    typedef AutoPtr<TiMethod> TiMethodRef;
    typedef AutoPtr<TiList> TiListRef;
    typedef AutoPtr<Bytes> BytesRef;

    typedef SharedPtr<std::string> SharedString;
    typedef std::vector<SharedString> StringList;
    typedef SharedPtr<StringList> SharedStringList;

    typedef ArgList ValueList;

    class Module;
}

#ifndef OS_WIN32
    #pragma GCC visibility pop
#endif

#include "reference_counted.h"
#include "logger.h"

#include "binding/binding.h"
#include "module_provider.h"
#include "module.h"
#include "async_job.h"
#include "main_thread_job.h"
#include "script.h"

#ifdef OS_OSX
#include "osx/osx.h"
#elif defined(OS_WIN32)
#include "win32/win32.h"
#endif

#include "host.h"

#endif
