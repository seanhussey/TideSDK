
# 
# Copyright (c) 2012 - 2014 TideSDK contributors 
# http://www.tidesdk.org
# Includes modified sources under the Apache 2 License
# Copyright (c) 2008 - 2012 Appcelerator Inc
# Refer to LICENSE for details of distribution and use.
# 

import pstats
import sys

stats = pstats.Stats(sys.argv[1])
stats.sort_stats('time','name').print_stats()
