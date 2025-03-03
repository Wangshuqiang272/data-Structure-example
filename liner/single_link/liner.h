/*
 * Project: data-Structure-example
 * Module: module_name
 * File: liner.h
 * Created Date: 2025-03-02 23:09:41
 * Author: wangshuqiang
 * Description: description
 * -----
 * todo: modified 
 * -----
 */
#ifndef LINER_H
#define LINER_H

/* ======================================================================================
 * includes
 */

/* ======================================================================================
 * extern
 */

/* ======================================================================================
 * macros
 */

/* ======================================================================================
 * types
 */
 typedef struct Node {
    int data;
    struct Node *next;
  } node_t;
  
  typedef enum {
    HEAD_INSERT,
    TAIL_INSERT,
    MAX_INSERT,
  } insert_mode_e;
/* ======================================================================================
 * declaration
 */
 void single_liner_test(void);
/* ======================================================================================
 * extern
 */ 
#endif // LINER_H