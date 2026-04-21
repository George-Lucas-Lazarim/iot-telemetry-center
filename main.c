#include "queue.h"
#include "hash.h"
#include "tree.h"
#include <time.h>

int main() {
    struct queue* buffer = createQueue();
    struct queue* temperatureTable[6];
    struct treeNode* criticalTree = NULL;

    initTable(&temperatureTable, 6);

    int n;
    int idSensors[] = {10, 17, 31, 5, 12, 99};
    float escale, drawnTemperature;
    float minTemperature = 20.0;
    float maxTemperature = 85.0;

    srand(time(NULL));

    printf("Enter the amount of random data you want to generate in the IDs: ");
    scanf("%d", &n);

    printf("Generating random data in the IDs...");
    for (int i=0; i < n; i++) {
        int idDrawn = idSensors[rand() % 6];

        escale = (float) rand() / RAND_MAX;
        drawnTemperature = minTemperature + (escale * (maxTemperature - minTemperature));

        enqueueData(buffer, drawnTemperature, idDrawn);
    }
    printf("%d Packets queued in buffer successfully");
}