/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _READ_EVENT_H_
#define _READ_EVENT_H_

namespace tide
{
    class TIDE_API ReadEvent : public Event
    {
    public:
        ReadEvent(AutoPtr<EventObject> target, BytesRef);
        void _GetData(const ValueList&, ValueRef result);

    protected:
        BytesRef data;
    };
}

#endif
