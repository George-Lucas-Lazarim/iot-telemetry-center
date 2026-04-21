#include "queue.h"

struct queue* createQueue (struct queue* queue) {
    queue = (struct queue*) malloc (sizeof(struct queue));
    if (queue == NULL) return queue;

    queue->front = queue->rear = NULL;
    return queue;
}