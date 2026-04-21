#include "queue.h"

struct queue* createQueue() {
    struct queue* queue = (struct queue*) malloc (sizeof(struct queue));
    if (queue == NULL) return queue;

    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue (struct queue* queue, float data, int id) {
    struct queueNode* newNode = (struct queueNode*) malloc (sizeof(struct queueNode));

    if (newNode == NULL) {
        printf("Error! Memory allocation failure");
        return;
    }

    newNode->data = data;
    newNode->id = id;
    newNode->next = NULL;

    if (queue == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}