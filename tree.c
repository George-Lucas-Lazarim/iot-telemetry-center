#include "tree.h"

struct treeNode* addData (struct treeNode* root, struct node* node) {
    struct treeNode* newNode = (struct treeNode*) malloc (sizeof(struct treeNode));
    newNode->data = node->data;
    newNode->id = node->id;
    newNode->right = newNode->left = NULL;

    if (root == NULL) return newNode;

    struct treeNode* currentNode = root;

    while (true) {
        if (currentNode->data <= node->data) {
            if (currentNode->right == NULL) {
                currentNode->right = newNode;
                return root;
            }
            currentNode = currentNode->right;
        } else {
            if (currentNode->left == NULL) {
                currentNode->left = newNode;
                return root;
            }
            currentNode = currentNode->left;
        }
    }
}