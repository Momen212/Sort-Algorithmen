#include <stdio.h>
#include <stdlib.h>
#include "utils.c"

int main() { 


     int n;
     int data[100];
     int k;
     scanf("%d",&n);
     for(int i =0 ; i<n ; i++){
          scanf("%d",&data[i]);

     }
     scanf("%d",&k);
     if(k<1) return 0;
     print_array(data,n);
     int l = heap_select(data,n,k);
     printf("Das %d-groesste Element ist %d",k,l);


}
