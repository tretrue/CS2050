#include "lab.h"

int main (void)
{
    dList* uqueue = createdoublyList();
    
    srand(time(NULL));

for (int i = 0; i < 10; i++){
        uqueue = doublyaddToFront(uqueue,rand()%20);
    } //add values to list

    printdoublyList(uqueue);

    printf("Value of %d removed.\n", dequeue(uqueue));

    printdoublyList(uqueue);

    uqueue = enqueue(uqueue, rand()%20);

    printf("Node with value %d added.\n", uqueue->head->key);

    printdoublyList(uqueue);

    printf("** FREEING UNSORTED LIST **\n\n");

    freedoublyList(uqueue);

    printf("** CREATING SORTED LIST **\n\n");

    dList* squeue = createdoublyList();

    for(int i = 0; i < 10; i++)
    {
        int j = rand()%20;
        squeue = addAndSort(squeue, j);
        printf("Value %d added and sorted.\n", j);
        printdoublyList(squeue);
    }

    return 0;
}