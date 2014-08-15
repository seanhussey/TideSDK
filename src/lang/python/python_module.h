/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PYTHON_MODULE_H
#define _PYTHON_MODULE_H

#include <Python.h>
#include <tide/tide.h>
#include <string>
#include <vector>
#include <iostream>

#include "python_api.h"
#include "python_utils.h"
#include "python_object.h" 
#include "python_method.h"
#include "python_list.h"
#include "python_tuple.h"
#include "python_dict.h"
#include "python_evaluator.h"

#define THROW_PYTHON_EXCEPTION \
PyObject *_ptype, *_pvalue, *_trace; \
PyErr_Fetch(&_ptype, &_pvalue, &_trace); \
ValueException _ex = ValueException::FromString("Unknown"); \
if (_pvalue != NULL) \
{ \
    ValueRef _ex_val = PythonUtils::ToTiValue(_pvalue); \
    _ex = ValueException(_ex_val); \
} \
Py_XDECREF(_ptype); \
Py_XDECREF(_pvalue); \
Py_XDECREF(_trace); \
throw _ex;

namespace tide
{
    class TIDESDK_PYTHON_API PythonModule : public Module, public ModuleProvider
    {
    public:
        PythonModule(Host* host, const char* path) :
            Module(host, path, STRING(MODULE_NAME), STRING(MODULE_VERSION))
        {
        }

        ~PythonModule()
        {
        }

        void Initialize();
        void Stop();

        virtual bool IsModule(std::string& path);
        virtual Module* CreateModule(std::string& path);
        void InitializeBinding();

        Host* GetHost()
        {
            return host;
        }

        static PythonModule* Instance()
        {
            return instance_;
        }

    private:
        TiObjectRef binding;
        static PythonModule *instance_;
        DISALLOW_EVIL_CONSTRUCTORS(PythonModule);
    };

    struct PyLockGIL
    {
        PyLockGIL() : gstate(PyGILState_Ensure())
        { }

        ~PyLockGIL()
        {
            PyGILState_Release(gstate);
        }

        PyGILState_STATE gstate;
    };

    struct PyAllowThreads
    {
        PyAllowThreads() : threadState(PyEval_SaveThread())
        { }

        ~PyAllowThreads()
        {
            PyEval_RestoreThread(threadState);
        }

        PyThreadState* threadState;
    };
}

#include "python_module_instance.h"

#endif
