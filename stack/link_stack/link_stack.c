/*
 * Project: data-Structure-example
 * Module: module_name
 * File: link_stack.c
 * Created Date: 2025-03-24 14:42:34
 * Author: wangshuqiang
 * Description: description
 * -----
 * todo: modified
 * -----
 */

/* ======================================================================================
 * log
 */
#include <stdlib.h>
#include <string.h>
#define LOG_ENABLE_DEBUG (1)

/* ======================================================================================
 * includes
 */
#include "link_stack.h"
#include "stdbool.h"
#include "stdio.h"
/* ======================================================================================
 * macros
 */

/* ======================================================================================
 * types
 */
typedef struct link_node {
    int node_data;
    struct link_node *next;
} link_node_t;

typedef struct {
    link_node_t *top;
    int count;
} link_stack_t;
/* ======================================================================================
 * declaration
 */

/* ======================================================================================
 * globals
 */

/* ======================================================================================
 * helper
 */

/* ======================================================================================
 * private implementation
 */
static link_stack_t *link_stack_init(void) {
    link_stack_t *stack = (link_stack_t *)malloc(sizeof(link_stack_t));
    if (NULL == stack) {
        printf("%s init failed,memory not enough\r\n", __func__);
        return NULL;
    }

    memset(stack, 0, sizeof(link_stack_t));

    // 空栈时将栈顶指向空节点
    stack->top = NULL;
    stack->count = 0;

    return stack;
}

static void link_stack_destroy(link_stack_t *stack) {

    // 判断传参是否错误
    if (NULL == stack) {
        printf("%s param null\r\n", __func__);
        return;
    }

    // 判断链栈是否为空栈
    if (NULL != stack->top) {
        link_node_t *head = stack->top;
        while (head) {
            link_node_t *p = head->next;
            free(head);
            head = p;
        }
        stack->top = NULL;
    }

    free(stack);
}

static bool is_link_stack_empty(link_stack_t *stack) {

    if (NULL == stack) {
        printf("%s param null\r\n", __func__);
        return true;
    }

    if (NULL == stack->top) {
        return true;
    }

    return false;
}

static void link_stack_printf(link_stack_t *stack) {

    if ((NULL == stack) || (true == is_link_stack_empty(stack))) {
        printf("%s param null\r\n", __func__);
        return;
    }

    link_node_t *head = stack->top;
    while (head) {
        link_node_t *p = head->next;
        printf("%d\t", head->node_data);
        head = p;
    }
    printf("\r\n");
}

static void link_stack_push(link_stack_t *stack, int data) {

    if (NULL == stack) {
        printf("%s param null\r\n", __func__);
        return;
    }

    // 判断是否有空间开辟节点
    link_node_t *node = (link_node_t *)malloc(sizeof(link_node_t));

    if (NULL == node) {
        printf("%s can not malloc memory anymore\r\n", __func__);
        return;
    }

    memset(node, 0, sizeof(link_node_t));

    // 将第一个节点的next指向NULL，作为栈底
    if (true == is_link_stack_empty(stack)) {
        node->next = NULL;
    } else {
        node->next = stack->top;
    }

    node->node_data = data;
    stack->top = node;
    stack->count++;
}

static void link_stack_pop(link_stack_t *stack) {

    if ((NULL == stack) || (NULL == stack->top)) {
        printf("%s param null\r\n", __func__);
        return;
    }

    link_node_t *head = stack->top;
    if (NULL == head->next) {
        stack->top = NULL;
    } else {
        stack->top = head->next;
    }

    free(head);
    stack->count--;
}
/* ======================================================================================
 * implementation
 */

void link_stack_test(void) {

    link_stack_t *link_stack = link_stack_init();
    link_stack_push(link_stack, 4);
    link_stack_push(link_stack, 8);
    link_stack_push(link_stack, 10);
    link_stack_push(link_stack, 2);
    link_stack_printf(link_stack);
    link_stack_pop(link_stack);
    link_stack_pop(link_stack);
    link_stack_printf(link_stack);
    link_stack_push(link_stack, 100);
    link_stack_push(link_stack, 322);
    link_stack_pop(link_stack);
    link_stack_printf(link_stack);
    link_stack_destroy(link_stack);
    link_stack = NULL;
    return;
}