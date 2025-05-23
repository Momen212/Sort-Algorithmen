#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

void print_array(const int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]); 
    }
    printf("\n");
}



int partition(int data[], int l, int r, int* compare_cnt)
{

    int pivot =data[r];
    int i=l-1;
    for (int j = l; j < r;j++){
        (*compare_cnt)++;
        if (data[j]>pivot){
            i++;
            int tmp=data[i];
            data[i]=data[j];
            data[j]=tmp;
        }
    }
    int t=data[i+1];
    data[i+1]=data[r];
    data[r]=t;    
    
    return i+1;

}

void quick_sort(int data[], int l, int r, int* compare_cnt)
{

    int m;
    if (l<r){
        m=partition(data,l,r,compare_cnt);
        printf("%d ",data[m]);
        quick_sort(data,l,m-1,compare_cnt);
        quick_sort(data,m+1,r,compare_cnt);
    }
}
