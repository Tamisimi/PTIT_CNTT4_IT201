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

int main() {
    struct Stack myStack = newStack(5);
    int num;

    printf("Nhập các phần tử:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &num);
        push(&myStack, num);
    }

    printf("stack={\n");
    printf("    elements: [");
    for (int i = 0; i <= myStack.top; i++) {
        printf("%d", myStack.arr[i]);
        if (i < myStack.top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", myStack.top);
    printf("    cap: %d\n", myStack.maxSize);
    printf("}\n");

    return 0;
}