/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _MODULE_PROVIDER_H_
#define _MODULE_PROVIDER_H_
#include <string>

namespace tide
{
    class Module;
    class Host;

    typedef Module* ModuleCreator(const Host *host, const char *path);

    /**
     * Module Provider implementations are responsible for determining if a file
     * contains a supportable module, and for constructing them if they
     * determine that the file is supported.
     *
     * In general, module providers will be a part of the system, but they are meant
     * as a way to provide extension points to 3rd party languages such as Python, Ruby, etc.
     *
     * Currently any language supported by Tide includes it's own ModuleProvider
     */
    class EXPORT ModuleProvider
    {
    public:
        ModuleProvider() {}
        virtual ~ModuleProvider() {};

        /**
         * @param filename an absolute path to a file in the filesystem
         * @return if the passed-in absolute file path is a supported module or not
         */
        virtual bool IsModule(std::string& filename) = 0;

        /**
         * Create a module based on a path that was signified as "supported" by
         * ModuleProvider::IsModule. Most implementations will load this file into
         * their interpreter, or dynamically load it's contents in some way.
         *
         * @param path an absolute path to a module file in the filesystem
         * @return The module that represents this path.
         */
        virtual Module* CreateModule(std::string& path) = 0;
    };
}

#endif
