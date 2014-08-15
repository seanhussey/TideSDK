/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PYTHON_DICT_H_
#define _PYTHON_DICT_H_

#include "python_module.h"

namespace tide
{
    class KPythonDict : public TiObject
    {
    public:
        KPythonDict(PyObject *obj);
        virtual ~KPythonDict();

        virtual void Set(const char *name, ValueRef value);
        virtual ValueRef Get(const char *name);
        virtual bool Equals(TiObjectRef);
        virtual SharedStringList GetPropertyNames();

        PyObject* ToPython();

    private:
        PyObject *object;
        DISALLOW_EVIL_CONSTRUCTORS(KPythonDict);
    };
}

#endif
