#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void enqueue(Queue* queue, int value) {
    if (queue->rear == queue->maxSize - 1) {
        printf("queue is full\n");
        return;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
}

int dequeue(Queue* queue) {
    if (queue->rear < queue->front) {
        printf("queue is empty\n");
        return -1;
    }

    int value = queue->array[queue->front];
    queue->front++;
    return value;
}

void printQueue(Queue* queue) {
    printf("queue = {\n");
    printf("   array = [");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d", queue->array[i]);
        if (i < queue->rear) printf(", ");
    }
    printf("],\n");
    printf("   front = %d,\n", queue->front);
    printf("   rear = %d,\n", queue->rear);
    printf("   capacity = %d\n", queue->maxSize);
    printf("}\n");
}

int main() {
    Queue* queue1 = initQueue(5);
    if (queue1 == NULL) {
        return 1;
    }
    printQueue(queue1);
    dequeue(queue1);
    printQueue(queue1);
    printf("\n");

    Queue* queue2 = initQueue(5);
    if (queue2 == NULL) {
        free(queue1->array);
        free(queue1);
        return 1;
    }
    enqueue(queue2, 1);
    enqueue(queue2, 2);
    enqueue(queue2, 5);
    printQueue(queue2);
    int value = dequeue(queue2);
    printf("return value = %d;\n", value);
    printQueue(queue2);

    free(queue1->array);
    free(queue1);
    free(queue2->array);
    free(queue2);

    return 0;
}