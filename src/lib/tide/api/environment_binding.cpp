/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "environment_binding.h"
#include <tideutils/environment_utils.h>

namespace tide
{
    ValueRef EnvironmentBinding::Get(const char *name)
    {
        return Value::NewString(EnvironmentUtils::Get(name));
    }
    
    SharedStringList EnvironmentBinding::GetPropertyNames()
    {
        std::map<std::string, std::string> env = EnvironmentUtils::GetEnvironment();
        SharedStringList keys = new StringList();
        
        std::map<std::string, std::string>::iterator iter = env.begin();
        for (; iter != env.end(); iter++)
        {
            keys->push_back(new std::string(iter->first));
        }
        return keys;
    }
    
    void EnvironmentBinding::Set(const char *name, ValueRef value)
    {
        if (value->IsString())
        {
            EnvironmentUtils::Set(name, value->ToString());
        }
    }
    
    SharedString EnvironmentBinding::DisplayString(int levels)
    {
        std::map<std::string, std::string> env = EnvironmentUtils::GetEnvironment();
        std::map<std::string, std::string>::iterator iter = env.begin();
        SharedString str = new std::string();
        
        for (; iter != env.end(); iter++)
        {
            (*str) += iter->first + "=" + iter->second + ",";
        }
        return str;
    }
}
