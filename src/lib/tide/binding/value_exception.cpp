/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "../tide.h"
#include <cstdarg>

namespace tide
{
    ValueException::ValueException(ValueRef v) : std::exception(), value(v)
    {
    }

    ValueException::~ValueException() throw ()
    {
    }

    ValueException ValueException::FromString(const char* s)
    {
        return ValueException(Value::NewString(s));
    }

    ValueException ValueException::FromString(std::string s)
    {
        return ValueException(Value::NewString(s));
    }

    ValueException ValueException::FromFormat(const char* format, ...)
    {

        va_list args;
        va_start(args, format);
        std::string text = Logger::Format(format, args);
        va_end(args);

        return ValueException(Value::NewString(text));
    }

    ValueException ValueException::FromObject(TiObjectRef o)
    {
        return ValueException(Value::NewObject(o));
    }

    ValueRef ValueException::GetValue()
    {
        return this->value;
    }

    SharedString ValueException::DisplayString()
    {
        if (!this->value.isNull())
        {
            return this->value->DisplayString();
        }
        else
        {
            SharedString s = new std::string("<no exception>");
            return s;
        }
    }

    std::string& ValueException::ToString()
    {
        this->displayString = *this->DisplayString();
        return this->displayString;
    }
}
