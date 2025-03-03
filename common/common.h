/*
 * Project: data-Structure-example
 * Module: module_name
 * File: common.h
 * Created Date: 2025-03-02 23:14:35
 * Author: wangshuqiang
 * Description: description
 * -----
 * todo: modified 
 * -----
 */
#ifndef COMMON_H
#define COMMON_H

/* ======================================================================================
 * includes
 */

/* ======================================================================================
 * extern
 */

/* ======================================================================================
 * macros
 */

#define check_var_void_return(param, print)                                          \
 if (param) {                                                                \
   printf(print);                                                              \
   return;                                                                    \
 }
/* ======================================================================================
 * types
 */

/* ======================================================================================
 * declaration
 */
void printf_iterator(int *array, int n);
/* ======================================================================================
 * extern
 */ 
#endif // COMMON_H