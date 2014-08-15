/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _SCRIPT_BINDING_H
#define _SCRIPT_BINDING_H

#include <tide/tide.h>

namespace tide
{
    class TIDE_API ScriptBinding : public StaticBoundObject
    {
    public:
        ScriptBinding();
        
    protected:
        void _AddScriptEvaluator(const ValueList& args, ValueRef result);
        void _RemoveScriptEvaluator(const ValueList& args, ValueRef result);
        void _CanEvaluate(const ValueList& args, ValueRef result);
        void _CanPreprocess(const ValueList& args, ValueRef result);
        void _Evaluate(const ValueList& args, ValueRef result);
        void _Preprocess(const ValueList& args, ValueRef result);
    };
}
#endif
