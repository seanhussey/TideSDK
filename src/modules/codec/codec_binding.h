/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _CODEC_BINDING_H_
#define _CODEC_BINDING_H_

#include <tide/tide.h>


namespace ti
{
    class CodecBinding : public StaticBoundObject
    {
    public:
        CodecBinding(TiObjectRef);
    protected:
        virtual ~CodecBinding();
    private:
        TiObjectRef global;

        void EncodeBase64(const ValueList& args, ValueRef result);
        void DecodeBase64(const ValueList& args, ValueRef result);
        void DigestToHex(const ValueList& args, ValueRef result);
        void DigestHMACToHex(const ValueList& args, ValueRef result);
        void EncodeHexBinary(const ValueList& args, ValueRef result);
        void DecodeHexBinary(const ValueList& args, ValueRef result);
        void Checksum(const ValueList& args, ValueRef result);
        void CreateZip(const ValueList& args, ValueRef result);
        void ExtractZip(const ValueList& args, ValueRef result);
        
        static ValueRef CreateZipAsync(const ValueList& args);
        static ValueRef ExtractZipAsync(const ValueList& args);
    };
}

#endif
