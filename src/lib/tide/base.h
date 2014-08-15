/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _TIDE_BASE_H_
#define _TIDE_BASE_H_

#include <tideutils/base.h>

#ifdef USE_NO_EXPORT
#define TIDE_API
#else
#if defined(OS_OSX) || defined(OS_LINUX)
#define EXPORT __attribute__((visibility("default")))
#define TIDE_API EXPORT
#elif defined(OS_WIN32)
# ifdef TIDE_API_EXPORT
#  define TIDE_API __declspec(dllexport)
# else
#  define TIDE_API __declspec(dllimport)
# endif
# define EXPORT __declspec(dllexport)
#endif
#endif

#endif
