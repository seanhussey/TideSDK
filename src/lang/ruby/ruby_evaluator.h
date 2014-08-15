/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _RUBY_EVALUATOR_H_
#define _RUBY_EVALUATOR_H_

namespace tide
{
    class RubyEvaluator : public StaticBoundObject
    {
        public:
        RubyEvaluator();
        ~RubyEvaluator();

        void CanEvaluate(const ValueList& args, ValueRef result);
        void Evaluate(const ValueList& args, ValueRef result);

        private:
        std::string GetContextId(TiObjectRef global);
        VALUE GetContext(TiObjectRef global);
        void ContextToGlobal(VALUE ctx, TiObjectRef o);
    };
}

#endif
