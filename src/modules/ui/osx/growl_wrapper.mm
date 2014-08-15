/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#import "growl_wrapper.h"

@implementation growlWrapper

// Register for Growl using tiGrowl as the application name
// TODO: Make it so the application name is the name of the application, rather then tiGrowl
-(NSDictionary *)registrationDictionaryForGrowl {
    NSArray *notifications = [NSArray arrayWithObject:@"tiGrowl"];
    return [NSDictionary dictionaryWithObjectsAndKeys: @"tiGrowl", GROWL_APP_ID, @"tiGrowl", GROWL_APP_NAME, notifications, GROWL_NOTIFICATIONS_ALL, notifications, GROWL_NOTIFICATIONS_DEFAULT, nil];
}

// Function to show growl notification
void showGrowlMessage(NSInteger priority, NSString *title, NSString *desc, CFDataRef iconData)
{
    growlWrapper *growlDelegate;
    growlDelegate = [[growlWrapper alloc] init];
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

    NSData *icon = (NSData *)iconData;

    [GrowlApplicationBridge setGrowlDelegate:growlDelegate];
    [GrowlApplicationBridge notifyWithTitle: title
                                description: desc
                           notificationName: @"tiGrowl"
                                   iconData:icon
                                   priority:priority
                                   isSticky:NO
                               clickContext:nil];
    // TODO: Memory check, make sure this is being released properly and there isn't any memory leaks
    [pool drain];
}

@end
