#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int compare(void *obj1, void *obj2);
void *binarySearch(void *arr[], int first, int last, void *query);
void printArray(void *arr[], int size);