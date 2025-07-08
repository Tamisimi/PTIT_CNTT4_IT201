#include <stdio.h>

struct Stack {
    int arr[100];
    int top;
    int maxSize;
};

struct Stack initStack(int size) {
    struct Stack s;
    s.top = -1;
    s.maxSize = size;
    return s;
}

int pop(struct Stack* s) {
    if (s->top == -1) {
        printf("No element in stack\n");
        return -1;
    }
    int value = s->arr[s->top];
    s->top--;
    return value;
}

void printStack(struct Stack s) {
    printf("stack={\n");
    printf("    elements: [");
    if (s.top >= 0) {
        for (int i = 0; i <= s.top; i++) {
            printf("%d", s.arr[i]);
            if (i < s.top) printf(", ");
        }
    }
    printf("],\n");
    printf("    top: %d,\n", s.top);
    printf("    cap: %d\n", s.maxSize);
    printf("}\n");
}

int main() {
    struct Stack myStack = initStack(5);
    myStack.arr[0] = 10;
    myStack.arr[1] = 20;
    myStack.arr[2] = 30;
    myStack.arr[3] = 40;
    myStack.arr[4] = 50;
    myStack.top = 4;

    printStack(myStack);
    printf("%d\n", pop(&myStack));

    pop(&myStack);
    pop(&myStack);
    pop(&myStack);
    pop(&myStack);

    printStack(myStack);
    pop(&myStack);

    return 0;
}