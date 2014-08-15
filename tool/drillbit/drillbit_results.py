#!/usr/bin/python

# 
# Copyright (c) 2012 - 2014 TideSDK contributors 
# http://www.tidesdk.org
# Includes modified sources under the Apache 2 License
# Copyright (c) 2008 - 2012 Appcelerator Inc
# Refer to LICENSE for details of distribution and use.
# 

# Simple script that gathers all the test results from drillbit and
# spits out the results on stdout in JSON

import os
import sys

scriptDir = os.path.dirname(__file__)
sys.path.append(os.path.join(scriptDir, "..", "site_scons"))

import simplejson

if len(sys.argv) < 2:
    print >>sys.stderr, "Usage: %s [drillbit-results-dir]" % sys.argv[0]
    sys.exit(-1)

resultsDir = sys.argv[1]

results = {}
for file in os.listdir(resultsDir):
    if file[len(file)-5:] == ".json" and file != "drillbit.json":
        test = file[0:len(file)-5]
        result = simplejson.load(open(os.path.join(resultsDir, file), 'r'))
        results[test] = result

print simplejson.dumps(results)
