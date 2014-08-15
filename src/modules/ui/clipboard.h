/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _CLIPBOARD_H_
#define _CLIPBOARD_H_

#include <tide/tide.h>

namespace ti
{
    class Clipboard : public AccessorObject
    {
        public:
        Clipboard();
        ~Clipboard();

        enum DataType { TEXT, URI_LIST, IMAGE, UNKNOWN };
        void _GetData(const ValueList& args, ValueRef result);
        void _SetData(const ValueList& args, ValueRef result);
        void _ClearData(const ValueList& args, ValueRef result);
        void _HasData(const ValueList& args, ValueRef result);
        void _GetText(const ValueList& args, ValueRef result);
        void _SetText(const ValueList& args, ValueRef result);
        void _ClearText(const ValueList& args, ValueRef result);
        void _HasText(const ValueList& args, ValueRef result);
        bool HasData(DataType type);
        void ClearData(DataType type);

        std::string& GetText();
        void SetText(std::string& newText);
        bool HasText();
        void ClearText();
        BytesRef GetImage(std::string& mimeType);
        void SetImage(std::string& mimeType, BytesRef newImage);
        bool HasImage();
        void ClearImage();
        std::vector<std::string>& GetURIList();
        void SetURIList(std::vector<std::string>& newURIList);
        bool HasURIList();
        void ClearURIList();

        std::string& GetTextImpl();
        void SetTextImpl(std::string& newText);
        bool HasTextImpl();
        void ClearTextImpl();
        BytesRef GetImageImpl(std::string& mimeType);
        void SetImageImpl(std::string& mimeType, BytesRef image);
        bool HasImageImpl();
        void ClearImageImpl();
        std::vector<std::string>& GetURIListImpl();
        void SetURIListImpl(std::vector<std::string>& uriList);
        bool HasURIListImpl();
        void ClearURIListImpl();
    };
}
#endif
