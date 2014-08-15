/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PYTHON_METHOD_H_
#define _PYTHON_METHOD_H_

#include "python_module.h"

namespace tide
{
    class KPythonObject;
    class KPythonMethod : public TiMethod
    {
    public:
        KPythonMethod(PyObject *obj);
        virtual ~KPythonMethod();

        ValueRef Call(const ValueList& args);
        virtual void Set(const char *name, ValueRef value);
        virtual ValueRef Get(const char *name);
        virtual bool Equals(TiObjectRef);
        virtual SharedStringList GetPropertyNames();
        PyObject* ToPython();

    private:
        PyObject* method;
        AutoPtr<KPythonObject> object;
        DISALLOW_EVIL_CONSTRUCTORS(KPythonMethod);
    };
}

#endif
