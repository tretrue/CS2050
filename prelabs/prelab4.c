#include <stdio.h>
#include <stdlib.h>

double* createArray(double*);
void freeArray(double*);

int main (void)
{
    double *array;
    array = malloc(sizeof(double)*100 + sizeof(int));

    array = createArray(array);

    int i; 

    printf("\n");

    for(i = 0; i < 100; i++)
    {
        printf(" %f", *(array + i));
    }

    printf("\nsize of array is %d", *((int *)array - 1));

    freeArray(array);

    return 0; 
}

double* createArray (double* array)
{
   *((int *)array) = 100;  
    array =(double *)(((int *) array) + 1);

    int i;
    double j = 0;

    for(i = 0; i < 100; i++)
    {
        *(array + i) = j;

        j++;
    }

    return array;
}

void freeArray (double* array)
{
    array =(double *)(((int *) array) - 1);

    free(array);
}

i