/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _MEDIA_WIN32_SOUND_H_
#define _MEDIA_WIN32_SOUND_H_

#include <tide/tide.h>
#include <vector>
#include <dshow.h>
#include "../sound.h"

using namespace tide;

namespace ti
{
    class Win32Sound : public Sound
    {
        public:
        Win32Sound(std::string& url);
        virtual ~Win32Sound();
        virtual void LoadImpl();
        virtual void UnloadImpl();
        virtual void PlayImpl();
        virtual void PauseImpl();
        virtual void StopImpl();
        virtual void SetVolumeImpl(double volume);
        virtual double GetVolumeImpl();

        static UINT graphNotifyMessage;
        bool GraphCallback(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
        static bool StaticGraphCallback(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

        private:
        std::wstring widePath;
        IGraphBuilder* graphBuilder;
        IMediaControl* mediaControl;
        IMediaEventEx* mediaEventEx;
        IMediaSeeking* mediaSeeking;
        IBasicAudio* basicAudio;
    };
}

#endif
