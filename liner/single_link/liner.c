/*
 * Project: cmake1
 * Module: module_name
 * File: main.c
 * Created Date: 2025-02-20 11:06:33
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liner.h"
/* ======================================================================================
 * macros
 */

/* ======================================================================================
 * types
 */

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

static void free_iterator(node_t *liner) {
  if (liner == NULL) {
    printf("%s param error\r\n", __func__);
  }

  node_t *head = liner;
  while (head != NULL) {
    node_t *p = NULL;
    if (head->next != NULL) {
      p = head->next;
    }
    free(head);
    head = p;
  }
}
static node_t *create_liner_object(int n) {
  if (n <= 0)
    return NULL;
  node_t *head = (node_t *)malloc(sizeof(node_t));
  if (head == NULL)
    return NULL;
  node_t *res = head;
  head->data = 0;
  head->next = NULL;

  for (int i = 0; i < n; i++) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (NULL == node) {
      free_iterator(head);
      return NULL;
    }
    node->data = i;
    head->next = node;
    head = head->next;
  }
  return res;
}

static int get_liner_length(node_t *liner) {
  if (liner == NULL) {
    printf("%s param error\r\n", __func__);
    return -1;
  }
  int length = -1;
  node_t *head = liner;
  while (head) {
    length++;
    head = head->next;
  }
  return length;
}
static void print_iterator(node_t *liner) {
  if ((NULL == liner) || (NULL == liner->next))
    return;
  node_t *head = liner->next;
  while (head != NULL) {
    printf("%d\t", head->data);
    head = head->next;
  }
  printf("\r\nlength = %d\r\n", get_liner_length(liner));
}

static void head_insert_data(node_t *liner, int data) {
  if (liner == NULL) {
    printf("%s param error", __func__);
  }

  node_t *p = liner->next;
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  if (new_node == NULL)
    return;

  new_node->data = data;

  new_node->next = p;
  liner->next = new_node;
}

static void tail_insert_data(node_t *liner, int data) {
  if (liner == NULL) {
    printf("%s param error", __func__);
  }

  node_t *tail = liner;
  while (tail != NULL) {
    if (NULL == tail->next)
      break;

    tail = tail->next;
  }

  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  if (NULL == new_node)
    return;

  new_node->data = data;
  new_node->next = NULL;
  tail->next = new_node;
}
static void insert_data(node_t *liner, int data, insert_mode_e mode) {
  switch (mode) {
  case HEAD_INSERT: {
    head_insert_data(liner, data);
    break;
  }
  case TAIL_INSERT: {
    tail_insert_data(liner, data);
    break;
  }
  default: {
    break;
  }
  }
}

static void delete_data_according_value(node_t *liner, int data) {
  if (liner == NULL) {
    printf("%s param error", __func__);
  }

  node_t *head = liner->next;
  node_t *pre_head = liner;
  while (NULL != head) {
    if (head->data != data) {
      pre_head = head;
      head = head->next;
      continue;
    }

    if (NULL == head->next) {
      pre_head->next = NULL;
      free(head);
      break;
    }

    pre_head->next = head->next;
    free(head);
    head = pre_head->next;
    break;
  }
}

static void delete_data_according_index(node_t *liner, int index) {
  if (liner == NULL) {
    printf("%s param error", __func__);
  }

  // 链表中只有头结点时不删除任何节点，默认头节点无法删除
  // 无法删除index值大于链表长度的节点
  if ((get_liner_length(liner) <= 0) || (index >= get_liner_length(liner)) ||
      (0 == index)) {
    return;
  }

  int p_index = 0;
  node_t *tail = liner->next;
  node_t *head = liner;
  for (int i = 1; i < index; i++) {
    head = tail;
    tail = tail->next;
  }
  head->next = tail->next;
  free(tail);
  tail = NULL;
}

static int find_node_index_by_index(node_t *liner, int val) {
  if (liner == NULL) {
    printf("%s param error", __func__);
  }

  node_t *head = liner->next;
  int index = 1;
  while (NULL != head) {
    if (head->data != val) {
      head = head->next;
      index++;
      continue;
    }
    return index;
  }

  return -1;
}
/* ======================================================================================
 * implementation
 */

void single_liner_test(void) {
  node_t *liner = create_liner_object(10);
  insert_data(liner, 99, HEAD_INSERT);
  insert_data(liner, 89, HEAD_INSERT);
  insert_data(liner, 79, HEAD_INSERT);
  insert_data(liner, 101, TAIL_INSERT);
  insert_data(liner, 150, TAIL_INSERT);
  insert_data(liner, 190, TAIL_INSERT);
  print_iterator(liner);
  delete_data_according_value(liner, 101);
  delete_data_according_value(liner, 190);
  delete_data_according_value(liner, 79);
  delete_data_according_value(liner, 200);
  print_iterator(liner);
  delete_data_according_index(liner, 4);
  delete_data_according_index(liner, 5);
  print_iterator(liner);
  printf("find val 89 = %d\r\n", find_node_index_by_index(liner, 89));
  printf("find val 2 = %d\r\n", find_node_index_by_index(liner, 2));
  printf("find val 150 = %d\r\n", find_node_index_by_index(liner, 150));
  printf("find val 300 = %d\r\n", find_node_index_by_index(liner, 300));
  free_iterator(liner);
  liner = NULL;
  return;
}