#include "lab.h"

#define SIZE 10
int main (void)
{
    srand(time(NULL));
    void *array[SIZE];
    int arr[SIZE];


    for(int i = 0; i < SIZE; i++)
    {
       arr[i] = i;
       array[i] = &arr[i];
    }

    

    printf("\nArray after sort: ");
    printArray(array, SIZE);

    int val = (rand() % 20);
    int *key = &val;

    printf("\nSearching for value %d", *key);

    int *result = (int*)binarySearch(array, 0, (SIZE - 1), (void*)key);

    if (result == NULL)
        printf("\nValue not found");
    else
        printf("\n%d has been found.", *result);

    

    return 0;
}