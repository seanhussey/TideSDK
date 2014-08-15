/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PYTHON_TUPLE_H_
#define _PYTHON_TUPLE_H_

#include "python_module.h"

namespace tide
{
    class KPythonTuple : public TiList
    {
    public:
        KPythonTuple(PyObject *obj);
        virtual ~KPythonTuple();

        ValueRef Get(const char *name);
        void Set(const char *name, ValueRef value);
        virtual bool Equals(TiObjectRef);
        SharedStringList GetPropertyNames();

        unsigned int Size();
        void Append(ValueRef value);
        virtual void SetAt(unsigned int index, ValueRef value);
        bool Remove(unsigned int index);
        ValueRef At(unsigned int index);

        PyObject* ToPython();

    protected:
        PyObject *tuple;
        AutoPtr<KPythonObject> object;
        DISALLOW_EVIL_CONSTRUCTORS(KPythonTuple);
    };
}

#endif
