/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _DATABASE_BINDING_H_
#define _DATABASE_BINDING_H_

#include <tide/tide.h>
#include "webkit_databases.h"
#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>

namespace ti
{
    class DatabaseBinding : public AccessorObject
    {
    public:
        DatabaseBinding(std::string& name, bool isWebKitDatabase);

    protected:
        virtual ~DatabaseBinding();
        void Open(const ValueList& args, ValueRef result);
        void Execute(const ValueList& args, ValueRef result);
        void Close(const ValueList& args, ValueRef result);
        void Remove(const ValueList& args, ValueRef result);
        void GetPath(const ValueList& args, ValueRef result);
        void Close();

        Poco::Data::Session *session;
        std::string name;
        std::string path;
        bool isWebKitDatabase;
    };
}

#endif
