#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

void print_array(const int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n"); 
}

void merge_sort_recursive(int target[], int source[], int left, int right, int *compare_cnt,int n) {

    if (left >= right) {
        if (right==n-1){
            print_array(target,n);
        }
        


        return;
    }
    int mid = (left + right) / 2;

    merge_sort_recursive(source, target, left, mid, compare_cnt,n);
    merge_sort_recursive(source, target, mid + 1, right, compare_cnt,n);

    for (int i = left; i <=right; i++) source[i] = target[i];

    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        (*compare_cnt)++;
        if (source[i] <= source[j]) {
            target[k++] = source[i++];
        } else {
            target[k++] = source[j++];
        }
    }

    while (i <= mid) {
        target[k++] = source[i++];
    }

    while (j <= right) {
        target[k++] = source[j++];
    }

    // Copy merged segment back to source for next level
    for (int i = left; i <= right; i++) {
        source[i] = target[i];
    }

    if (right==n-1){
        print_array(target,n);
    }
}

void merge_sort(int arr[], int n, int *compare_cnt) {

    int tmp_array[100];
    for (int i = 0; i < n; i++) tmp_array[i] = arr[i];

    merge_sort_recursive(arr, tmp_array, 0, n - 1, compare_cnt,n);

}

bool is_sorted(const int array[], int n) {

    for (int i = 0; i < n ; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;

}
