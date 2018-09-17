#include "lab.h"

int main (void)
{
    srand(time(NULL));
    int arr[SIZE]; //base random array
    
    int num = SIZE;
    int *size = &num;
 
//bubble sort   
    void *barray[SIZE];//array for bubblesort

    for(int i = 0; i < SIZE; i++)
    {
       barray[i] = &arr[i];
    }

    printf("\nArray before sorting: ");
    printArray(barray, SIZE);

    bubbleSort(barray, size);

    printf("\nArray after sorting: ");
    printArray(barray, SIZE);

//insertion sort
    void *iarray[SIZE];//array for insertion sort
    
    for(int i = 0; i < SIZE; i++)
    {
       iarray[i] = &arr[i];
    }

    printf("\nArray before sorting: ");
    printArray(iarray, SIZE);

    insertion(iarray);

    printf("\nArray after sorting: ");
    printArray(iarray, SIZE);

//selection sort
    void *sarray[SIZE];//array for insertion sort
    
    for(int i = 0; i < SIZE; i++)
    {
       sarray[i] = &arr[i];
    }

    printf("\nArray before sorting: ");
    printArray(sarray, SIZE);

    selection(sarray);

    printf("\nArray after sorting: ");
    printArray(sarray, SIZE);

//quick sort
    void *qarray[SIZE];//array for quick sort
    
    for(int i = 0; i < SIZE; i++)
    {
       qarray[i] = &arr[i];
    }

    printf("\nArray before sorting: ");
    printArray(qarray, SIZE);

    int *zero = 0;

    quickSort(qarray, (void*)zero, (void*)size);

    printf("\nArray after sorting: ");
    printArray(qarray, SIZE);

//merge sort
    void *marray[SIZE];//array for merge sort
    
    for(int i = 0; i < SIZE; i++)
    {
       marray[i] = &arr[i];
    }

    printf("\nArray before sorting: ");
    printArray(marray, SIZE);

    quickSort(marray, (void*)zero, (void*)size);

    printf("\nArray after sorting: ");
    printArray(marray, SIZE);

//free arrays
    free(barray);
    free(iarray);
    free(sarray);
    free(qarray);
    free(marray);


    return 0;
}