/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _COMPONENT_BINDING_H_
#define _COMPONENT_BINDING_H_

#include <tide/tide.h>
#include <map>
#include <vector>
#include <string>

namespace tide
{
    class ComponentBinding : public AccessorObject
    {
        public:
        ComponentBinding(SharedComponent component);

        private:
        SharedComponent component;

        void _GetType(const ValueList& args, ValueRef value);
        void _GetName(const ValueList& args, ValueRef value);
        void _GetVersion(const ValueList& args, ValueRef value);
        void _GetPath(const ValueList& args, ValueRef value);
        void _IsBundled(const ValueList& args, ValueRef value);
        void _IsLoaded(const ValueList& args, ValueRef value);
    };
}
#endif
