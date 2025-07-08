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

int main() {
    struct Stack myStack = initStack(5);
    printf("Số phần tử: %d\n", myStack.maxSize);
    printf("Top hiện tại: %d\n", myStack.top);
    return 0;
}