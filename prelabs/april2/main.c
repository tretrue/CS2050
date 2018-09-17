#include "lab.h"

int main (void)
{
    srand(time(NULL)); //create randnum

    
    int size = 10; //set size

    int n = size;

    int array[n]; //init array

    for(int i = 0; i < n; i++)
    {
        array[i] = ((rand() % 10)); //create array of size n
    }
    printf("\nArray before sorting: ");
    
        printArray(array, n);
    
    bubbleSort(array, n);
    
    printf("Array after sorting: ");
    
        printArray(array,n);

    int key = (rand() % 10);
    int first = 0;
    int last = n-1;

    printf("\nAttempting to retrieve index with value %d\n", key);
    
    int result = binarySearch(array, first, last, key);

    if(result == -1)
    printf("\nElement not found.");
    
    else
    {
        printf("\nElement found at index %d", result+1);
    }

    return 0;
}
