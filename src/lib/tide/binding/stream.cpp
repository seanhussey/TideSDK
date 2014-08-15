/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "../tide.h"

namespace tide {

Stream::Stream(const char* type) : StaticBoundObject(type)
{
}

Stream::~Stream()
{
}

void Stream::Write(const char* buffer, size_t size)
{
    throw ValueException::FromString("Stream is not writable.");
}

bool Stream::IsWritable() const
{
    return false;
}

size_t Stream::Read(const char* buffer, size_t size)
{
    throw ValueException::FromString("Stream is not readable.");
}

bool Stream::IsReadable() const
{
    return false;
}

} // namespace tide
