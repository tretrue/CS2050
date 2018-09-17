#include <stdio.h>
#include <stdlib.h>

int* createArray(int);
int arraySize(int*);
void freeArray(int*);

int main (void)
{
    int n;
    int size;
    int *array;

    printf("\nEnter the size of the array: ");
    scanf("%d", &n)


    array = createArray(n);

    size = arraySize(array);

    printf("\nThe size of the array is %d\n", size);

    freeArray(array);
}

int* createArray(int n)
{
    int i;
    int *array = malloc(sizeof(int) * (n + 1));

    array[0] = n;
    array = array + 1;

    for(i = 0; i < n; i++)
    {
        array[i] = 0;
    }

    return array;
}

int arraySize(int* array)
{
    int* size = array - 1;

    return *size;
}

void freeArray(int* array)
{
   array = array - 1;

    free(array);
}

