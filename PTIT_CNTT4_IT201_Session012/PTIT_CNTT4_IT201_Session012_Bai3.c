#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Lỗi: Không thể cấp phát bộ nhớ!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* createDoublyLinkedList(int n) {
    if (n <= 0) return NULL;
    
    Node* head = NULL;
    Node* tail = NULL;
    
    for (int i = 0; i < n; i++) {
        int data;
        printf("Nhập giá trị cho phần tử %d: ", i + 1);
        scanf("%d", &data);
        
        Node* newNode = createNode(data);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return head;
}

Node* appendNode(Node* head, int data) {
    Node* newNode = createNode(data);
    
    if (head == NULL) {
        return newNode;
    }
    
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
    newNode->prev = current;
    
    return head;
}

void printList(Node* head) {
    Node* current = head;
    
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) printf("<->");
    }
    printf("->NULL\n");
}

int main() {
    int n;
    printf("Nhập số lượng phần tử trong danh sách: ");
    scanf("%d", &n);
    
    Node* head = createDoublyLinkedList(n);
    printf("\nDanh sách ban đầu:\n");
    printList(head);
    
    int newData;
    printf("\nNhập số nguyên dương để thêm vào cuối danh sách: ");
    scanf("%d", &newData);
    
    head = appendNode(head, newData);
    printf("\nDanh sách sau khi thêm phần tử:\n");
    printList(head);
    
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}