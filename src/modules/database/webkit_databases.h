/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef TI_DATABASES_H
#define TI_DATABASES_H

#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>

namespace ti
{
    /**
     * Databases is a convenience class for handling WebKit compatible databases
     */
    class WebKitDatabases
    {
    public:
        WebKitDatabases();
        virtual ~WebKitDatabases();

        /**
         * returns true if database for origin exists, false if not found
         */
        bool Exists(std::string name);

        /**
         * return the path to an existing database with origin and name
         */
        std::string Path(std::string name);

        /**
         * create a new database with name for origin
         */
        std::string Create(std::string name);

        /**
         * delete an existing database for name and origin
         */
        void Delete(std::string name);

    private:
        std::string origin;
        std::string originPath;
        Poco::Data::Session* session;
    };
}

#endif
