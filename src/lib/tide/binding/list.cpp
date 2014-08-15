/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "../tide.h"
#include <sstream>
#include <cmath>
#include <climits>

namespace tide
{

    void TiList::ResizeTo(unsigned int size)
    {
        if (size < 0 || size == this->Size())
        {
            return;
        }

        while (size < this->Size())
        {
            this->Remove(this->Size() - 1);
        }

        while (size > this->Size())
        {
            this->Append(Value::Undefined);
        }
    }

    SharedString TiList::DisplayString(int levels)
    {
        std::ostringstream oss;
        oss << "(" << this->GetType() << ")" << " [";
        for (unsigned int i = 0; i < this->Size(); i++)
        {
            ValueRef list_val = this->At(i);
            SharedString list_str = list_val->DisplayString(levels-1);
            oss << " " << *list_str << ",";
        }
        //int before_last_comma = oss.tellp() - 1;
        //oss.seekp(before_last_comma);
        oss << " ]";

        return new std::string(oss.str());
    }

    /*static*/
    std::string TiList::IntToChars(unsigned int value)
    {
        std::stringstream ss;
        ss << value;
        return ss.str();
    }

    /*static*/
    bool TiList::IsInt(const std::string& name)
    {
        for (size_t i = 0; i < strlen(name.c_str()); i++)
        {
            if (!isdigit(name[i]))
                return false;
        }
        return true;
    }

    /*static*/
    unsigned int TiList::ToIndex(const std::string& str)
    {
        char* endPointer = 0;
        unsigned long result = strtoul(str.c_str(), &endPointer, 10);

        if ((endPointer == str.c_str() && result == 0) || result > UINT_MAX)
        {
            throw ValueException::FromFormat("Could not convert %s to an unsigned int",
                str.c_str());
        }

        return result;
    }

    /*static*/
    TiListRef TiList::Unwrap(TiListRef o)
    {
        AutoPtr<ProfiledBoundList> plist = o.cast<ProfiledBoundList>();
        if (plist.isNull())
        {
            return o;
        }
        else
        {
            return plist->GetDelegate();
        }
    }
}
