/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Refer to LICENSE for details of distribution and use.
 **/


#ifndef _TIDE_APP_MANIFEST_H_
#define _TIDE_APP_MANIFEST_H_

#include <tideutils/base.h>

namespace TideUtils
{
  /**
   * Represents a Tide App Manifest class which holds all manifest data.
   */
  class TIDE_UTILS_API AppManifest
  {
    public:
      AppManifest(const std::string& manifestPath);
      ~AppManifest();

    private:
      void parseManifest();

      const std::string manifestPath;
  };
}

#endif
