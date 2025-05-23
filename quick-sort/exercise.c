#include <stdio.h>
#include <stdlib.h>
#include "utils.c"

int main() {
    int compare_cnt = 0;
    int n;

    scanf("%d", &n); 
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    quick_sort(arr,0,n-1,&compare_cnt);
    printf("\n");
    print_array(arr,n);
    printf("Used %d comparisons.\n", compare_cnt);

    free(arr);
    return 0;
}
