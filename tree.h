#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

struct treeNode {
    float data;
    int id;
    struct treeNode* right;
    struct treeNode* left;
};

struct treeNode* addData (struct treeNode* root, struct node* node);
void printTreeNode (struct treeNode* root);
void printTree (struct treeNode* root);

#endif