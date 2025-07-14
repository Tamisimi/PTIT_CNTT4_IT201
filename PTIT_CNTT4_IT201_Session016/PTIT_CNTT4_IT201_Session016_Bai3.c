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

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue* queue, int value) {
    Node* newNode = createNode(value);
    
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
    printf("}\n");
}

void peek(Queue* queue) {
    if (queue->front == NULL) {
        printf("queue is empty\n");
    } else {
        printf("%d\n", queue->front->data);
    }
}

int main() {
    Queue* queue = initQueue();
    
    printQueue(queue);
    peek(queue);
    
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 5);
    printQueue(queue);
    peek(queue);
    
    while (queue->front != NULL) {
        Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
    
    return 0;
}