/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _COM_REFERENCE_COUNTED_H_
#define _COM_REFERENCE_COUNTED_H_
#include <Unknwn.h>
/*
 * This is a COM-specific wrapper of ReferenceCounted. 
 */
namespace tide
{
    class TIDE_API COMReferenceCounted : public ReferenceCounted, public IUnknown
    {
    public:
        // IUnknown
        virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject)
        {
            *ppvObject = 0;
            if (IsEqualGUID(riid, IID_IUnknown))
            {
                *ppvObject = static_cast<IUnknown*>(this);
            }
            else
            {
                return E_NOINTERFACE;
            }
            return S_OK;
        }
        
        virtual ULONG STDMETHODCALLTYPE AddRef(void)
        {
            duplicate();
            return referenceCount();
        }
        
        virtual ULONG STDMETHODCALLTYPE Release(void)
        {
            release();
            return referenceCount();
        }
    };
}

#endif
