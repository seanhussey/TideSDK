/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _URL_H_
#define _URL_H_

#ifndef KEYVALUESTRUCT
typedef struct {
    char* key;
    char* value;
} KeyValuePair;
#define KEYVALUESTRUCT 1
#endif

namespace ti
{
	void NormalizeURLCallback(const char* url, char* buffer, int bufferLength);
	void URLToFileURLCallback(const char* url, char* buffer, int bufferLength);
	int CanPreprocessURLCallback(const char* url);
	char* PreprocessURLCallback(const char* url, KeyValuePair* headers, char** mimeType);
	void ProxyForURLCallback(const char* url, char* buffer, int bufferLength);
}
#endif
