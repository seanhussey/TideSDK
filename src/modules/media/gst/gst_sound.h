/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _TI_MEDIA_GST_SOUND_H_
#define _TI_MEDIA_GST_SOUND_H_

#include <tide/tide.h>
#include <vector>

using namespace tide;

namespace ti
{
    class GstSound;
    typedef AutoPtr<GstSound> SharedGstSound;

    class GstSound : public Sound
    {
    public:
        GstSound(std::string& url);
        virtual void LoadImpl();
        virtual void UnloadImpl();
        virtual void PlayImpl();
        virtual void PauseImpl();
        virtual void StopImpl();
        virtual void SetVolumeImpl(double volume);
        virtual double GetVolumeImpl();

    private:
        GstElement* pipeline;
        guint watchEventSourceId;
        std::string fileURL;
    };
}

#endif
