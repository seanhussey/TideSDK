/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#include "ui_module.h"
#include <Poco/StringTokenizer.h>
using Poco::StringTokenizer;

namespace ti
{
    Clipboard::Clipboard() :
        AccessorObject("UI.Clipboard")
    {
        this->SetMethod("setData", &Clipboard::_SetData);
        this->SetMethod("getData", &Clipboard::_GetData);
        this->SetMethod("hasData", &Clipboard::_HasData);
        this->SetMethod("clearData", &Clipboard::_ClearData);
        this->SetMethod("setText", &Clipboard::_SetText);
        this->SetMethod("getText", &Clipboard::_GetText);
        this->SetMethod("clearText", &Clipboard::_ClearText);
        this->SetMethod("hasText", &Clipboard::_HasText);
    }

    static Clipboard::DataType MimeTypeToDataType(std::string& mimeType)
    {
        transform(mimeType.begin(), mimeType.end(), mimeType.begin(), tolower);

        // Types "URL" and "Text" are for IE compatibility. We want to have
        // a consistent interface with WebKit's HTML 5 DataTransfer.
        if (mimeType == "text" || mimeType.find("text/plain") == 0)
        {
            return Clipboard::TEXT;
        }
        else if (mimeType == "url" || mimeType.find("text/uri-list") == 0)
        {
            return Clipboard::URI_LIST;
        }
        else if (mimeType.find("image") == 0)
        {
            return Clipboard::IMAGE;
        }
        else
        {
            return Clipboard::UNKNOWN;
        }
    }

    static BytesRef ValueToBytes(ValueRef value)
    {
        if (value->IsObject())
        {
            BytesRef bytes = value->ToObject().cast<Bytes>();
            if (bytes.isNull())
                bytes = new Bytes("", 0);
            return bytes;
        }
        else if (value->IsString())
        {
            const char* data = value->ToString();
            return new Bytes(data, strlen(data));
        }
        else
        {
            throw ValueException::FromString("Need a Bytes or a String");
        }
    }

    static std::vector<std::string> ValueToURIList(ValueRef value)
    {
        std::vector<std::string> uriList;
        if (value->IsList())
        {
            TiListRef list(value->ToList());
            for (unsigned int i = 0; i < list->Size(); i++)
            {
                ValueRef element(list->At(i));
                if (element->IsString())
                    uriList.push_back(element->ToString());
            }
        }
        else if (value->IsString())
        {
            StringTokenizer tokenizer(value->ToString(), "\n", 
                StringTokenizer::TOK_TRIM | StringTokenizer::TOK_IGNORE_EMPTY);
            for (size_t i = 0; i < tokenizer.count(); i++)
            {
                uriList.push_back(tokenizer[i]);
            }
        }
        else
        {
            throw ValueException::FromString("URI List requires an Array or a newline-delimited String");
        }
        return uriList;
    }

    void Clipboard::_GetData(const ValueList& args, ValueRef result)
    {
        args.VerifyException("getData", "s");

        std::string mimeType(args.GetString(0));
        DataType type = MimeTypeToDataType(mimeType);
        if (type == URI_LIST)
        {
            std::vector<std::string>& list = this->GetURIList();
            if (mimeType == "url")
            {
                std::string url;
                if (list.size() > 0)
                    url = list.at(0);

                result->SetString(url.c_str());
            }
            else
            {
                result->SetList(StaticBoundList::FromStringVector(list));
            }
        }
        else if (type == IMAGE)
        {
            result->SetObject(this->GetImage(mimeType));
        }
        else 
        {
            result->SetString(this->GetText());
        }
    }

