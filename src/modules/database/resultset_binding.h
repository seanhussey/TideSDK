/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _DATABASE_RESULTSET_BINDING_H_
#define _DATABASE_RESULTSET_BINDING_H_

#include <tide/tide.h>
#include <Poco/Data/RecordSet.h>

namespace ti
{
    /**
     * Binding for the ResultSet (or in Poco SQLite the RecordSet)
     *
     */
    class ResultSetBinding : public StaticBoundObject
    {
    public:
        ResultSetBinding();
        ResultSetBinding(Poco::Data::RecordSet& rs);

    protected:
        virtual ~ResultSetBinding();

    private:
        SharedPtr<Poco::Data::RecordSet> rs;
        bool eof;
        
        void Bind();
        void TransformValue(size_t index, ValueRef result);
        

        void IsValidRow(const ValueList& args, ValueRef result);
        void Next(const ValueList& args, ValueRef result);
        void Close(const ValueList& args, ValueRef result);
        void RowCount(const ValueList& args, ValueRef result);
        void FieldCount(const ValueList& args, ValueRef result);
        void FieldName(const ValueList& args, ValueRef result);
        void Field(const ValueList& args, ValueRef result);
        void FieldByName(const ValueList& args, ValueRef result);
    };
}

#endif
