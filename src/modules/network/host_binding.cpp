/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "host_binding.h"

namespace ti
{
    HostBinding::HostBinding(IPAddress addr) :
        StaticBoundObject("Network.Host"),
        name(addr.toString())
    {
        this->Init();
        try
        {
            this->host = DNS::hostByAddress(addr);
        }
        catch (HostNotFoundException&)
        {
            this->invalid = true;
            //TODO: improve this exception so we can properly raise
        }
        catch (NoAddressFoundException&)
        {
            this->invalid = true;
            //TODO: improve this exception so we can properly raise
        }
    }
    HostBinding::HostBinding(std::string name) : StaticBoundObject("Host"), name(name)
    {
        this->Init();
        try
        {
            this->host = DNS::hostByName(name.c_str());
        }
        catch (HostNotFoundException&)
        {
            this->invalid = true;
            //TODO: improve this exception so we can properly raise
        }
        catch (NoAddressFoundException&)
        {
            this->invalid = true;
            //TODO: improve this exception so we can properly raise
        }
    }
    HostBinding::~HostBinding()
    {
        TIDE_DUMP_LOCATION
    }
    void HostBinding::Init() 
    {
        this->invalid = false;
        /**
         * @tiapi(method=True,name=Network.Host.toString,since=0.2) Returns a string representation of a Host object
         * @tiresult(for=Network.Host.toString,type=String) the string representation of the Host object
         */
        this->SetMethod("toString",&HostBinding::ToString);
        /**
         * @tiapi(method=True,name=Network.Host.isInvalid,since=0.2) Checks whether the Host object is invalid
         * @tiresult(for=Network.Host.isInvalid,type=Boolean) true if the Host object is invalid, false if otherwise
         */
        this->SetMethod("isInvalid",&HostBinding::IsInvalid);
        /**
         * @tiapi(method=True,name=Network.Host.getName,since=0.2) Return the hostname of a Host object
         * @tiresult(for=Network.Host.getName,type=String) the hostname of the Host object
         */
        this->SetMethod("getName",&HostBinding::GetName);
        /**
         * @tiapi(method=True,name=Network.Host.getAliases,since=0.2) Returns the list of aliases for a Host object
         * @tiresult(for=Network.Host.getAliases,type=Array<String>) a list of aliases for the Host object
         */
        this->SetMethod("getAliases",&HostBinding::GetAliases);
        /**
         * @tiapi(method=True,name=Network.Host.getAddresses,since=0.2) Returns the list of address for a Host object
         * @tiresult(for=Network.Host.getAddresses,type=Array<Network.IPAddress>) a list of aliases for the Host object
         */
        this->SetMethod("getAddresses",&HostBinding::GetAddresses);
    }
    void HostBinding::ToString(const ValueList& args, ValueRef result)
    {
        std::string s("[IPAddress ");
        s+=name;
        s+="]";
        result->SetString(s.c_str());
    }
    void HostBinding::IsInvalid(const ValueList& args, ValueRef result)
    {
        result->SetBool(this->invalid);
    }
    void HostBinding::GetName(const ValueList& args, ValueRef result)
    {
        result->SetString(this->host.name().c_str());
    }
    void HostBinding::GetAliases(const ValueList& args, ValueRef result)
    {
        TiListRef list = new StaticBoundList();
        std::vector<std::string> aliases = this->host.aliases();
        std::vector<std::string>::iterator iter = aliases.begin();
        while (iter!=aliases.end())
        {
            std::string alias = (*iter++);
            list->Append(Value::NewString(alias));
        }
        result->SetList(list);
    }
    void HostBinding::GetAddresses(const ValueList& args, ValueRef result)
    {
        TiListRef list = new StaticBoundList();
        std::vector<IPAddress> addresses = this->host.addresses();
        std::vector<IPAddress>::iterator iter = addresses.begin();
        while (iter!=addresses.end())
        {
            IPAddress address = (*iter++);
            TiObjectRef obj = new IPAddressBinding(address);
            ValueRef addr = Value::NewObject(obj);
            list->Append(addr);
        }
        result->SetList(list);
    }
}
