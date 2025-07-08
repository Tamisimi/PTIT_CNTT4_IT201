#include <stdio.h>

struct Stack {
    int arr[100];
    int top;
    int maxSize;
};

struct Stack newStack(int size) {
    struct Stack s;
    s.top = -1;
    s.maxSize = size;
    return s;
}

void push(struct Stack *s, int element) {
    if (s->top < s->maxSize - 1) {
        s->top = s->top + 1;
        s->arr[s->top] = element;
    } else {
        printf("Ngăn xếp đầy, không thêm được!\n");
    }
}

int pop(struct Stack *s) {
    if (s->top >= 0) {
        int element = s->arr[s->top];
        s->top = s->top - 1;
        return element;
    } else {
        printf("No element in stack\n");
        return -1;
    }
}

void printStack(struct Stack *s) {
    printf("stack={\n");
    printf("    elements: [");
    for (int i = 0; i <= s->top; i++) {
        printf("%d", s->arr[i]);
        if (i < s->top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", s->top);
    printf("    cap: %d\n", s->maxSize);
    printf("}\n");
}

void display(struct Stack *s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->arr[i]);
    }
}

int main() {
    struct Stack myStack = newStack(5);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    push(&myStack, 40);
    push(&myStack, 50);

    printStack(&myStack);

    display(&myStack);

    return 0;
}