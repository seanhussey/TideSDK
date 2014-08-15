/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PROFILED_BOUND_METHOD_H_
#define _PROFILED_BOUND_METHOD_H_

namespace tide
{
    /**
     * The ProfiledBoundMethod is a wrapped TiMethod that does profiling
     */
    class ProfiledBoundMethod : public ProfiledBoundObject, public TiMethod
    {
    public:
        ProfiledBoundMethod(TiMethodRef delegate, std::string& parentType);
        virtual ~ProfiledBoundMethod();

        // @see TiMethod::Call
        virtual ValueRef Call(const ValueList& args);
        // @see TiMethod::Set
        virtual void Set(const char *name, ValueRef value);
        // @see TiMethod::Get
        virtual ValueRef Get(const char *name);
        // @see TiMethod::GetPropertyNames
        virtual SharedStringList GetPropertyNames();
        // @see TiObject::GetType
        virtual std::string& GetType();

        bool HasProperty(const char* name);

        /**
         * @return the delegate of this profiled bound method
         */
        TiMethodRef GetDelegate() { return method; }
        virtual void duplicate()
        {
            ++count;
        }

        virtual void release()
        {
            int value = --count;
            if (value <= 0) {
                delete this;
            }
        }

        virtual int referenceCount() const
        {
            return count.value();
        }

    private:
        TiMethodRef method;
        std::string fullType;
        Poco::AtomicCounter count;

    };
}

#endif
