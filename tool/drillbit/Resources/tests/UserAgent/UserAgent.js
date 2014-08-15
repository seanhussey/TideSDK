/**
 * Copyright (c) 2012 - 2014 TideSDK contributors 
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

describe("Contents of user agent", {
  validate_name_and_version: function () {
    value_of(Ti.userAgent)
      .should_contain('TideSDK/');
    value_of(Ti.userAgent)
      .should_contain('TideSDK/' + Ti.version);
    // for now, we're going to simulate Safari -- this addresses TI-303
    value_of(Ti.userAgent)
      .should_contain('Safari');
  }
});
