/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

@interface OSXMenuItemDelegate : NSObject
{
    ti::OSXMenuItem *menuItem;
}
-(id)initWithMenuItem:(ti::OSXMenuItem*)item;
-(void)invoke:(id)sender;
-(ti::OSXMenuItem*)getMenuItem;
@end
