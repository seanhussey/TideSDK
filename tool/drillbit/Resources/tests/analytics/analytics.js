/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

describe("Analytics Tests", {
  test_analytics_properties: function () {
    value_of(Ti.Analytics)
      .should_be_object();
    value_of(Ti.Analytics.addEvent)
      .should_be_function();
  }
});
