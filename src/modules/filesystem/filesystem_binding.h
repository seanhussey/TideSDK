/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _FILESYSTEM_BINDING_H_
#define _FILESYSTEM_BINDING_H_

#include <vector>
#include <tide/tide.h>
#include <Poco/Mutex.h>
#include <Poco/Timer.h>

namespace ti
{
    class FilesystemBinding : public StaticBoundObject
    {
    public:
        FilesystemBinding(Host*, TiObjectRef);
        virtual ~FilesystemBinding();

    private:
        Host *host;
        TiObjectRef global;
        std::vector<TiObjectRef> asyncOperations;
        Poco::Timer *timer;

        void CreateTempFile(const ValueList& args, ValueRef result);
        void CreateTempDirectory(const ValueList& args, ValueRef result);
        void GetFile(const ValueList& args, ValueRef result);
        void GetFileStream(const ValueList& args, ValueRef result);
        void GetApplicationDirectory(const ValueList& args, ValueRef result);
        void GetApplicationDataDirectory(const ValueList& args, ValueRef result);
        void GetRuntimeHomeDirectory(const ValueList& args, ValueRef result);
        void GetResourcesDirectory(const ValueList& args, ValueRef result);
        void GetProgramsDirectory(const ValueList &args, ValueRef result);
        void GetDesktopDirectory(const ValueList& args, ValueRef result);
        void GetDocumentsDirectory(const ValueList& args, ValueRef result);
        void GetUserDirectory(const ValueList& args, ValueRef result);
        void GetLineEnding(const ValueList& args, ValueRef result);
        void GetSeparator(const ValueList& args, ValueRef result);
        void GetRootDirectories(const ValueList& args, ValueRef result);
        void ExecuteAsyncCopy(const ValueList& args, ValueRef result);

        //INTERNAL ONLY
        void OnAsyncOperationTimer(Poco::Timer &timer);
        void DeletePendingOperations(const ValueList& args, ValueRef result);
    };
}

#endif
