#ifndef UTILS_H
#define UTILS_H

void print_array(const int array[], int size);
void swap(int* data, int i, int j);
void max_heapify_up(int* data, int i);
void max_heapify_down(int* data, int n);
void build_max_heap(int* data, int n);
int extract_max(int* data, int n);
int heap_select(int* data, int n, int k);

#endif