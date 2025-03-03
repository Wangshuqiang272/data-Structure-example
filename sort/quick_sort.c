/*
 * Project: cmake1
 * Module: module_name
 * File: main.c
 * Created Date: 2025-02-18 10:16:54
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
#include "../common/common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
static int quick_sort_array[] = {4, 6, 2, 5, 7, 1, 3, 3, 9};

/* ======================================================================================
 * helper
 */

/* ======================================================================================
 * private implementation
 */

static int divide_portation(int *array, int low, int high) {
  int temp = -1;
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (array[j] <= *(array + high)) {
      i++;
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }

  temp = array[i + 1];
  array[i + 1] = array[high];
  array[high] = temp;
  return i + 1;
}

static void quick_sort(int *array, int low, int high) {
  if (!array) {
    printf("%s param error", __func__);
    return;
  }

  if (low > high)
    return;
  int point = divide_portation(array, low, high);

  quick_sort(array, low, point - 1);
  quick_sort(array, point + 1, high);
}

static void select_sort(int *array, int length) {
  if (array == NULL) {
    printf("%s param error\r\n", __func__);
  }

  for (int i = 0; i < length - 1; i++) {
    for (int j = i + 1; j < length; j++) {
      if (array[i] < array[j]) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

static void Bubbles_sort(int *array, int length) {
  if (array == NULL) {
    printf("%s param error\r\n", __func__);
  }

  for (int i = length; i > 0; i--) {
    for (int j = 0; j < length - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j + 1];
        array[j + 1] = array[j];
        array[j] = temp;
      }
    }
  }
}
/* ======================================================================================
 * implementation
 */

void quick_sort_test(void) {
  int length = (sizeof(quick_sort_array) / sizeof(int));
  printf_iterator(quick_sort_array, length);
  // quick_sort(quick_sort_array, 0, length - 1);
  select_sort(quick_sort_array, length);
  // Bubbles_sort(quick_sort_array, length);
  printf_iterator(quick_sort_array, length);
  return;
}