/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PHP_METHOD_H_
#define _PHP_METHOD_H_

namespace tide
{
    class KPHPMethod : public TiMethod
    {
        public:
        KPHPMethod(zval* object, const char* methodName);
        KPHPMethod(const char *functionName);

        virtual ~KPHPMethod();
        ValueRef Call(const ValueList& args);
        virtual void Set(const char *name, ValueRef value);
        virtual ValueRef Get(const char *name);
        virtual SharedStringList GetPropertyNames();
        virtual SharedString DisplayString(int);
        virtual bool Equals(TiObjectRef);
        bool PropertyExists(const char* property);
        zval* ToPHP();

        private:
        zval* object;
        char* methodName;
        zval* zMethodName;
        TiObjectRef globalObject;
    };
}

#endif
