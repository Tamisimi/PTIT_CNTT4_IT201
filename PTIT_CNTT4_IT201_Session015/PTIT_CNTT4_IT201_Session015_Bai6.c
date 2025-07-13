#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* arr;
    int front;
    int rear;
    int size;
} Queue;

Queue* initQ(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Khong the cap phat bo nho cho hang doi!\n");
        return NULL;
    }

    q->arr = (int*)malloc(size * sizeof(int));
    if (q->arr == NULL) {
        printf("Khong the cap phat bo nho cho mang!\n");
        free(q);
        return NULL;
    }

    q->front = 0;
    q->rear = -1;
    q->size = size;

    return q;
}

void push(Queue* q, int val) {
    if (q->rear == q->size - 1) {
        return;
    }
    q->rear++;
    q->arr[q->rear] = val;
}

int pop(Queue* q) {
    if (q->rear < q->front) {
        return -1;
    }

    int val = q->arr[q->front];
    q->front++;
    return val;
}

bool checkInc(Queue* q, int n) {
    if (n <= 1) return true;

    int prev = pop(q);
    while (q->front <= q->rear) {
        int curr = pop(q);
        if (curr - prev != 1) {
            return false;
        }
        prev = curr;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    Queue* q = initQ(n);
    if (q == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        push(q, val);
    }

    bool res = checkInc(q, n);
    printf("%s\n", res ? "True" : "False");

    free(q->arr);
    free(q);

    return 0;
}