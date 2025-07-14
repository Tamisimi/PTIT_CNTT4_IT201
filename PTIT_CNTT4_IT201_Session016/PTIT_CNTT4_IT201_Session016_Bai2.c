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

Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    int value;
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue* queue) {
    Node* newNode = createNode();
    
    if (queue->front == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void printQueue(Queue* queue) {
    printf("queue = {\n");
    printf("  front->");
    Node* current = queue->front;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf("->");
        }
        current = current->next;
    }
    printf("->NULL\n");
    
    printf("  rear->");
    if (queue->rear != NULL) {
        printf("%d->NULL\n", queue->rear->data);
    } else {
        printf("NULL\n");
    }
    printf("},\n");
}

int main() {
    Queue* queue = initQueue();
    
    printQueue(queue);
    
    enqueue(queue);
    printQueue(queue);
    
    enqueue(queue);
    enqueue(queue);
    printQueue(queue);
    
    enqueue(queue);
    printQueue(queue);
    
    while (queue->front != NULL) {
        Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
    
    return 0;
}