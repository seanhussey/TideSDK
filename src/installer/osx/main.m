/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#import <Cocoa/Cocoa.h>

int main(int argc, char *argv[])
{
#ifdef DEBUG
    int i;
    for (i = 0; i < argc; i++){
        printf("Arg %d is: %s\n",i,argv[i]);
    }
#endif

    return NSApplicationMain(argc,  (const char **) argv);
}
