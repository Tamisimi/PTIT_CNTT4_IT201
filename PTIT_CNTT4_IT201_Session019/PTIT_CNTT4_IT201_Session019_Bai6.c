#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int searchBFS(struct Node* root, int value) {
    if (root == NULL) return 0;
    
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        if (current->data == value) return 1;
        if (current->left != NULL) queue[rear++] = current->left;
        if (current->right != NULL) queue[rear++] = current->right;
    }
    return 0;
}

int main() {
    struct Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int valueToFind;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &valueToFind);
    if (searchBFS(root, valueToFind))
        printf("Tim thay %d trong cay\n", valueToFind);
    else
        printf("Khong tim thay %d trong cay\n", valueToFind);

    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);
    return 0;
}