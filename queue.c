#include "queue.h"

bool isEmpty (struct queue* queue) {
    return (queue == NULL || queue->front == NULL);
}

struct queue* createQueue() {
    struct queue* queue = (struct queue*) malloc (sizeof(struct queue));
    if (queue == NULL) {
        printf("Error! Memory allocation failure");
        return NULL;
    } else if (isEmpty(queue)) return queue;

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

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

