#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Stack stack;

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void createStack() {
    stack.top = NULL;
}

int main() {
    createStack();
    if (stack.top == NULL) {
        printf("Ngăn xếp đã được khởi tạo thành công với top = NULL\n");
    }
    return 0;
}