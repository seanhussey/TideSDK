/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _RUBY_HASH_H_
#define _RUBY_HASH_H_

namespace tide {

class KRubyHash : public TiObject {
public:
    KRubyHash(VALUE object);
    virtual ~KRubyHash();

    virtual void Set(const char *name, ValueRef value);
    virtual ValueRef Get(const char *name);
    virtual SharedStringList GetPropertyNames();
    virtual SharedString DisplayString(int);
    VALUE ToRuby();

    /*
     * Determine if the given Ruby object equals this one
     * by comparing these objects's identity e.g. equals?()
     *  @param other the object to test
     *  @returns true if objects have reference equality, false otherwise
     */
    virtual bool Equals(TiObjectRef);

private:
    VALUE hash;
    AutoPtr<KRubyObject> object;

};

}

#endif /* RUBY_BOUND_OBJECT_H_ */
