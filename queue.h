#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

struct queueNode {
    float data;
    int id;
    struct queueNode* next;
};

struct queue {
    struct queueNode* front;
    struct queueNode* rear;
};

struct queue* createQueue();
void enqueue (struct queue* queue, float data, int id);

#endif