/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#import <Foundation/Foundation.h>
#import <Growl/Growl.h>
#include <string>

@interface growlWrapper : NSObject <GrowlApplicationBridgeDelegate>

void showGrowlMessage(NSInteger priority, NSString *title, NSString *desc, CFDataRef icon);

@end
