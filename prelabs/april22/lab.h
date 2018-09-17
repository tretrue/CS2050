#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10


void quickSort (void *arr[], void *x, void *z);
void printArray(void *arr[], int size);
void swap(void *xp, void *yp); 
int compare (void *obj1, void *obj2);
void bubbleSort(void *arr[], void *size);
void insertion (void *arr[]);
void selection (void *arr[]);
void mergeSort(void *arr[], void *x, void *z);
void merge(void *arr[],int i1,int j1,int i2,int j2);



