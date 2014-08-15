/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/


#include <curl/curl.h>
#include <tideutils/boot_utils.h>
#define COMPONENT_JOB 0
#define APPLICATION_JOB 1

class Job
{
    public:
    Job(std::string url, int type = COMPONENT_JOB);
    void Fetch();
    void Unzip();
    std::string GetFilename();
    int GetIndex();
    void SetProgress(double progress);
    double GetProgress();
    void ParseURL(std::string url);
    void ParseFile(std::string url);
    Installer* GetInstaller();

    static int total;
    static void InitDownloader();
    static void ShutdownDownloader();

    static std::string temporaryDirectory;
    static std::string installDirectory;

    int Index()
    {
        return this->index;
    }

    private:
    std::string url;
    int type;
    int index;
    std::string out_filename;
    double progress;
    KComponentType componentType;
    std::string name;
    std::string version;
    bool download;

    static CURL *curl;
    static char* curl_error;
    void UnzipComponent();
    void UnzipApplication();
};
