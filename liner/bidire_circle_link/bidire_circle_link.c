/*
 * Project: data-Structure-example
 * Module: module_name
 * File: bidire_circle_link.c
 * Created Date: 2025-03-06 18:26:34
 * Author: wangshuqiang
 * Description: description
 * -----
 * todo: modified
 * -----
 */

/* ======================================================================================
 * log
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#define LOG_ENABLE_DEBUG (1)

/* ======================================================================================
 * includes
 */
#include "bidire_circle_link.h"

/* ======================================================================================
 * macros
 */

/* ======================================================================================
 * types
 */
typedef struct node {
    int data;
    struct node *pre;
    struct node *next;
} node_t;
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
static node_t *bidire_circle_link_init(void) {
    node_t *pointer = NULL;

    pointer = (node_t *)malloc(sizeof(node_t));
    if (NULL == pointer) {
        printf("bidirectional link space malloc fail\r\n");
        return NULL;
    }

    memset(pointer, 0, sizeof(node_t));
    pointer->next = pointer;
    pointer->pre = pointer;
    return pointer;
}

static void bidire_circle_link_head_insert(node_t *link, int value) {
    if (NULL == link) {
        return;
    }

    // 引入first节点，使其指向头节点的下一个节点，当链表为空表时，first节点指向自身，
    // 添加第一个节点时，需要将空表中head->pre指向新的节点，此后在添加节点后就不需要更新head->pre.
    node_t *first = link->next;
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (NULL == new_node) {
        printf("malloc space not enough\r\n");
        return;
    }

    new_node->data = value;

    new_node->next = first;
    new_node->pre = link;
    link->next = new_node;
    first->pre = new_node;

    return;
}

static void bidire_circle_link_tail_insert(node_t *link, int value) {
    if (NULL == link) {
        return;
    }

    node_t *head = link;
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (NULL == new_node) {
        printf("malloc space not enough\r\n");
        return;
    }

    new_node->data = value;

    new_node->next = head;
    new_node->pre = head->pre;
    head->pre->next = new_node;
    head->pre = new_node;

    return;
}

static void bidire_circle_link_tail_delete(node_t *link) {
    if (NULL == link) {
        return;
    }

    // 空表无法删除最后一个节点
    if (link->pre == link)
        return;

    node_t *head = link->pre;

    // 删除操作
    head->pre->next = link;
    link->pre = head->pre;

    free(head);
    return;
}
static int get_bidire_circle_link_length(node_t *link) {
    if (NULL == link) {
        return -1;
    }

    int length = 0;
    node_t *head = link->next;
    while (head != link) {
        length++;
        head = head->next;
    }
    return length;
}

static void bidire_circle_link_head_delete(node_t *link) {
    if ((NULL == link) || (link->next == link)) {
        return;
    }

    node_t *head = link->next;
    head->next->pre = link;
    link->next = head->next;

    return;
}

static void printf_link_node(node_t *link) {
    if (NULL == link) {
        return;
    }

    int length = 0;
    node_t *head = link->next;
    while (head != link) {
        length++;
        printf("%d\t", head->data);
        head = head->next;
    }

    printf(" length = %d\r\n", length);
}

static void free_link_node(node_t *link) {
    if (NULL == link) {
        return;
    }

    node_t *head = link->next;
    while (head != link) {
        node_t *p = head->next;
        free(head);
        head = p;
    }

    free(head);
    return;
}

static node_t *find_node_by_value(node_t *link, int value) {
    if ((NULL == link) || (link->next == link)) {
        return NULL;
    }

    node_t *head = link->next;

    while (head != link) {
        if (head->data == value) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}
/* ======================================================================================
 * implementation
 */

void bidire_circle_link_test(void) {

    // 头插和尾插的步骤要着重看一下
    // 注意头插法中引用first节点实现添加第一个节点时，头节点指向第一个节点的操作
    node_t *link = bidire_circle_link_init();
    bidire_circle_link_tail_delete(link);
    bidire_circle_link_head_delete(link);
    printf_link_node(link);
    bidire_circle_link_head_insert(link, 3);
    bidire_circle_link_tail_delete(link);
    printf_link_node(link);
    bidire_circle_link_head_insert(link, 7);
    bidire_circle_link_head_insert(link, 43);
    bidire_circle_link_head_delete(link);
    bidire_circle_link_head_insert(link, 35);
    bidire_circle_link_head_delete(link);
    bidire_circle_link_head_insert(link, 397);
    printf_link_node(link);
    bidire_circle_link_tail_delete(link);
    printf_link_node(link);
    bidire_circle_link_tail_insert(link, 55);
    bidire_circle_link_head_delete(link);
    bidire_circle_link_tail_insert(link, 10);
    bidire_circle_link_tail_insert(link, 4);
    bidire_circle_link_head_delete(link);
    bidire_circle_link_tail_insert(link, 667);
    printf_link_node(link);
    bidire_circle_link_tail_delete(link);
    printf_link_node(link);
    node_t *p = find_node_by_value(link, 667);
    printf("%d\r\n", p->data);
    free_link_node(link);
    link = NULL;
}