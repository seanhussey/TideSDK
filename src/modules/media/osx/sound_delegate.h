/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#import <Cocoa/Cocoa.h>
#import "osx_sound.h"

using namespace ti;

@interface SoundDelegate : NSObject
{
    OSXSound* sound;
}
-(void)setOSXSound:(OSXSound*)sound;
-(void)dealloc;
@end
