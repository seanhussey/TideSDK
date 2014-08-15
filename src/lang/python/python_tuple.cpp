/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "python_list.h"

namespace tide
{
    KPythonTuple::KPythonTuple(PyObject *tuple) :
        TiList("Python.KPythonTuple"),
        tuple(tuple),
        object(new KPythonObject(tuple, true))
    {
        PyLockGIL lock;
        Py_INCREF(this->tuple);
    }

    KPythonTuple::~KPythonTuple()
    {
        PyLockGIL lock;
        Py_DECREF(this->tuple);
    }

    void KPythonTuple::Append(ValueRef value)
    {
        throw ValueException::FromString("Cannot modify the size of a Python tuple.");
    }

    unsigned int KPythonTuple::Size()
    {
        PyLockGIL lock;
        return PyTuple_Size(this->tuple);
    }

    bool KPythonTuple::Remove(unsigned int index)
    {
        throw ValueException::FromString("Cannot modify the size of a Python tuple.");
        return false;
    }

    ValueRef KPythonTuple::At(unsigned int index)
    {
        PyLockGIL lock;
        if (index >= 0 && index < this->Size())
        {
            PyObject *p = PyTuple_GetItem(this->tuple, index);
            ValueRef v = PythonUtils::ToTiValue(p);
            return v;
        }
        else
        {
            return Value::Undefined;
        }
    }

    void KPythonTuple::Set(const char *name, ValueRef value)
    {
        throw ValueException::FromString("Cannot modify a Python tuple.");
    }

    void KPythonTuple::SetAt(unsigned int index, ValueRef value)
    {
        throw ValueException::FromString("Cannot modify a Python tuple.");
    }

    ValueRef KPythonTuple::Get(const char *name)
    {
        if (TiList::IsInt(name))
        {
            return this->At(TiList::ToIndex(name));
        }
        else
        {
            return object->Get(name);
        }
    }

    SharedStringList KPythonTuple::GetPropertyNames()
    {
        SharedStringList property_names = object->GetPropertyNames();
        for (size_t i = 0; i < this->Size(); i++)
        {
            std::string name = TiList::IntToChars(i);
            property_names->push_back(new std::string(name));
        }
        return property_names;
    }

    PyObject* KPythonTuple::ToPython()
    {
        return this->object->ToPython();
    }

    bool KPythonTuple::Equals(TiObjectRef other)
    {
        AutoPtr<KPythonTuple> pyOther = other.cast<KPythonTuple>();
        if (pyOther.isNull())
        {
            return false;
        }
        else
        {
            return pyOther->ToPython() == this->ToPython();
        }
    }
}
