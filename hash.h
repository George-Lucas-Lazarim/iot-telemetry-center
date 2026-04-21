#ifndef HASH_H
#define HASH_H

#include "queue.h"

void initTable (struct node** table, int size);
int hashFunction (int id, int size);

#endif