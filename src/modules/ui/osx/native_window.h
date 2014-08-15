/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _NATIVE_WINDOW_H_
#define _NATIVE_WINDOW_H_

#import "../ui_module.h"
#import <Cocoa/Cocoa.h>

#ifndef TIDE_LITE
#import <WebKit/WebInspector.h>
#endif

@class WebViewDelegate;

using namespace ti;

#ifndef TIDE_LITE
@interface NativeWindow : NSWindow <NSWindowDelegate>
{
    BOOL canReceiveFocus;
    WebView* webView;
    WebViewDelegate* delegate;
    BOOL requiresDisplay;
    AutoPtr<OSXUserWindow>* userWindow;
    WebInspector* inspector;
    BOOL fullscreen;
    BOOL focused;
    NSRect savedFrame;
}
- (void)setUserWindow:(AutoPtr<OSXUserWindow>*)inUserWindow;
- (void)setupDecorations:(AutoPtr<WindowConfig>)config;
- (void)setTransparency:(double)transparency;
- (void)setFullscreen:(BOOL)yn;
- (void)close;
- (void)finishClose;
- (void)open;
- (void)frameLoaded;
- (WebView*)webView;
- (OSXUserWindow*)userWindow;
- (void)showInspector:(BOOL)console;
@end
#else
@interface NativeWindow : NSWindow <NSWindowDelegate>
{
    BOOL canReceiveFocus;
    WebView* webView;
    WebViewDelegate* delegate;
    BOOL requiresDisplay;
    AutoPtr<OSXUserWindow>* userWindow;
    BOOL fullscreen;
    BOOL focused;
    NSRect savedFrame;
}
- (void)setUserWindow:(AutoPtr<OSXUserWindow>*)inUserWindow;
- (void)setupDecorations:(AutoPtr<WindowConfig>)config;
- (void)setTransparency:(double)transparency;
- (void)setFullscreen:(BOOL)yn;
- (void)close;
- (void)finishClose;
- (void)open;
- (void)frameLoaded;
- (WebView*)webView;
- (OSXUserWindow*)userWindow;
@end
#endif

#endif
