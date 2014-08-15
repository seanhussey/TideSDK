/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _FUNCTION_PTR_METHOD_H_
#define _FUNCTION_PTR_METHOD_H_

namespace tide
{
    typedef ValueRef (*KFunctionPtrCallback) (const ValueList& args);
    class TIDE_API FunctionPtrMethod : public TiMethod
    {
        public:
        FunctionPtrMethod(KFunctionPtrCallback);
        virtual ~FunctionPtrMethod();

        /**
         * @see TiMethod::Call
         */
        virtual ValueRef Call(const ValueList& args);

        /**
         * @see TiObject::Set
         */
        virtual void Set(const char *name, ValueRef value);

        /**
         * @see TiObject::Get
         */
        virtual ValueRef Get(const char *name);

        /**
         * @see TiObject::GetPropertyNames
         */
        virtual SharedStringList GetPropertyNames();
        

        protected:
        KFunctionPtrCallback callback;
        TiObjectRef object;

        private:
        DISALLOW_EVIL_CONSTRUCTORS(FunctionPtrMethod);
    };
}

#endif
