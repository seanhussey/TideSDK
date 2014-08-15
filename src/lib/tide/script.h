/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _SCRIPT_H_
#define _SCRIPT_H_

#include <tide/tide.h>

namespace tide
{
    class TIDE_API PreprocessData : public ReferenceCounted
    {
    public:
        BytesRef data;
        std::string mimeType;
    };
    
    class TIDE_API Script
    {
    public:
        static SharedPtr<Script> GetInstance();
        static void Initialize();
        static bool HasExtension(const char *url, const char *ext);
        static std::string GetExtension(const char *url);
        
        void AddScriptEvaluator(TiObjectRef evaluator);
        void RemoveScriptEvaluator(TiObjectRef evaluator);

        bool CanEvaluate(const char *mimeType);
        bool CanPreprocess(const char *url);
        TiListRef GetEvaluators() { return evaluators; }

        ValueRef Evaluate(const char *mimeType, const char *name, const char *code, TiObjectRef scope);
        AutoPtr<PreprocessData> Preprocess(const char *url, TiObjectRef scope);
        
    protected:
        TiListRef evaluators;
        static SharedPtr<Script> instance;
        
        Script() : evaluators(new StaticBoundList()) { }
        TiObjectRef FindEvaluatorWithMethod(const char *method, const char *arg);
    };
}

#endif
