/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _JAVASCRIPT_METHODS_H_
#define _JAVASCRIPT_METHODS_H_

namespace tide
{
namespace JavaScriptMethods
{

void Bind(TiObjectRef global);
ValueRef SetTimeout(const ValueList& args);
ValueRef SetInterval(const ValueList& args);
ValueRef ClearTimeout(const ValueList& args);
ValueRef ClearInterval(const ValueList& args);

}
}

#endif
