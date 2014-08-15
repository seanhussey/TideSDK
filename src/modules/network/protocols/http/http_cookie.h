/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _HTTP_COOKIE_H_
#define _HTTP_COOKIE_H_

#include <tide/tide.h>
#include <Poco/Net/HTTPCookie.h>

namespace ti
{
    class HTTPCookie : public AccessorObject
    {
    public:
        HTTPCookie();
        HTTPCookie(Poco::Net::HTTPCookie& cookie);
        void InitializeBinding();

        void GetName(const ValueList& args, ValueRef result);
        void SetName(const ValueList& args, ValueRef result);
        void GetValue(const ValueList& args, ValueRef result);
        void SetValue(const ValueList& args, ValueRef result);
        void GetVersion(const ValueList& args, ValueRef result);
        void SetVersion(const ValueList& args, ValueRef result);
        void GetDomain(const ValueList& args, ValueRef result);
        void SetDomain(const ValueList& args, ValueRef result);
        void GetPath(const ValueList& args, ValueRef result);
        void SetPath(const ValueList& args, ValueRef result);
        void GetMaxAge(const ValueList& args, ValueRef result);
        void SetMaxAge(const ValueList& args, ValueRef result);
        void GetComment(const ValueList& args, ValueRef result);
        void SetComment(const ValueList& args, ValueRef result);
        void IsHTTPOnly(const ValueList& args, ValueRef result);
        void SetHTTPOnly(const ValueList& args, ValueRef result);
        void IsSecure(const ValueList& args, ValueRef result);
        void SetSecure(const ValueList& args, ValueRef result);
        void ToString(const ValueList& args, ValueRef result);

        SharedString DisplayString(int levels);

    private:
        Poco::Net::HTTPCookie cookie;
    };
}

#endif
