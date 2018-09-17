#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct doublystructNode {
    int key;
    struct doublystructNode* next;
    struct doublystructNode* prev;
}dNode;

typedef struct structNode {
    int key;
    struct structNode* next;
}Node;

typedef struct singlylinkedList {
    Node* head;
    Node* tail;
    int size;
}List;

typedef struct doublylinkedList {
    dNode* head;
    dNode* tail;
    int size;
}dList;

Node* createNode(int item);
List* createList();
List* addToFront(List* list, int newValue);
void printList(List* list);

dNode* createdoublyNode(int item);
dList* createdoublyList();
dList* doublyaddToFront(dList* dlist, int newValue);
void printdoublyList(dList* dlist);


List* insertKey(List* list, int newValue, int index); 
List* removeFirstOccurrence(List* list, int keyValue);

dList* insertKeydoubly(List* dlist, int newValue, int index);
dList* removeFirstOccurrencedoubly(List* dlist, int keyValue);

dList* removeTail(dList* dlist);
int dequeue(dList* dlist);
dList* enqueue(dList* dlist, int value);

void freeList(List* list);
void freedoublyList(dList* dlist);

dList* addAndSort(dList* dlist, int value);