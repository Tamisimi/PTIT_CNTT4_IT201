#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* initQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int main() {
    Queue* queue = initQueue();
    if (queue->front == NULL && queue->rear == NULL) {
        printf("Hang doi khoi tao thanh cong!\n");
    } else {
        printf("Khoi tao hang doi that bai!\n");
    }
    free(queue);
    return 0;
}