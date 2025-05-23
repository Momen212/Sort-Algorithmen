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

    print_array(arr , n);
    printf("\n");
    insertion_sort( &z,arr, n);
    print_array(arr , n);
    printf("\n");
    if(is_sorted(arr,n)){
        printf("Feld ist sortiert!\n");
    }
    else{
        printf("FEHLER: Feld ist NICHT sortiert!\n");
    }
    printf("Das Sortieren hat %d Vergleiche benoetigt.",z);
}
