/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "media_binding.h"
#include <tide/tide.h>
#include <cstring>

namespace ti
{
    MediaBinding::MediaBinding(TiObjectRef global) :
        StaticBoundObject("Media"),
        global(global)
    {
        /**
         * @tiapi(method=True,name=Media.createSound,since=0.2) Creates a sound object
         * @tiarg(for=Media.createSound,name=path,type=String) path or url to the sound file
         * @tiresult(for=Media.createSound,type=Media.Sound) a Sound object
         */
        this->SetMethod("createSound", &MediaBinding::_CreateSound);
        /**
         * @tiapi(method=True,name=Media.beep,since=0.2) Causes the system to beep
         */
        this->SetMethod("beep", &MediaBinding::_Beep);
    }

    MediaBinding::~MediaBinding()
    {
    }

    void MediaBinding::_CreateSound(const ValueList& args, ValueRef result)
    {
        if (args.size()!=1)
            throw ValueException::FromString("createSound takes 1 parameter");

        std::string path(args.at(0)->ToString());
        result->SetObject(this->CreateSound(path));
    }

    void MediaBinding::_Beep(const ValueList& args, ValueRef result)
    {
        this->Beep();
    }
}
