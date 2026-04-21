#include "hash.h"

void initTable (struct queue** table, int size) {
    if (size <= 0) {
        printf("Error! Invalid size");
        return;
    }
    
    for (int i=0; i < size; i++) table[i] = createQueue();
}

int hashFunction (struct node* queueNode, int size) {
    if (size <= 0) {
        printf("Error! Invalid size");
        return -1;
    }

    return queueNode->id % size;
}

void addTable (struct queue** table, struct node* queueNode, int size) {
    if (size <= 0) {
        printf("Error! Invalid size");
        return;
    }

    enqueueNode(table[hashFunction(queueNode, size)], queueNode);
}