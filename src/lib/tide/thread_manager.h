/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _THREAD_MANAGER_H_
#define _THREAD_MANAGER_H_

#ifdef OS_OSX
#define START_TIDE_THREAD NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
#define END_TIDE_THREAD [pool release];
#else
#define START_TIDE_THREAD
#define END_TIDE_THREAD
#endif

#endif
