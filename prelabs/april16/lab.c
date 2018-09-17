#include "lab.h"


void *binarySearch(void *arr[], int first, int last, void *key)
{
        
        int val = last/2;

    while (first <= last)
    {
 // Check if x is present at mid
        if (compare(key, *(arr + val)) == 0)
            return *(arr + val);
 
        // If x greater, look to right half
        if (compare(key, *(arr + val)) > 0)
            first = val + 1;
 
        // If x is smaller, look to left half 
        if(compare(key, *(arr + val)) < 0)
            last = val - 1;

        val = (first+last)/2;  
    }
 
    return NULL; //element doesn't exist
}

int compare(void *obj1, void *obj2)
{ 
    int num1 = *((int*)obj1);
    int num2 = *((int*)obj2);

    if(num1 < num2)
        return -1;

    if(num1 > num2)
        return 1;

    if(num1 == num2)
        return 0;

    else{
        printf("\nComparison Failed.");
        exit(1);
    }
    
}

void printArray(void *arr[], int size)
{
    int n = size;

    for(int i = 0; i < n; i++)
    {
        printf("%d ", *((int*)arr[i]));
    }

    printf("\n");
}
