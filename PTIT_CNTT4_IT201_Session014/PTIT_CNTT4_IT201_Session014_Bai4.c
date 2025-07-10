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

void push(struct Stack* s, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = s->top;
    s->top = newNode;
}

void printStack(struct Stack* s) {
    printf("stack = {\n");
    if (s->top == NULL) {
        printf("   NULL\n");
    } else {
        struct Node* current = s->top;
        while (current != NULL) {
            printf("   %d", current->data);
            if (current->next != NULL) {
                printf("->");
            }
            current = current->next;
        }
        printf("->NULL\n");
    }
    printf("}\n");
}

int pop(struct Stack* s) {
    if (s->top == NULL) {
        printf("Ngăn xếp trống\n");
        return -1;
    }
    struct Node* temp = s->top;
    int data = temp->data;
    s->top = temp->next;
    free(temp);
    return data;
}

int main() {
    createStack();
    
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    
    printStack(&stack);
    
    pop(&stack);
    
    printStack(&stack);
    
    struct Stack stack2;
    createStack();
    
    printStack(&stack2);
    
    pop(&stack2);
    
    return 0;
}