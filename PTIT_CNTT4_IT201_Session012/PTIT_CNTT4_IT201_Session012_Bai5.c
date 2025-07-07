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

void printList(Node* head) {
    Node* current = head;
    printf("Danh sách liên kết đôi: ");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf("<->");
        }
        current = current->next;
    }
    printf("->NULL\n");
}

Node* deleteNodesWithValue(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;

        if (current->data == value) {
            if (current == head) {
                head = current->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            }
            else {
                current->prev->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
            }
            free(current);
        }
        current = next;
    }
    return head;
}

int main() {
    int n, value;
    printf("Nhập số lượng phần tử trong danh sách: ");
    scanf("%d", &n);

    Node* head = createDoublyLinkedList(n);
    printList(head);

    printf("Nhập giá trị cần xóa: ");
    scanf("%d", &value);

    head = deleteNodesWithValue(head, value);
    printList(head);

    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}