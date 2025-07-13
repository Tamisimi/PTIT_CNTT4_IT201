#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    int front;
    int rear;
    int maxSize;
} Queue;

Queue* initQueue(int maxSize) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    
    if (queue == NULL) {
        printf("Khong the cap phat bo nho cho hang doi!\n");
        return NULL;
    }

    queue->array = (int*)malloc(maxSize * sizeof(int));

    if (queue->array == NULL) {
        printf("Khong the cap phat bo nho cho mang!\n");
        free(queue);
        return NULL;
    }

    queue->front = 0;
    queue->rear = -1;
    queue->maxSize = maxSize;

    return queue;
}

int main() {
    int maxSize = 5;
    Queue* queue = initQueue(maxSize);

    if (queue == NULL) {
        return 1;
    }
    
    printf("Hang doi duoc khoi tao voi:\n");
    printf("Kich thuoc toi da: %d\n", queue->maxSize);
    printf("Front: %d\n", queue->front);
    printf("Rear: %d\n", queue->rear);
    
    free(queue->array);
    free(queue);
    
    return 0;
}