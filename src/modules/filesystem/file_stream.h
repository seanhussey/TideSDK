/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef FileStream_h
#define FileStream_h

#ifdef OS_OSX
#import <Foundation/Foundation.h>
#endif

#include <string>

#include <tide/tide.h>
#include <Poco/FileStream.h>

namespace ti {

class FileStream : public Stream {
public:
    enum FileStreamMode {
        MODE_READ = 1,
        MODE_APPEND = 2,
        MODE_WRITE = 3
    };

    FileStream(std::string filename);
    virtual ~FileStream();

    bool Open(FileStreamMode mode, bool binary = false, bool append = false);
    bool IsOpen() const;
    void Close();

    void Seek(int offset, int direction);
    int Tell();

    virtual void Write(const char* buffer, size_t size);
    virtual bool IsWritable() const;
    virtual size_t Read(const char* buffer, size_t size);
    virtual bool IsReadable() const;

    // TODO: make this private once removed from File.
    void _Open(const ValueList& args, ValueRef result);

private:
    void _IsOpen(const ValueList& args, ValueRef result);
    void _Close(const ValueList& args, ValueRef result);
    void _Seek(const ValueList& args, ValueRef result);
    void _Tell(const ValueList& args, ValueRef result);
    void _Write(const ValueList& args, ValueRef result);
    void _Read(const ValueList& args, ValueRef result);

    void _ReadLine(const ValueList& args, ValueRef result);
    void _WriteLine(const ValueList& args, ValueRef result);
    void _Ready(const ValueList& args, ValueRef result);

    std::string filename;

    Poco::FileInputStream* istream;
    Poco::FileOutputStream* ostream;
    Poco::FileIOS* stream;
};

}

#endif 
