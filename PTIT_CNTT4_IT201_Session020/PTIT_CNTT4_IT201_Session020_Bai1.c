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

int main() {
    int data;
    printf("Nhap gia tri cho nut moi: ");
    scanf("%d", &data);
    struct Node* newNode = createNode(data);
    struct Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    printf("node = {\n   data: %d,\n   left->NULL,\n   right->NULL\n}", newNode->data);
    free(newNode);
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);
    return 0;
}