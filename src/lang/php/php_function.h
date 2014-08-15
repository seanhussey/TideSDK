/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PHP_FUNCTION_H_
#define _PHP_FUNCTION_H_

namespace tide
{
    class KPHPFunction : public TiMethod
    {
        public:
        KPHPFunction(const char *functionName);

        virtual ~KPHPFunction();
        ValueRef Call(const ValueList& args);
        virtual void Set(const char *name, ValueRef value);
        virtual ValueRef Get(const char *name);
        virtual SharedStringList GetPropertyNames();
        virtual SharedString DisplayString(int);
        virtual bool Equals(TiObjectRef);
        bool PropertyExists(const char* property);

        inline std::string& GetMethodName() { return methodName; }

        private:
        std::string methodName;
        zval* zMethodName;
        TiObjectRef globalObject;
    };
}

#endif
