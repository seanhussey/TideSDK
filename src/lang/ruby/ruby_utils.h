/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef RUBY_TYPES_H_
#define RUBY_TYPES_H_

#include <typeinfo>
#include "ruby_module.h"

namespace tide
{
    class RubyUtils
    {
    public:
        static ValueRef ToTiValue(VALUE value);
        static VALUE ToRubyValue(ValueRef value);
        static VALUE TiObjectToRubyValue(ValueRef value);
        static VALUE TiMethodToRubyValue(ValueRef value);
        static VALUE TiListToRubyValue(ValueRef value);
        static bool KindOf(VALUE value, VALUE klass);

        static ValueException GetException();
        static VALUE GenericTiMethodCall(TiMethodRef method, VALUE args);

    private:
        static VALUE TiObjectClass;
        static VALUE TiMethodClass;
        static VALUE TiListClass;
        RubyUtils(){}
        ~RubyUtils(){}
    };
}

#endif
