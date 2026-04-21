#include "queue.h"

bool isEmpty (struct queue* queue) {
    return (queue == NULL || queue->front == NULL);
}

struct queue* createQueue() {
    struct queue* queue = (struct queue*) malloc (sizeof(struct queue));
    if (queue == NULL) {
        printf("Error! Memory allocation failure");
        return NULL;
    }

    queue->front = queue->rear = NULL;
    return queue;
}

void enqueueData (struct queue* queue, float data, int id) {
    struct node* newNode = (struct node*) malloc (sizeof(struct node));

    if (newNode == NULL) {
        printf("Error! Memory allocation failure");
        return;
    }

    newNode->data = data;
    newNode->id = id;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void enqueueNode (struct queue* queue, struct node* node) {
    if (isEmpty(queue)) {
        queue->front = queue->rear = node;
    } else {
        struct node* tempNode = queue->front;

        while (tempNode != NULL) {
            if (tempNode->id == node->id) {
                tempNode->data = node->data;
                free(node);
                return;
            }
            tempNode = tempNode->next;
        }

        queue->rear->next = node;
        queue->rear = node;
    }
}

struct node* dequeue (struct queue* queue) {
    if (isEmpty(queue)) {
        printf("Error! The queue is empty");
        return NULL;
    }

    struct node* node = queue->front;

    queue->front = queue->front->next;
    if (queue->front == NULL) queue->rear = NULL;

    node->next = NULL;

    return node;
}