/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef PYTHON_TYPES_H_
#define PYTHON_TYPES_H_

#include <typeinfo>
#include "python_module.h"

namespace tide
{
    class PythonUtils
    {
    public:
        static void InitializePythonKClasses();
        static ValueRef ToTiValue(PyObject* value);
        static PyObject* ToPyObject(ValueRef value);
        static PyObject* ToPyObject(const ValueList& list);
        static const char* ToString(PyObject* value);
        static PyObject* TiObjectToPyObject(ValueRef o);
        static PyObject* TiMethodToPyObject(ValueRef o);
        static PyObject* TiListToPyObject(ValueRef o);
        static std::string PythonErrorToString();

    private:
        PythonUtils() {}
        ~PythonUtils () {}
    };
}

#endif
