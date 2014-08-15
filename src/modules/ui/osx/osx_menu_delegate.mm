/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#import "../ui_module.h"

@implementation OSXMenuDelegate

- (id)initWithMenu:(ti::OSXMenu*)inMenu willRegister:(BOOL)willRegister
{
    if ([super init]) {
        dirty = YES;
        menu = inMenu;
        registerNative = willRegister;
    }
    return self;
}

- (NSInteger)numberOfItemsInMenu:(NSMenu *)menu
{
    // We will setup the menu in menuNeedsUpdate.
    return -1;
}

- (void)menuNeedsUpdate:(NSMenu *)nativeMenu
{
    if (!dirty) {
        return;
    }

    dirty = NO;
    OSXMenu::ClearNativeMenu(nativeMenu);
    menu->AddChildrenToNativeMenu(nativeMenu, registerNative ? true : false);
}

- (void)markAsDirty
{
    dirty = YES;
}
@end

