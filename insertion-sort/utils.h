#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

bool is_sorted(const int array[], int n);
void insertion_sort(int *compare_cnt, int numbers[], int size);
void print_array(const int array[], int size);

#endif