    void Clipboard::_SetData(const ValueList& args, ValueRef result)
    {
        args.VerifyException("setData", "s s|o|l|0");

        std::string mimeType(args.GetString(0));
        DataType type = MimeTypeToDataType(mimeType);

        if (args.at(1)->IsNull() ||
            (args.at(1)->IsString() && !strcmp(args.at(1)->ToString(), "")))
        {
            this->ClearData(type);
        }
        else if (type == URI_LIST)
        {
            std::vector<std::string> uriList(ValueToURIList(args.at(1)));
            this->SetURIList(uriList);
        }
        else if (type == IMAGE)
        {
            BytesRef imageBytes(ValueToBytes(args.at(1)));
            this->SetImage(mimeType, imageBytes);
        }
        else
        {
            std::string newText(args.GetString(1, ""));
            this->SetText(newText);
        }
    }

    void Clipboard::_HasData(const ValueList& args, ValueRef result)
    {
        args.VerifyException("hasData", "?s");

        DataType type = UNKNOWN;
        if (args.size() > 0)
        {
            std::string mimeType(args.GetString(0));
            type = MimeTypeToDataType(mimeType);
        }

        result->SetBool(this->HasData(type));
    }

    void Clipboard::_ClearData(const ValueList& args, ValueRef result)
    {
        args.VerifyException("setData", "?s");

        DataType type = UNKNOWN;
        if (args.size() > 0)
        {
            std::string mimeType(args.GetString(0));
            type = MimeTypeToDataType(mimeType);
        }

        this->ClearData(type);
    }

    void Clipboard::_SetText(const ValueList& args, ValueRef result)
    {
        args.VerifyException("setText", "s");
        std::string newText(args.GetString(0, ""));
        this->SetText(newText);
    }

    void Clipboard::_GetText(const ValueList& args, ValueRef result)
    {
        result->SetString(this->GetText());
    }

    void Clipboard::_ClearText(const ValueList& args, ValueRef result)
    {
        this->ClearText();
    }

    void Clipboard::_HasText(const ValueList& args, ValueRef result)
    {
        result->SetBool(this->HasText());
    }

    bool Clipboard::HasData(DataType type)
    {
        if (type == TEXT)
        {
            return this->HasText();
        }
        else if (type == URI_LIST)
        {
            return this->HasURIList();
        }
        else if (type == IMAGE)
        {
            return this->HasImage();
        }
        else
        {
            return this->HasText() || this->HasURIList() || this->HasImage();
        }
    }

    void Clipboard::ClearData(DataType type)
    {
        if (type == TEXT)
        {
            this->ClearText();
        }
        else if (type == URI_LIST)
        {
            this->ClearURIList();
        }
        else if (type == IMAGE)
        {
            this->ClearImage();
        }
        else
        {
            this->ClearText();
            this->ClearURIList();
            this->ClearImage();
        }
    }

    void Clipboard::SetText(std::string& newText)
    {
        if (newText.empty())
            this->ClearText();
        else
            this->SetTextImpl(newText);
    }

    std::string& Clipboard::GetText()
    {
        return this->GetTextImpl();
    }

    void Clipboard::ClearText()
    {
        this->ClearTextImpl();
    }

    bool Clipboard::HasText()
    {
        return this->HasTextImpl();
    }

    BytesRef Clipboard::GetImage(std::string& mimeType)
    {
        return this->GetImageImpl(mimeType);
    }

    void Clipboard::SetImage(std::string& mimeType, BytesRef newImage)
    {
        this->SetImageImpl(mimeType, newImage);
    }

    bool Clipboard::HasImage()
    {
        return this->HasImageImpl();
    }

    void Clipboard::ClearImage()
    {
        this->ClearImageImpl();
    }

    std::vector<std::string>& Clipboard::GetURIList()
    {
        return this->GetURIListImpl();
    }

    void Clipboard::SetURIList(std::vector<std::string>& newURIList)
    {
        this->SetURIListImpl(newURIList);
    }

    bool Clipboard::HasURIList()
    {
        return this->HasURIListImpl();
    }

    void Clipboard::ClearURIList()
    {
        this->ClearURIListImpl();
    }
}

