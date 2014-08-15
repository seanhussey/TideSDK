/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#import <Cocoa/Cocoa.h>
#import "Downloader.h"
#import <tideutils/file_utils.h>
#import <tideutils/boot_utils.h>
#import <tideutils/application.h>
using namespace TideUtils;
using TideUtils::Application;
using TideUtils::SharedApplication;
using TideUtils::KComponentType;
SharedApplication app;

@interface Job : NSObject {
    NSURL* url; 
    NSString* path; 
    BOOL isUpdate; 
}
-(Job*)init:(NSString*)pathOrURL;
-(Job*)initUpdate:(NSString*)pathOrURL;
-(NSURL*)url;
-(NSString*)path;
-(void)setPath:(NSString*)newPath;
-(BOOL)needsDownload;
-(BOOL)isUpdate;
-(int)totalDownloads;
-(int)totalJobs;
@end

@interface Controller : NSObject {
    IBOutlet NSWindow* progressWindow;
    IBOutlet NSProgressIndicator* progressBar;
    IBOutlet NSButton* progressCancelButton;
    IBOutlet NSTextField* progressText;
    IBOutlet NSImageView* progressImage;
    IBOutlet NSTextField* progressAppName;
    IBOutlet NSTextField* progressAppVersion;
    IBOutlet NSTextField* progressAppPublisher;
    IBOutlet NSTextField* progressAppURL;

    IBOutlet NSWindow* introWindow;
    IBOutlet NSTextField* introLicenseLabel;
    IBOutlet NSBox* introLicenseBox;
    IBOutlet NSTextView* introLicenseText;

    IBOutlet NSImageView* introImage;
    IBOutlet NSTextField* introAppName;
    IBOutlet NSTextField* introAppVersion;
    IBOutlet NSTextField* introAppPublisher;
    IBOutlet NSTextField* introAppURL;

    NSMutableArray *jobs;
    NSString *temporaryDirectory;
    NSString *installDirectory;
    NSString *updateFile;
    BOOL skipIntroDialog;
}

-(IBAction)cancelProgress:(id)sender;
-(IBAction)cancelIntro:(id)sender;
-(IBAction)continueIntro:(id)sender;
-(void)updateMessage:(NSString*)msg;
-(NSString*)temporaryDirectory;
-(NSString*)installDirectory;
-(void)finishInstallation;
-(void)downloadAndInstall:(Controller*)controller;
-(void)install:(Job*)job;
-(void)downloadJob:(Job*)job atIndex:(int)index;
-(void)setupDialogs;
-(void)createInstallerMenu:(NSString*)applicationName;
-(void)showIntroDialog;

@end
