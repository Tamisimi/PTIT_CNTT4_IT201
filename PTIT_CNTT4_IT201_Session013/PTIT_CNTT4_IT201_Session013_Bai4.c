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

void printStack(struct Stack s) {
    if (s.top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("stack={\n");
    printf("    elements: [");
    for (int i = 0; i <= s.top; i++) {
        printf("%d", s.arr[i]);
        if (i < s.top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", s.top);
    printf("    cap: %d\n", s.maxSize);
    printf("}\n");
    for (int i = s.top; i >= 0; i--) {
        printf("%d\n", s.arr[i]);
    }
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
    return 0;
}