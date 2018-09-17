#include "lab.h"

void printArray(void *arr[], int size)
{
    int n = size;

    for(int i = 0; i < n; i++)
    {
        printf("%d ", *((int*)arr[i]));
    }

    printf("\n");
}

void swap(void *xp, void *yp)
{
    //grab values
    int num1 = *((int*)xp);
    int num2 = *((int*)yp);
    
    //bubble sort
    int temp = num1;
    num1 = num2;
    num2 = temp;

    //re-assign
    xp = &num1;
    yp = &num2;
}

int compare (void *obj1, void *obj2)
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

void bubbleSort(void *arr[], void *size)
{
   int n = *((int*)size);

   int i, j; //placeholders

   for (i = 0; i < n-1; i++)
   {     
       for (j = 0; j < n-i-1; j++)
       {
           if (compare(*(arr + j), *(arr + (j+1))) > 0) //bubblesort
           {
              swap(*(arr + j), *(arr + (j+1)));
           }
        }
   }
}

void insertion (void *arr[])
{
    int n = SIZE;
    int i = 0;

    for( i = 1; i < n; i++)
    {
        int temp = *(((int*)arr + i));
		int j = i - 1;
		
        while(temp < *((int*)(arr + i)) && j >= 0)
		    {
		    	*(((int*)arr + (j + 1))) = *(((int*)arr + j));
			    --j;
		    }

       *(((int*)arr + (j + 1))) = temp;   
     }
}

void selection (void *arr[])
{
    int i, j, mindex;

    // loop through all numbers 
   for(i = 0; i < SIZE-1; i++) { 
	
      // set current element as minimum 
      mindex = i;
		
      // check the element to be minimum 
      for(j = i + 1; j < SIZE; j++) 
      {
         if( *(arr + j) < *(arr + mindex))
         {
            mindex = j;
         }
     }
     if(mindex != i) {
         printf("Items swapped: [ %d, %d ]\n" , *(((int*)arr + i)), *(((int*)arr + mindex))); 
			
         // swap the numbers 
         int temp = *((int*)(arr + mindex));
         *(arr + mindex) = *(arr + i);
         *((int*)(arr + i)) = temp;
      }          
   }
}

void quickSort (void *arr[], void *x, void *z)
{
    

    int key, k, j, i;

    int m = *((int*)x);
    int n = *((int*)z);

    int *mptr = &m;
    int *nptr = &n;

    if(m < n)
    {
        k = (m + n)/2;

        swap(*(arr + m), *(arr + k));
        key = *(((int*)arr + k));
        i = m + 1;
        j = n;
        
        while(i <= j)
        {
            while((i <= n) && (*(((int*)arr + i)) <= key))
                i++;
            while((j >= m) && (*(((int*)arr + j)) > key))
                j--;
            if( i < j)
                swap(*(arr + i), *(arr + j));
        }
        swap(*(arr + m), *(arr + j));
 
        /* recursively sort the lesser list */

        int num1 = j - 1;
        int num2 = j + 1;

        int *jminus = &num1;
        int *jplus = &num2;

        quickSort(arr, (void*)mptr, (void*)jminus);
        quickSort(arr, (void*)jplus, (void*)nptr);
    }

}

void mergeSort(void *arr[], void *x, void *z)
{
    int mid;

    int i = *((int*)x);
    int j = *((int*)z);

    int *iptr = &i;
    int *jptr = &j;
        
    if(i<j)
    {
        mid=(i+j)/2;

        int *midptr = &mid;
        mergeSort(arr,(void*)iptr,(void*)midptr);        //left recursion

        mid += 1;
        midptr = &mid;

        mergeSort(arr,(void*)midptr,(void*)jptr);    //right recursion
        merge(arr,i,mid,mid+1,j);    //merging of two sorted sub-arrays
    }
}
 
void merge(void *arr[],int i1,int j1,int i2,int j2)
{
    int a[SIZE];
    
    for(int i = 0; i < SIZE; i++)
        a[i] = *((int*)(arr + i));


    int temp[SIZE];    //array used for merging
    int i,j,k;
    i=i1;    //beginning of the first list
    j=i2;    //beginning of the second list
    k=0;
    
    while(i<=j1 && j<=j2)    //while elements in both lists
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    
    while(i<=j1)    //copy remaining elements of the first list
        temp[k++]=a[i++];
        
    while(j<=j2)    //copy remaining elements of the second list
        temp[k++]=a[j++];
        
    //Transfer elements from temp[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];

    for(i = 0; i < SIZE; i++)
        arr[i] = &a[i];
}