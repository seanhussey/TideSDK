/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/


#include <tideutils/data_utils.h>
#include "poco/KDigestEngine.h"
#include "poco/KMD5Engine.h"

using KPoco::DigestEngine;
using KPoco::MD5Engine;

#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>


namespace TideUtils
{
namespace DataUtils
{
    std::string HexMD5(std::string data)
    {
        MD5Engine engine;
        engine.update(data);
        return DigestEngine::digestToHex(engine.digest());
    }

    std::string GenerateUUID()
    {
        boost::uuids::uuid uuid = boost::uuids::random_generator()();
        return boost::lexical_cast<std::string>(uuid);
    }
}
}
