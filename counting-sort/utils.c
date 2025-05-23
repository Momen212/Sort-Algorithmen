#include <stdio.h>
#include <stdlib.h>

void print_array(const int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n"); 
}

int* count(int* data, int n, int min_value, int max_value) {
    int size=max_value-min_value+1;
    int *C_arr = malloc( size* sizeof(int));

    for (int i = 0; i < n; i++)
    {
        C_arr[data[i]-min_value]++;

    }

    return C_arr;
    
    
}

void counting_sort(int* data, int n) {
    int max_value=data[0];
    int min_value=data[0];
        for (int l = 0; l < n; l++)
    {
        if(max_value<data[l]){
            max_value=data[l];
        }
        if(min_value>data[l]){
            min_value=data[l];
        }
    }
    printf("%d %d\n",min_value,max_value);
    int* array = count(data,n,min_value,max_value);
    int size =max_value-min_value+1;
    print_array(array,size);
    int index=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < array[i]; j++)
        {
            data[index++]=i+min_value;
        }
        
    }
    print_array(data,n);
    free(array);
    
}