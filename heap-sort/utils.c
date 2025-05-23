#include <stdio.h>
#include <limits.h>
#include "utils.h"

void print_array(const int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d", array[size-1]);
    printf("\n");
} 

// Swap two elements in an array
void swap(int* data, int i, int j) {
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

// Bottom-up heapify (inserts new element into heap)
void max_heapify_up(int* data, int i) {
    if(i>0 && data[i]>data[i/2]){
        swap(data,i,i/2);
        i=i/2;
    }
    else return;
    max_heapify_up(data,i);
}

// Restore max heap by pushing down from the root
void max_heapify_down(int* data, int n) {
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < n && data[left] > data[largest]) {
            largest = left;
        }

        if (right < n && data[right] > data[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(data,i,largest);
            i = largest; 
        } 
        else {
            break; 
        }
    }
}

// Turn entire array into a max heap
void build_max_heap(int* data, int n) {
    for(int i=0 ; i<n ; i++){
        max_heapify_up( data, i);
    }

}

// Remove and return the max element from heap
int extract_max(int* data, int n) {
    if (n<1) return 0;
    int max=data[0];
    swap(data,0,n-1);
    n--;
    max_heapify_down(data, n);  
    return max;
}

// Select the k-th largest element
int heap_select(int* data, int n, int k) {
    for(int i=0;i<n;i++){
        for (int j = i+1; j < n; j++)
        {
            if (data[i]>data[j]){
                swap(data,i,j);
            }
        }
        
    }
    int k_largest= data[n-k];
    max_heapify_down(data,n);
    return k_largest;
}

