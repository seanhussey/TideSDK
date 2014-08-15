/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _OSX_NSLOG_CHANNEL_
#define _OSX_NSLOG_CHANNEL_

#include <Poco/Channel.h>
#include <Poco/PatternFormatter.h>
#include "Poco/Mutex.h"
//#include "Poco/UnWindows.h"

namespace tide
{
	class NSLogChannel : public Poco::Channel
	{
		public:
			NSLogChannel(); 
			void log(const Poco::Message& msg);

		protected:
			~NSLogChannel() {};

		private:
			Poco::PatternFormatter formatter;
	};
}

#endif
