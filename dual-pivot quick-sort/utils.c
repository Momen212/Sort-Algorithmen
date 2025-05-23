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


void swap(int* data, int i, int j) {
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

int *partition(int data[], int l, int r, int *compare_cnt)
{

    int p1=data[l];
    int p2=data[r];
    (*compare_cnt)++;
    if (p1<p2){
        swap(data,l ,r);
        p1 = data[l];
        p2 = data[r];
    }
    int i=l+1;
    int k=r-1;
    int j=i;
    while (j <= k) {
        (*compare_cnt)++;
        if (data[j] > p1) {
            swap(data,j ,i);
            i++;
            j++;
        } else {
            (*compare_cnt)++;
            if (data[j] < p2) {
            swap(data,j ,k);
            k--;
            } else {
                j++;
            }
        }
    }

    swap(data,l ,--i);  // p1 korrekt platzieren
    swap(data,r ,++k);  // p2 korrekt platzieren


    int* piv=malloc(2*sizeof(int));
    piv[0]=i;
    piv[1]=k;
    return piv;
}

void quick_sort(int data[], int l, int r, int *compare_cnt)
{


    if (l<r){
        int *m = partition(data, l, r, compare_cnt);
        printf("%d %d ",data[m[0]],data[m[1]]);
        quick_sort(data,l,m[0]-1,compare_cnt);
        quick_sort(data,m[0]+1,m[1]-1,compare_cnt);
        quick_sort(data,m[1]+1,r,compare_cnt);
        
    }
}