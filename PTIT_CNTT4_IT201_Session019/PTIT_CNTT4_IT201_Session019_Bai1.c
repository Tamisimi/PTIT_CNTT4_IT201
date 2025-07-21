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
    struct Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    printf("Root: %d\n", root->data);
    printf("Left of root: %d\n", root->left->data);
    printf("Right of root: %d\n", root->right->data);
    printf("Left of left: %d\n", root->left->left->data);
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);
    return 0;
}