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

void printTreeNode (struct treeNode* root) {
    if (root == NULL) return;

    printf("\n%.2f: ", root->data);
    if (root->left != NULL) {
        printf("%.2f; ", root->left->data);
    } else {
        printf("NULL; ");
    }
    if (root->right != NULL) {
        printf("%.2f", root->right->data);
    } else {
        printf("NULL");
    }
}

void printTree (struct treeNode* root) {
    if (root == NULL) return;

    printTreeNode(root);
    printTree(root->left);
    printTree(root->right);
}