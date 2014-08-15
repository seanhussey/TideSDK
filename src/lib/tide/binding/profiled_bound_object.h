/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PROFILED_BOUND_OBJECT_H_
#define _PROFILED_BOUND_OBJECT_H_
#include <Poco/FileStream.h>
#include <Poco/Mutex.h>

namespace tide
{
    /**
     * The ProfiledBoundObject is a wrapped TiObject that does profiling on a 
     * wrapped TiObject
     */
    class TIDE_API ProfiledBoundObject : public TiObject
    {
        public:
        ProfiledBoundObject(TiObjectRef delegate);
        virtual ~ProfiledBoundObject();
        static void SetStream(Poco::FileOutputStream*);

        public:
        // @see TiObject::Set
        virtual void Set(const char *name, ValueRef value);
        // @see TiObject::Get
        virtual ValueRef Get(const char *name);
        // @see TiObject::GetPropertyNames
        virtual SharedStringList GetPropertyNames();
        // @see TiObject::DisplayString
        virtual SharedString DisplayString(int levels=3);
        // @see TiObject::Equals
        virtual bool Equals(TiObjectRef other);

        bool HasProperty(const char* name);

        /**
         * @return the delegate of this profiled bound object
         */
        TiObjectRef GetDelegate() { return delegate; }
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

    protected:
        TiObjectRef delegate;
        ValueRef Wrap(ValueRef value, std::string type);
        std::string GetSubType(std::string name);
        void Log(const char* eventType, std::string& name, Poco::Timestamp::TimeDiff);
        static bool AlreadyWrapped(ValueRef);
        static Poco::FileOutputStream *stream;
        static Poco::Mutex logMutex;
        Poco::AtomicCounter count;
    };
}

#endif
