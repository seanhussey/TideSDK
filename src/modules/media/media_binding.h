/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _MEDIA_BINDING_H_
#define _MEDIA_BINDING_H_

#include <tide/tide.h>
#include <map>
#include <vector>
#include <string>

namespace ti
{
    class MediaBinding : public StaticBoundObject
    {
        public:
        MediaBinding(TiObjectRef);

        protected:
        virtual ~MediaBinding();

        private:
        TiObjectRef global;
        void _CreateSound(const ValueList& args, ValueRef result);
        void _Beep(const ValueList& args, ValueRef result);

        virtual TiObjectRef CreateSound(std::string& url) = 0;
        virtual void Beep() = 0;
    };
}

#endif
