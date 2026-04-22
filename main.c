#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#include "hash.h"
#include "tree.h"

#define N_SENSORS 5
#define MIN_TEMPERATURE 20
#define MAX_TEMPERATURE 85

int main() {
    struct queue* buffer = createQueue();
    struct queue* temperatureTable[N_SENSORS];
    initTable(temperatureTable, N_SENSORS);
    struct treeNode* criticalTree = NULL;

    srand(time(NULL));

    int idValid[] = {10, 17, 31, 5, 12};
    for (int i=0; i < N_SENSORS; i++) {
        struct node* initialSensor = (struct node*) malloc (sizeof(struct node));
        initialSensor->id = idValid[i];
        initialSensor->data = 0.0;
        initialSensor->next = NULL;
        addTable(temperatureTable, initialSensor, N_SENSORS);
    }

    int n;
    printf("\nEnter the amount of random data you want to generate in the IDs: ");
    scanf("%d", &n);

    int idSensors[] = {10, 17, 31, 5, 12, 99, 66, 33, 11, 73};
    float drawnTemperature;
    printf("\nGenerating random data in the IDs...");
    for (int i=0; i < n; i++) {
        int idDrawn = idSensors[rand() % 10];
        float escale = (float) rand() / RAND_MAX;
        drawnTemperature = MIN_TEMPERATURE + (escale * (MAX_TEMPERATURE - MIN_TEMPERATURE));
        enqueueData(buffer, drawnTemperature, idDrawn);
    }
    printf("\n%d Packets queued in buffer successfully", n);

    printf("\nAllocating data in the temperature table... ");
    while (!isEmpty(buffer)) {
        struct node* pacage = dequeue(buffer);

        struct node* tempHash = temperatureTable[hashFunction(pacage, N_SENSORS)]->front;
        bool sensorFound = false;

        while (tempHash != NULL) {
            if (tempHash->id == pacage->id) {
                sensorFound = true;
                tempHash->data = pacage->data;
                break;
            }
            tempHash = tempHash->next;
        }

        if (sensorFound) {
            printf("\nSensor %d updated: %.2f C", pacage->id, pacage->data);

            if (pacage->data > 60.0) {
                printf("\nWARNING! Sending sensor %d to the critical historic", pacage->id);
                criticalTree = addData(criticalTree, pacage);
            }
        } else printf("\nSensor %d not authorized. Package discarded", pacage->id);
        free(pacage);
    }
    
    printf("\nData allocated in the temperature table!");

    printf("\n--- CRITICAL ALERT REPORT (Increasing Order of Temperature) ---\n");
    printTree(criticalTree);
    printf("\n");
}