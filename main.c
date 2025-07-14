#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 100

typedef struct Course {
    char codeCourse[MAX_LEN];
    char nameCourse[MAX_LEN];
    int credits;
}Course;

typedef struct Node {
    Course data;
    struct Node* next;
}Node;

typedef struct DNode {
    Course data;
    struct DNode* prev;
    struct DNode* next;
}DNode;

typedef struct  StackNode {
    Course data;
    struct StackNode* next;
}StackNode;

typedef struct Student {
    char name[MAX_LEN];
    struct Student* next;
}Student;

Node* createNode(Course course) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Fail to update");
        return NULL;
    }
    newNode->data = course;
    newNode->next = NULL;
    return newNode;
}

bool isDuplicate(Node* head, char* code) {
    Node* curr = head;
    while (curr != NULL) {
        if (strcmp(curr->data.codeCourse, code) == 0) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void print(Node* head) {
    Node* curr = head;
    if (curr == NULL) {
        return;
    }
    while (curr->next != NULL) {
        printf("Course: %s ,Name: %s ,Credits: %d\n",curr->data.nameCourse, curr->data.codeCourse, curr->data.credits);
        current = curr->next;
    }
}

void addCourse(Node** head) {
    Course course;
    printf("Enter Course Code: ");
    scanf("%s", course.codeCourse);
    getchar();
    if (isDuplicate(*head, course.codeCourse){
        printf("Duplicate Course Code");
        return;
    }
    printf("Enter Course Name: ");
    scanf("%s", course.nameCourse);
    getchar();
    printf("Enter Course Credits: ");
    scanf("%d", &course.credits);   
    getchar();
    Node* newNode = createNode(course);
    newNode->next = *head;
    *head = newNode;
    printf("Successfully added");
}

int main() {
    Node* head = NULL;

}