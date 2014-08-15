/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef STREAM_H_
#define STREAM_H_

namespace tide {

class TIDE_API Stream : public StaticBoundObject {
public:
    Stream(const char* type = "Stream");
    virtual ~Stream();

    virtual void Write(const char* buffer, size_t size);
    virtual bool IsWritable() const;
    virtual size_t Read(const char* buffer, size_t size);
    virtual bool IsReadable() const;
};

} // namespace tide

#endif
