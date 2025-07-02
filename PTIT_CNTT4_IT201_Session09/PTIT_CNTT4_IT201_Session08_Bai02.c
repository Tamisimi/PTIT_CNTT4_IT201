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

void printNodes(struct Node* head) {
    struct Node* temp = head;
    int i = 1;
    while (temp != NULL) {
        printf("Node %d: %d\n", i, temp->data);
        temp = temp->next;
        i++;
    }
}

int main() {
    struct Node* list = createLinkedList();
    printList(list);
    printf("\n");
    printNodes(list);

    struct Node* temp = list;
    while (temp != NULL) {
        struct Node* p = temp;
        temp = temp->next;
        free(p);
    }

    return 0;
}