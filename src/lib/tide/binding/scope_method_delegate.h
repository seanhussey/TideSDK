/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _SCOPE_METHOD_DELEGATE_H_
#define _SCOPE_METHOD_DELEGATE_H_

namespace tide {

    enum MethodDelegateType
    {
        GET, /**< Getter method */
        SET /**< Setter method */
    };

    /**
     * class that can be used to change the delegation of a method
     * call's Get or Set method to first check to see if the key has
     * namespace dots (such as ti.foo.bar) and if so, delegate to a
     * differently supplied scope object for delegation.
     */
    class TIDE_API ScopeMethodDelegate : public TiMethod
    {
    
    public:
        ScopeMethodDelegate(MethodDelegateType type, TiObjectRef global,
                            TiObjectRef scope, TiMethodRef delegate);
        virtual ~ScopeMethodDelegate();


        void Set(const char *name, ValueRef value);
        ValueRef Get(const char *name);
        SharedStringList GetPropertyNames();


        bool IsGlobalKey(std::string& key);
        ValueRef Call(const ValueList& args);

        /**
         * create a delegate from a TiObject to a wrapped
         * StaticBoundObject and delegate set/get to the new
         * static bound object
         */
        static AutoPtr<StaticBoundObject> CreateDelegate(TiObjectRef global, TiObjectRef bo);

    private:
        MethodDelegateType type;
        TiObjectRef global;
        TiObjectRef scope;
        TiMethodRef delegate;

    private:
        DISALLOW_EVIL_CONSTRUCTORS(ScopeMethodDelegate);
    };

}

#endif
