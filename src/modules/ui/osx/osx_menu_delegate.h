/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

@interface OSXMenuDelegate : NSObject <NSMenuDelegate>
{
    ti::OSXMenu* menu;
    BOOL dirty;
    BOOL registerNative;
}
- (id)initWithMenu:(ti::OSXMenu*)menu willRegister:(BOOL)willRegister;
- (NSInteger)numberOfItemsInMenu:(NSMenu *)menu;
- (void)menuNeedsUpdate:(NSMenu *)menu;
- (void)markAsDirty;
@end
