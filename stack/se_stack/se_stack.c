/*
 * Project: data-Structure-example
 * Module: module_name
 * File: se_stack.c
 * Created Date: 2025-03-09 14:27:51
 * Author: wangshuqiang
 * Description: description
 * -----
 * todo: modified
 * -----
 */

/* ======================================================================================
 * log
 */
#define LOG_ENABLE_DEBUG (1)

/* ======================================================================================
 * includes
 */
#include "se_stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ======================================================================================
 * macros
 */
#define STACK_SIZE 5
/* ======================================================================================
 * types
 */
typedef struct {
    int stack[STACK_SIZE];
    signed int top;
} seq_stack_t;

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
static seq_stack_t *se_stack_init(void) {
    seq_stack_t *stack = (seq_stack_t *)malloc(sizeof(seq_stack_t));
    if (NULL == stack) {
        printf("seqstack space malloc fail\r\n");
        return NULL;
    }

    memset(stack->stack, 0, sizeof(stack->stack));
    stack->top = -1;
    return stack;
}

static void se_stack_destory(seq_stack_t *stack) {
    if (NULL == stack) {
        printf("stack didn't exist\r\n");
        return;
    }

    free(stack);
}

static void seq_stack_clear(seq_stack_t *stack) {
    if (NULL == stack) {
        printf("stack didn't exist\r\n");
        return;
    }

    memset(stack->stack, 0, sizeof(stack->stack));
    stack->top = -1;
    return;
}

static int get_stack_length(seq_stack_t *stack) {
    if (NULL == stack) {
        printf("%s param error\r\n", __func__);
        return 0;
    }

    int length = ((sizeof(stack->stack) / sizeof(int)) - 1);
    if (stack->top >= length) {
        return STACK_SIZE;
    } else if (stack->top <= -1) {
        return 0;
    } else {
        return stack->top + 1;
    }
}

static void seq_stack_push(seq_stack_t *stack, int value) {
    if ((NULL == stack) || (STACK_SIZE <= get_stack_length(stack))) {
        printf("%s param null\r\n", __func__);
        return;
    }

    stack->stack[++stack->top] = value;
    return;
}

static void seq_stack_pop(seq_stack_t *stack) {
    if ((NULL == stack) || (0 >= get_stack_length(stack))) {
        printf("%s param null\r\n", __func__);
        return;
    }

    stack->top--;
    return;
}

static void print_sequence_stack(seq_stack_t *stack) {
    if ((NULL == stack) || (stack->top <= -1)) {
        return;
    }

    int top = stack->top;
    while (top >= 0) {
        printf("%d\t", stack->stack[top--]);
    }

    printf("\r\n");
}
/* ======================================================================================
 * implementation
 */

void sequence_stack_test(void) {
    seq_stack_t *stack = se_stack_init();

    seq_stack_push(stack, 5);
    seq_stack_push(stack, 9);
    seq_stack_push(stack, 13);
    seq_stack_push(stack, 4);
    print_sequence_stack(stack);
    seq_stack_pop(stack);
    seq_stack_pop(stack);
    print_sequence_stack(stack);
    seq_stack_clear(stack);
    seq_stack_pop(stack);
    seq_stack_push(stack, 2);
    seq_stack_push(stack, 3);
    seq_stack_push(stack, 4);
    seq_stack_push(stack, 5);
    seq_stack_push(stack, 6);
    seq_stack_push(stack, 7);
    seq_stack_push(stack, 8);
    seq_stack_push(stack, 12);
    se_stack_destory(stack);
    stack = NULL;
}