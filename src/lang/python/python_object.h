/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PYTHON_OBJECT_H_
#define _PYTHON_OBJECT_H_

#include "python_module.h"

namespace tide
{
    class KPythonObject : public TiObject
    {
    public:
        KPythonObject(PyObject *obj);
        KPythonObject(PyObject *obj, bool readOnly);
        virtual ~KPythonObject();

        virtual void Set(const char *name, ValueRef value);
        virtual ValueRef Get(const char *name);
        virtual bool Equals(TiObjectRef);
        virtual SharedStringList GetPropertyNames();
        PyObject* ToPython();

    private:
        PyObject *object;
        bool readOnly;
        TiObjectRef delegate;
        DISALLOW_EVIL_CONSTRUCTORS(KPythonObject);
    };
}

#endif
