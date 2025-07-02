#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int x) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = x;
    p->next = NULL;
    return p;
}

struct Node* createLinkedList() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf("->");
        }
        temp = temp->next;
    }
    printf("->NULL\n");
}

int searchList(struct Node* head, int x) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == x) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    struct Node* list = createLinkedList();
    printList(list);

    int x;
    scanf("%d", &x);

    if (searchList(list, x)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    struct Node* temp = list;
    while (temp != NULL) {
        struct Node* p = temp;
        temp = temp->next;
        free(p);
    }

    return 0;
}