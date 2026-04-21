#include "hash.h"

void initTable(struct node** table, int size) {
    if (size <= 0) {
        printf("Error! Invalid size");
        return;
    }
    
    for (int i=0; i < size; i++) table[i] = NULL;
}