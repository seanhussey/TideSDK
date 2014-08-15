/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Includes modified sources under the Apache 2 License
 * Copyright (c) 2008 - 2012 Appcelerator Inc
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _PHP_TYPES_H_
#define _PHP_TYPES_H_

#include "php_module.h"

namespace tide
{
    typedef struct
    {
        zend_object std;
        ValueRef kvalue;
    } PHPTiObject;
    extern zend_class_entry *PHPTiObjectClassEntry;
    extern zend_class_entry *PHPTiMethodClassEntry;
    extern zend_class_entry *PHPTiListClassEntry;
    extern zend_object_handlers PHPTiObjectHandlers;

    namespace PHPUtils
    {
        ValueRef ToTiValue(zval* value TSRMLS_DC);
        zval* ToPHPValue(ValueRef value);
        void ToPHPValue(ValueRef value, zval** returnValue);
        std::string ZvalToPropertyName(zval* property);
        TiListRef PHPArrayToTiList(zval* array TSRMLS_DC,
            bool ignoreGlobals=false);
        TiListRef PHPHashTableToTiList(HashTable* hashtable TSRMLS_DC,
             bool ignoreGlobals=false);
        SharedStringList GetHashKeys(HashTable* hash);
        void TiObjectToKPHPObject(ValueRef objectValue, zval** returnValue);
        void TiMethodToKPHPMethod(ValueRef methodValue, zval** returnValue);
        void TiListToKPHPArray(ValueRef listValue, zval** returnValue);
        void InitializePHPTideClasses();
        bool PHPObjectsEqual(zval* val1, zval* val2 TSRMLS_DC);
        int HashZvalCompareCallback(const zval** one, const zval** two TSRMLS_DC);
        SharedStringList GetClassMethods(zend_class_entry* ce TSRMLS_DC);
        TiListRef GetClassVars(zend_class_entry* ce TSRMLS_DC);
        zend_function* GetGlobalFunction(const char *name TSRMLS_DC);
        void GenerateCaseMap(string code TSRMLS_DC);

        TiObjectRef GetCurrentGlobalObject();
        void PushPHPSymbolsIntoGlobalObject(HashTable* symbolTable, TiObjectRef global TSRMLS_DC);
        void PushGlobalObjectMembersIntoPHPSymbolTable(HashTable* symbolTable, TiObjectRef global TSRMLS_DC);
        void SwapGlobalObject(TiObjectRef newGlobal, HashTable* symbolTable TSRMLS_DC);
    }
}

#endif
