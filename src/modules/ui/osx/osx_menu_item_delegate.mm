/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "../ui_module.h"
@implementation OSXMenuItemDelegate
-(id)initWithMenuItem:(ti::OSXMenuItem*)inMenuItem
{
    if ([super init]) {
        menuItem = inMenuItem;
    }
    return self;
}

-(void)dealloc
{
    menuItem = nil;
    [super dealloc];
}

-(void)invoke:(id)sender
{
    menuItem->HandleClickEvent(NULL);
}

-(ti::OSXMenuItem*)getMenuItem
{
    return menuItem;
}
@end

