/*
 * Project: data-Structure-example
 * Module: module_name
 * File: static_link.c
 * Created Date: 2025-03-03 09:10:09
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
#include "static_link.h"
#include "stdio.h"
/* ======================================================================================
 * macros
 */
#define MAX_NODE_NUMBER 20
/* ======================================================================================
 * types
 */
typedef struct node {
    int data;
    int address;
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
static node_t link[MAX_NODE_NUMBER] = {0};

static void static_printf_node(void) {

    int node = link[MAX_NODE_NUMBER - 1].address;

    while (node) {
        printf("%d\t", link[node].data);
        node = link[node].address;
    }

    printf("\r\n");
    return;
}

static int get_spare_link_node(void) {
    return link[0].address;
}

static int get_static_link_last_address(void) {

    if (!link[MAX_NODE_NUMBER - 1].address) {
        return -1;
    }

    int address = link[MAX_NODE_NUMBER - 1].address;
    while (link[address].address) {
        address = link[address].address;
    }
    return address;
}

static int get_static_link_length(void) {
    int address = MAX_NODE_NUMBER - 1;
    int length = 0;
    while (link[address].address) {
        length++;
        address = link[address].address;
    }
    return length;
}

static void static_link_list_insert_node(int value) {
    if (get_spare_link_node() <= 0 || get_spare_link_node() >= MAX_NODE_NUMBER)
        return;

    // 判断节点个数是否越界
    if (get_static_link_length() >= MAX_NODE_NUMBER) {
        return;
    }
    // 判断静态链表最后一个节点address
    if (get_static_link_last_address() >= MAX_NODE_NUMBER) {
        return;
    }

    int idle_node = get_spare_link_node();
    int next_idle_node = link[idle_node].address;
    int link_node = get_static_link_last_address();

    // 创建节点
    link[idle_node].data = value;
    link[idle_node].address = 0;
    link[link_node].address = idle_node;

    // 头节点更新备份链表
    link[0].address = next_idle_node;

    // 尾节点有效链表
    if (0 == get_static_link_length()) {
        link[MAX_NODE_NUMBER - 1].address = idle_node;
    }
}

static void static_link_delete_according_value(int value) {

    // 待删除数值为0时，不进行删除操作
    if (!value)
        return;

    // 遍历静态链表搜索是否有待删除节点
    int pre_address = MAX_NODE_NUMBER - 1;
    int node_address = link[pre_address].address;

    while ((link[node_address].data != value)) {
        if (0 == link[node_address].address) {
            // 静态链表中没有待删除项，退出
            return;
        }
        pre_address = node_address;
        node_address = link[node_address].address;
    }

    link[node_address].data = 0;
    // 如果删除静态链表第一个节点，此时更新尾节点指向，否则，不更新
    if (node_address == link[MAX_NODE_NUMBER - 1].address) {
        link[MAX_NODE_NUMBER - 1].address = link[node_address].address;
    } else {
        // 删除中间节点，需要连接前后节点，尾节点不需要更新
        link[pre_address].address = link[node_address].address;
    }

    link[node_address].address = link[0].address;
    link[0].address = node_address;
}

static void static_link_init(void) {

    for (int i = 0; i < MAX_NODE_NUMBER - 1; i++) {
        link[i].address = i + 1;
    }

    link[MAX_NODE_NUMBER - 1].address = 0;
}
/* ======================================================================================
 * implementation
 */
void static_link_test(void) {
    static_link_init();
    static_link_list_insert_node(20);
    static_link_list_insert_node(32);
    static_link_list_insert_node(17);
    static_link_list_insert_node(5);
    static_link_list_insert_node(82);
    static_link_delete_according_value(20);
    static_link_delete_according_value(5);
    static_link_delete_according_value(82);
    static_printf_node();
    static_link_list_insert_node(66);
    static_link_list_insert_node(77);
    static_link_list_insert_node(82);
    static_link_delete_according_value(32);
    static_link_delete_according_value(0);
    static_link_delete_according_value(34);
    static_printf_node();
    return;
}