#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 10
typedef struct treeNode {
    int key;
    struct treeNode* left;
    struct treeNode* right;
}Tree;

Tree* add(Tree* top, int *key);
void swap(void *xp, void *yp);
void printArray(int arr[], int size);
Tree* newNode (int key);
void freeTree(Tree* top);
void printTree(Tree* top);
void writeTreeToArray(Tree* top, int *index, void* array[]);




int main (void){

    int array[SIZE];

    
    
    int size = SIZE;

    void** arr = malloc(SIZE * sizeof(void*));

    for(int i = 0; i < SIZE; i++)
    {
        array[i] = i;
                
        arr[i] = &array[i];
    }
    
    printArray(array, size);
    

    printf("\nArray values: ");

    int index;

    for(int i = SIZE - 1; i > 0; i--)
    {
        srand(time(NULL));

        index = (rand() % (i + 1)); 

        swap(arr[index], arr[i] );
        
    }

    for(int i = 0; i < SIZE; i++)
    {
        printf("%d", *((int*)arr[i]));
        array[i] = *((int*)arr[i]);
    }

    Tree* top = NULL;
    top = add(top, *(arr));

    for(int i = 1; i < SIZE; i++)
    {
        add(top, *(arr + i));
    }

    printTree(top);

    int j = 0;
    
    writeTreeToArray(top, &j, arr);

    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", *((int*)arr[i]));
        array[i] = *((int*)arr[i]);
    }

    freeTree(top);
    return 0;
}

Tree* add(Tree* top, int *key)
{
    if(top == NULL){
        return newNode(*key);
    }
    
    if(*key < top->key){
        
        top->left = add(top->left, key);
    }

    else if(*key > top->key){
        top->right = add(top->right, key);
    }

    else{
        double coin = drand48();
        if( coin < 0.5){
            top->left = add(top->left, key);
        }
        else{
            top->right = add(top->right, key);
        }
    }

    return top;
}

Tree* newNode (int key)
{
    Tree* node = malloc(sizeof(Tree));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;

}

void swap(void *xp, void *yp)
{
    //grab values
   // int num1 = *((int*)xp);
    //int num2 = *((int*)yp);
    
    //bubble sort
    int temp = *((int*)xp);
    *((int*)xp)= *((int*)yp);
    *((int*)yp) = temp;

    //re-assign
   // xp = &num1;
    //yp = &num2;
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

void freeTree(Tree* top)
{
    if(!top)
    {
        return;
    }

    freeTree(top->left);
    freeTree(top->right);

    free(top);
}

void printTree(Tree* top)
{
    if(!top)
        return;
    
    printTree(top->left);
        printf("\nNode is: %d", top->key);
    printTree(top->right);
    
}

void writeTreeToArray(Tree* top, int *index, void* array[])
{

    if(top)
    {
        writeTreeToArray(top->left, index, array);
        
        *((int*)(array[*index])) = top->key;
        
        *index += 1;
        
        writeTreeToArray(top->right, index, array);
    }

}