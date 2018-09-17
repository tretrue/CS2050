#include "lab.h"

dList* createdoublyList(){
    dList* dlist = (dList*)malloc(sizeof(dList));
    dlist->head = NULL;
    dlist->size = 0;
    return dlist;
}

dList* doublyaddToFront(dList* dlist, int newValue){
    
    dNode* newNode = createdoublyNode(newValue);
    if(dlist->size == 0)
    {
    newNode->next = dlist->head;
    dlist->size ++;
    dlist->head = dlist->tail = newNode;
    dlist->head->prev =NULL;
    dlist->tail->next = NULL;
    dlist->head = newNode;
    return dlist;
    }
    else{
    newNode->next = dlist->head;
    dlist->size ++;
    dlist->head = newNode;
    dlist->head->next->prev = dlist->head;
    return dlist;
    }
}

dNode* createdoublyNode(int item){
    dNode* newNode = (dNode*)malloc(sizeof(dNode));
    if (newNode){
        newNode->key = item;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    else {
        printf("malloc failed\n");
    }
    return newNode;
}

void printdoublyList(dList* dlist){
    printf("Elements on list are: ");
    dNode* temp = dlist->head;
    while (temp != NULL){
        printf("%d ",temp->key);
        temp = temp->next;
    }
    printf("\n\n");
}

dList* removeTail(dList* dlist){
    dNode* temp = dlist->tail;
    dlist->tail = dlist->tail->prev;
    free(temp);
    if(dlist->tail != NULL)
    dlist->tail->next = NULL;

    return dlist;
}

int dequeue (dList* dlist)
{
    int value = dlist->tail->key;
    dlist = removeTail(dlist); 
    return value;
}

dList* enqueue(dList* dlist, int value){
    dlist = doublyaddToFront(dlist, value);
    return dlist;    
};

void freedoublyList(dList* dlist)
{
 dNode* temp = dlist->head;
 while (temp != NULL)
 {
  dlist->head = dlist->head->next;
  free(temp);
  temp = dlist->head;
 }
 free(temp);

}

dList* addAndSort (dList* dlist, int value){
    dNode* newNode = createdoublyNode(value);
    dNode* temp;
    dNode* p = dlist->head;
    if(p == NULL){
        dlist->head = newNode;
        dlist->size++;
        return dlist;
    }
    if(value <= p->key){
       dlist->size++;
       return doublyaddToFront(dlist, value);
    }

    do{
        p = p->next;
        temp = p->prev;
    }
    while(p->prev->key < value && p->next != NULL);
    
    p->prev = newNode;
    newNode->next = p;
    temp->next = newNode;
    newNode->prev = temp;
    dlist->size++;


    return dlist;

}