/* $Id$ */

#ifndef PHP_LIBZOOKEEPER_H
#define PHP_LIBZOOKEEPER_H

extern zend_module_entry libzookeeper_module_entry;
#define phpext_libzookeeper_ptr &libzookeeper_module_entry

#ifdef PHP_WIN32
#   define PHP_LIBZOOKEEPER_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#   define PHP_LIBZOOKEEPER_API __attribute__ ((visibility("default")))
#else
#   define PHP_LIBZOOKEEPER_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(libzookeeper);
PHP_MSHUTDOWN_FUNCTION(libzookeeper);
PHP_RINIT_FUNCTION(libzookeeper);
PHP_RSHUTDOWN_FUNCTION(libzookeeper);
PHP_MINFO_FUNCTION(libzookeeper);

PHP_FUNCTION(confirm_libzookeeper_compiled);    /* For testing, remove later. */

/* 
    Declare any global variables you may need between the BEGIN
    and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(libzookeeper)
    long  global_value;
    char *global_string;
ZEND_END_MODULE_GLOBALS(libzookeeper)
*/

/* In every utility function you add that needs to use variables 
   in php_libzookeeper_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as LIBZOOKEEPER_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define LIBZOOKEEPER_G(v) TSRMG(libzookeeper_globals_id, zend_libzookeeper_globals *, v)
#else
#define LIBZOOKEEPER_G(v) (libzookeeper_globals.v)
#endif

/* class ZookeeperClient { */
zend_class_entry *zookeeper_client_class_entry;

ZEND_BEGIN_ARG_INFO_EX(connect_arg_info, 0, 0, 1)
    ZEND_ARG_INFO(0, host)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_get, 0, 0, 1)
    ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

zend_function_entry zookeeper_client_method_entry[] = {
    PHP_ME(ZookeeperClient, connect, connect_arg_info, ZEND_ACC_PUBLIC)
    PHP_ME(ZookeeperClient, get, get_arg_info, ZEND_ACC_PUBLIC)

    { NULL, NULL, NULL }
};

PHP_METHOD(ZookeeperClient, connect);
PHP_METHOD(ZookeeperClient, get);

/* } ZookeeperClient */

#endif  /* PHP_LIBZOOKEEPER_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
