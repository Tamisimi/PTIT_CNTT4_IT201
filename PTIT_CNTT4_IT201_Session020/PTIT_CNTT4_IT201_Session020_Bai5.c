#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int findMaxValue(struct Node* root) {
    if (root == NULL) return INT_MIN;
    int maxLeft = findMaxValue(root->left);
    int maxRight = findMaxValue(root->right);
    return (root->data > maxLeft && root->data > maxRight) ? root->data : 
           (maxLeft > maxRight ? maxLeft : maxRight);
}

int main() {
    struct Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int maxValue = findMaxValue(root);
    printf("Gia tri lon nhat trong cay: %d\n", maxValue);

    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);
    return 0;
}