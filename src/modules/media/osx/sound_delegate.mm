/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#import "sound_delegate.h"
#import "osx_sound.h"

@implementation SoundDelegate

-(void)setOSXSound:(OSXSound*)newSound
{
    sound = newSound;
}

-(void)dealloc
{
    sound = nil;
    [super dealloc];
}

-(void)completed:(id) unused
{
    if (sound)
        sound->SoundCompletedIteration();
}

-(void)sound:(NSSound*)s didFinishPlaying:(BOOL)finished
{
    if (finished)
    {
        [self performSelectorOnMainThread:@selector(completed:)
            withObject:nil waitUntilDone:NO];
    }
}

@end
