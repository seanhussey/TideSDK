/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "../tide.h"
#include <sstream>
#include <cmath>

namespace tide
{

    SharedString TiMethod::DisplayString(int levels)
    {
        std::ostringstream oss;
        oss << "<" << this->GetType() << " at " << this << ">";
        return new std::string(oss.str());
    }

    ValueRef TiMethod::Call(TiObjectRef thisObject, const ValueList& args)
    {
        return this->Call(args);
    }

    ValueRef TiMethod::Call()
    {
        return this->Call(ValueList());
    }

    ValueRef TiMethod::Call(const char* one, ValueRef two, ValueRef three,
        ValueRef four)
    {
        ValueList args;
        args.push_back(Value::NewString(one));
        args.push_back(two);
        args.push_back(three);
        args.push_back(four);
        return this->Call(args);
    }

    ValueRef TiMethod::Call(ValueRef one)
    {
        ValueList args;
        args.push_back(one);
        return this->Call(args);
    }

    ValueRef TiMethod::Call(ValueRef one, ValueRef two)
    {
        ValueList args;
        args.push_back(one);
        args.push_back(two);
        return this->Call(args);
    }

    ValueRef TiMethod::Call(ValueRef one, ValueRef two, ValueRef three)
    {
        ValueList args;
        args.push_back(one);
        args.push_back(two);
        args.push_back(three);
        return this->Call(args);
    }

    ValueRef TiMethod::Call(const char* one)
    {
        ValueList args;
        args.push_back(Value::NewString(one));
        return this->Call(args);
    }

    ValueRef TiMethod::Call(const char* one, ValueRef two)
    {
        ValueList args;
        args.push_back(Value::NewString(one));
        args.push_back(two);
        return this->Call(args);
    }

    ValueRef TiMethod::Call(const char* one, ValueRef two, ValueRef three)
    {
        ValueList args;
        args.push_back(Value::NewString(one));
        args.push_back(two);
        args.push_back(three);
        return this->Call(args);
    }

    TiMethodRef TiMethod::Unwrap(TiMethodRef o)
    {
        AutoPtr<ProfiledBoundMethod> pmeth = o.cast<ProfiledBoundMethod>();
        if (pmeth.isNull())
        {
            return o;
        }
        else
        {
            return pmeth->GetDelegate();
        }
    }
}
