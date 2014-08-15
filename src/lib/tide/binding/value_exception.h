/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _VALUE_EXCEPTION_H_
#define _VALUE_EXCEPTION_H_

#include <vector>
#include <string>
#include <map>

namespace tide
{

#ifndef OS_WIN32
    #pragma GCC visibility push(default)
#endif

    class TIDE_API ValueException : public std::exception
    {
        public:
        ValueException(ValueRef v);
        ~ValueException() throw ();

        public:
        static ValueException FromString(const char* s);
        static ValueException FromString(std::string s);
        static ValueException FromFormat(const char* format, ...);
        static ValueException FromObject(TiObjectRef o);
        ValueRef GetValue();
        SharedString DisplayString();
        std::string& ToString();

        private:
        ValueRef value;
        std::string displayString;
    };

#ifndef OS_WIN32
    #pragma GCC visibility pop
#endif
}

#endif
