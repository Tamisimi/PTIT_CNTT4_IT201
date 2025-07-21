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

int searchDFS(struct Node* root, int value) {
    if (root == NULL) return 0;
    if (root->data == value) return 1;
    return searchDFS(root->left, value) || searchDFS(root->right, value);
}

int main() {
    struct Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int valueToFind;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &valueToFind);
    if (searchDFS(root, valueToFind))
        printf("Tim thay %d trong cay\n", valueToFind);
    else
        printf("Khong tim thay %d trong cay\n", valueToFind);

    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);
    return 0;
}