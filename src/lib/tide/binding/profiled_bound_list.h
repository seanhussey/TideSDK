/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PROFILED_BOUND_LIST_H_
#define _PROFILED_BOUND_LIST_H_

namespace tide
{
    /**
     * The ProfiledBoundList is a wrapped TiList that does profiling
     */
    class ProfiledBoundList : public ProfiledBoundObject, public TiList
    {
    public:
        ProfiledBoundList(TiListRef delegate);
        virtual ~ProfiledBoundList();

        // @see TiList::Append
        virtual void Append(ValueRef value);
        // @see TiList::Size
        virtual unsigned int Size();
        // @see TiList::At
        virtual ValueRef At(unsigned int index);
        // @see TiList::SetAt
        virtual void SetAt(unsigned int index, ValueRef value);
        // @see TiList::Remove
        virtual bool Remove(unsigned int index);
        // @See TiList::Set
        virtual void Set(const char *name, ValueRef value);
        // @see TiList::Get
        virtual ValueRef Get(const char *name);
        // @see TiList::GetPropertyNames
        virtual SharedStringList GetPropertyNames();

        bool HasProperty(const char* name);

        /**
         * @return the delegate of this profiled bound object
         */
        TiListRef GetDelegate() { return list; }
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
        TiListRef list;
        Poco::AtomicCounter count;

    };
}

#endif
