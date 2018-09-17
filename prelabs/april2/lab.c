#include "lab.h"
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int size)
{
   int n = size;

   int i, j; //placeholders

   for (i = 0; i < n-1; i++)
   {     
       for (j = 0; j < n-i-1; j++)
       {
           if (arr[j] > arr[j+1]) //bubblesort
           {
              swap(&arr[j], &arr[j+1]);
           }
        }
   }
}

void printArray(int arr[], int size)
{
    int n = size;

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int binarySearch(int arr[], int first, int last, int key)
{
        int val = last/2;

        //printf("\nFirst: %d  val: %d  Last: %d ", first, val, last);
        //printf("\nvalue at first: %d\tvalue at middle: %d\tvalue at end: %d\n", arr[first], arr[val], arr[last]);

    //printf("%d is the target\n", key);
    while (first <= last)
    {
 // Check if x is present at mid
        if (arr[val] == key)
            return val;
 
        // If x greater, look to right half
        if (arr[val] < key)
            first = val + 1;
 
        // If x is smaller, look to left half half
        else
            last = val - 1;

        val = (first+last)/2;

        
    }
 
    return -1; //element doesn't exist
}
