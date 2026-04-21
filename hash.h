#ifndef HASH_H
#define HASH_H

#include "queue.h"

void initTable (struct queue** table, int size);
int hashFunction (struct node* queueNode, int size);
void addTable (struct queue** table, struct node* queueNode, int size);

#endif