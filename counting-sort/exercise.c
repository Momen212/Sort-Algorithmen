#include <stdio.h>
#include <stdlib.h>
#include "utils.c"
 
int main() {
    int n;

    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    counting_sort(arr,  n);
    

    free(arr);
    return 0;
}
