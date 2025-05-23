#include <stdlib.h>
#include <stdio.h>
#include "utils.c"

int main() {

    int n;
    int z=0;
    scanf("%d",&n);
    int arr[100];
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }

        print_array(arr, n);
        merge_sort(arr, n, &z);
        printf("Das Sortieren hat %d Vergleiche benoetigt.\n", z);
}
