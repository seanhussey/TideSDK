/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PHP_EVALUATOR_H_
#define _PHP_EVALUATOR_H_

#include <Poco/URI.h>

namespace tide
{
	class PHPEvaluator : public StaticBoundObject
	{
		public:
		PHPEvaluator();
		void CanEvaluate(const ValueList& args, ValueRef result);
		void CanPreprocess(const ValueList& args, ValueRef result);
		void Evaluate(const ValueList& args, ValueRef result);
		void Preprocess(const ValueList& args, ValueRef result);
		
		protected:
		std::string CreateContextName();
		void FillGet(Poco::URI& uri TSRMLS_DC);
		
	};
}

#endif
