/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#import "../ui_module.h"
#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>

#ifndef TIDE_LITE
#import <WebKit/WebViewPrivate.h>
#import <WebKit/WebInspector.h>
#import <WebKit/WebScriptDebugDelegate.h>
#import <WebKit/WebScriptObject.h>
#import <WebKit/WebPreferencesPrivate.h>

@class NativeWindow;
@interface WebViewDelegate : NSObject
{
    NativeWindow* window;
    Host* host;
    WebInspector* inspector;
    BOOL initialDisplay;
    std::map<WebFrame*, TiObjectRef>* frameToGlobalObject;
    Logger* logger;
}
-(id)initWithWindow:(NativeWindow*)window;
-(void)setupPreferences;
-(void)registerGlobalObject:(TiObjectRef) globalObject forFrame:(WebFrame *)frame;
-(TiObjectRef)registerJSContext:(JSGlobalContextRef)context forFrame:(WebFrame*)frame;
-(BOOL)isGlobalObjectRegisteredForFrame:(WebFrame*) frame;
-(TiObjectRef)globalObjectForFrame:(WebFrame*) frame;
-(void)deregisterGlobalObjectForFrame:(WebFrame *)frame;
@end
#endif

#ifdef TIDE_LITE
#import <WebKit/WebScriptObject.h>

@class NativeWindow;
@interface WebViewDelegate : NSObject
{
    NativeWindow* window;
    Host* host;
    BOOL initialDisplay;
    std::map<WebFrame*, TiObjectRef>* frameToGlobalObject;
    Logger* logger;
}
-(id)initWithWindow:(NativeWindow*)window;
-(void)setupPreferences;
-(void)registerGlobalObject:(TiObjectRef) globalObject forFrame:(WebFrame *)frame;
-(TiObjectRef)registerJSContext:(JSGlobalContextRef)context forFrame:(WebFrame*)frame;
-(BOOL)isGlobalObjectRegisteredForFrame:(WebFrame*) frame;
-(TiObjectRef)globalObjectForFrame:(WebFrame*) frame;
-(void)deregisterGlobalObjectForFrame:(WebFrame *)frame;
@end
#endif
