/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _REFERENCE_COUNTED_H_
#define _REFERENCE_COUNTED_H_

namespace tide
{
    class TIDE_API ReferenceCounted
    {
        private:
        Poco::AtomicCounter count;

        public:
        ReferenceCounted() : count(1) { }
        virtual ~ReferenceCounted() { }

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
    };
}

#endif
