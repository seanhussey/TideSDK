/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _MEDIA_OSX_SOUND_H_
#define _MEDIA_OSX_SOUND_H_

#include <tide/tide.h>
#include <vector>
#include "../sound.h"
#import <Cocoa/Cocoa.h>

using namespace tide;

namespace ti
{
    class OSXSound : public Sound
    {
        public:
        OSXSound(std::string& url);
        virtual ~OSXSound();
        virtual void LoadImpl();
        virtual void UnloadImpl();
        virtual void PlayImpl();
        virtual void PauseImpl();
        virtual void StopImpl();
        virtual void SetVolumeImpl(double volume);
        virtual double GetVolumeImpl();

        private:
        NSSound* sound;
        id delegate;
        NSURL* fileURL;
    };
}

#endif
