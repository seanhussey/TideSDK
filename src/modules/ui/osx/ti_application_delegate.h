/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef TI_APP_H
#define TI_APP_H
#import "../ui_module.h"
@interface TideSDKApplicationDelegate : NSObject <NSApplicationDelegate>
{
    ti::OSXUIBinding *binding;
}

-(id)initWithBinding:(ti::OSXUIBinding*)binding;
-(BOOL)application:(NSApplication*)theApplication openFile:(NSString*)filename;
-(BOOL)application:(NSApplication*)theApplication openFiles:(NSArray*)filenames;
-(NSApplicationTerminateReply) applicationShouldTerminate:(NSApplication*)sender;
@end

#endif
