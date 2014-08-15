/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#import "../ui_module.h"

@implementation OSXTrayItemDelegate
-(id)initWithTray:(OSXTrayItem*)inTrayItem
{
    trayItem = inTrayItem;
    self = [super init];
    return self;
}
-(void)dealloc
{
    [super dealloc];
}
-(void)invoke:(id)sender
{
    trayItem->InvokeCallback();
}
@end
