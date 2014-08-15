/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Refer to LICENSE for details of distribution and use.
 **/

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>

#include <cassert>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>

#include <tideutils/app_manifest.h>

namespace TideUtils
{
    AppManifest::AppManifest(const std::string& manifestPath_)
      : manifestPath(manifestPath_)
    {
      this->parseManifest();
    }

    AppManifest::~AppManifest()
    {
    }

    void AppManifest::parseManifest()
    {

    }
}
