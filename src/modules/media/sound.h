/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _MEDIA_SOUND_H_
#define _MEDIA_SOUND_H_
#include <tide/tide.h>

using namespace tide;

namespace ti
{
    class Sound : public StaticBoundObject
    {
        public:
        Sound(std::string& url);
        virtual ~Sound();

        void Play(const ValueList& args, ValueRef result);
        void Pause(const ValueList& args, ValueRef result);
        void Stop(const ValueList& args, ValueRef result);
        void Reload(const ValueList& args, ValueRef result);
        void SetVolume(const ValueList& args, ValueRef result);
        void GetVolume(const ValueList& args, ValueRef result);
        void SetLooping(const ValueList& args, ValueRef result);
        void IsLooping(const ValueList& args, ValueRef result);
        void IsPlaying(const ValueList& args, ValueRef result);
        void IsPaused(const ValueList& args, ValueRef result);
        void SetOnComplete(const ValueList& args, ValueRef result);

        void Play();
        void Pause();
        void Stop();
        void Reload();
        void SetVolume(double newVolume);
        double GetVolume();
        void SetLooping(bool newLooping);
        bool IsLooping();
        bool IsPlaying();
        bool IsPaused();
        void SetOnComplete(TiMethodRef newCallback);
        void Load();
        void Unload();
        void SoundCompletedIteration();

        virtual void LoadImpl() = 0;
        virtual void UnloadImpl() = 0;
        virtual void PlayImpl() = 0;
        virtual void PauseImpl() = 0;
        virtual void StopImpl() = 0;
        virtual void SetVolumeImpl(double volume) = 0;
        virtual double GetVolumeImpl() = 0;;

        protected:
        enum SoundState { PLAYING, PAUSED, STOPPED, END_OF_ITERATION };
        SoundState state;
        std::string url;
        std::string path;
        TiMethodRef callback;
        bool looping;
    };
}

#endif
