/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _MONKEY_BINDING_H_
#define _MONKEY_BINDING_H_
#include <tide/tide.h>
#include <vector>

namespace ti
{
    struct Script
    {
        public:
        std::vector<std::string> includes;
        std::vector<std::string> excludes;
        std::string source;
        bool Matches(std::string& url);
        static bool Matches(std::vector<std::string>&, std::string& url);
        static bool Matches(const char* pattern, const char* target);
    };

    class MonkeyBinding : public tide::StaticBoundObject
    {
        public:
        MonkeyBinding(Host*, TiObjectRef);

        protected:
        virtual ~MonkeyBinding();
        void ParseFile(string filePath);
        void Callback(const ValueList &args, ValueRef result);
        void EvaluateUserScript(
            TiObjectRef, std::string&,TiObjectRef, std::string&);

        TiObjectRef global;
        Logger* logger;
        TiMethodRef callback;
        std::vector<Script*> scripts;
    };
}

#endif
