/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#import <Cocoa/Cocoa.h>
#import <AppKit/AppKit.h>
#import "../ui_module.h"
#import "osx_ui_binding.h"
#import "osx_menu_item.h"

@implementation TideSDKApplicationDelegate

- (NSMenu *)applicationDockMenu:(NSApplication *)sender
{
    AutoPtr<OSXMenu> menu = binding->GetDockMenu().cast<OSXMenu>();
    if (!menu.isNull()) {
        NSMenu* nativeMenu = menu->CreateNativeNow(false);
        return nativeMenu;
    } else {
        return nil;
    }
}

- (id)initWithBinding:(ti::OSXUIBinding*)b
{
    self = [super init];
    if (self)
    {
        binding = b;
    }
    return self;
}

-(BOOL)application:(NSApplication*)theApplication openFile:(NSString*)filename
{
    AutoPtr<GlobalObject> globalObject(GlobalObject::GetInstance());
    AutoPtr<Event> event(globalObject->CreateEvent(Event::OPEN_REQUEST));

    TiListRef files(new StaticBoundList());
    files->Append(Value::NewString([filename UTF8String]));
    event->SetList("files", files);

    globalObject->FireEvent(event);
    return YES;
}

-(BOOL)application:(NSApplication*)theApplication openFiles:(NSArray*)filenames
{
    AutoPtr<GlobalObject> globalObject(GlobalObject::GetInstance());
    AutoPtr<Event> event(globalObject->CreateEvent(Event::OPEN_REQUEST));

    TiListRef files(new StaticBoundList());

    int arrayCount = [filenames count];
    for (int i = 0; i < arrayCount; i++)
    {
        files->Append(Value::NewString(
            [[filenames objectAtIndex:i] UTF8String]));
    }
    event->SetList("files", files);

    globalObject->FireEvent(event);
    return YES;
}

-(BOOL) applicationShouldHandleReopen:(NSApplication*)theApplication hasVisibleWindows:(BOOL)visibleWindows
{
    // Allow application to handle the dock click event in a custom way.
    AutoPtr<EventObject> target = GlobalObject::GetInstance();
    AutoPtr<Event> event = target->CreateEvent(Event::REOPEN);
    event->SetBool("hasVisibleWindows", visibleWindows);
    return target->FireEvent(event) ? YES : NO;
}

-(NSApplicationTerminateReply) applicationShouldTerminate:(NSApplication*)sender
{
    binding->GetHost()->Exit(0);
    return NO;
}

@end
