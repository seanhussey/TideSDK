/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "../tide.h"
namespace tide
{
    ReadEvent::ReadEvent(AutoPtr<EventObject> target, BytesRef data) :
        Event(target, Event::READ),
        data(data)
    {
        this->SetMethod("getData", &ReadEvent::_GetData);
    }

    void ReadEvent::_GetData(const ValueList&, ValueRef result)
    {
        result->SetObject(this->data);
    }
}
