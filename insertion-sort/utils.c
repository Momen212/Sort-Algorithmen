#include "utils.h"

static bool is_sorted_range(const int array[], int left, int right) {
    while(left<right){
        if(array[left]>array[left+1]&& left<right-1){
            return false;
        }
        left++;
    }
    return true;
}

bool is_sorted(const int array[], int n) {
    return is_sorted_range(array, 0, n);
}

void insertion_sort(int *compare_cnt, int numbers[], int size) {
    for (int j=1 ; j<size; ++j){
        int key=numbers[j];
        int i=j-1;
        while(i>=0 && numbers[i]>key){
            (*compare_cnt)++;
            numbers[i+1]=numbers[i];
            i=i-1;
            numbers[i+1]=key;
        }
        if (i >= 0) (*compare_cnt)++;
    }
}

void print_array(const int array[], int size) {
    for (int i=0 ; i<size; ++i){
        printf("%d ",array[i]);
    }
}