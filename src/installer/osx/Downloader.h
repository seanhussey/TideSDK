/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#import <Cocoa/Cocoa.h>


@interface Downloader :  NSObject {
	NSString* suggestedFilename;
	NSString* userAgent;
	NSMutableURLRequest* downloadRequest;
	NSURLConnection* downloadConnection;
	NSProgressIndicator* progress;
	NSMutableData* data;

	long long expectedBytes;
	BOOL completed;
}
-(id)initWithURL:(NSURL*)url progress:(NSProgressIndicator*)p;
-(BOOL)isDownloadComplete;
-(BOOL)completed;
-(void)setCompleted:(BOOL)value;
-(NSString*)suggestedFilename;
-(NSData*)data;
@end
