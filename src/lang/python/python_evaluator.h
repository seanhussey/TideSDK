/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef PYTHON_EVALUATOR_H_
#define PYTHON_EVALUATOR_H_

#include <Poco/StringTokenizer.h>

namespace tide
{
    class PythonEvaluator : public StaticBoundObject
    {
    public:
        PythonEvaluator();
        void Evaluate(const ValueList& args, ValueRef result);
        void CanEvaluate(const ValueList& args, ValueRef result);

    private:
        static void UnindentCode(std::string &code);
        static void DictToTiObjectProps(PyObject* map, TiObjectRef o);
        static void TiObjectPropsToDict(TiObjectRef o, PyObject* pyobj);
    };
}

#endif
