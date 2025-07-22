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

void insertNode(struct Node* root, int value) {
    if (root == NULL) return;
    
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        if (current->left == NULL) {
            current->left = createNode(value);
            return;
        } else if (current->right == NULL) {
            current->right = createNode(value);
            return;
        } else {
            if (current->left != NULL) queue[rear++] = current->left;
            if (current->right != NULL) queue[rear++] = current->right;
        }
    }
}

void levelorder(struct Node* root) {
    if (root == NULL) return;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL) queue[rear++] = current->left;
        if (current->right != NULL) queue[rear++] = current->right;
    }
}

int main() {
    struct Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int value;
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    insertNode(root, value);

    printf("Cay sau khi them: ");
    levelorder(root);
    printf("\n");

    free(root->left->left);
    free(root->left->right);
    free(root->right);
    free(root->left);
    free(root);
    return 0;
}