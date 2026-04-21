#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    float data;
    int id;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
};

bool isEmpty (struct queue* queue);
struct queue* createQueue();
void enqueueData (struct queue* queue, float data, int id);
void enqueueNode (struct queue* queue, struct node* node);
struct node* dequeue (struct queue* queue);
bool extractAndFree (struct queue* queue, float* data, float* id);

#endif