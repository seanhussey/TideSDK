/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef PYTHONAPI_H_
#define PYTHONAPI_H_

#if defined(OS_OSX) || defined(OS_LINUX)
#define EXPORT __attribute__((visibility("default")))
#define TIDESDK_PYTHON_API EXPORT
#elif defined(OS_WIN32)
#ifdef TIDESDK_PYTHON_API_EXPORT
#define TIDESDK_PYTHON_API __declspec(dllexport)
#else
#define TIDESDK_PYTHON_API __declspec(dllimport)
#endif
#endif

#endif /* PYTHONAPI_H_ */
