#include <stdio.h>
#include <string.h>

struct Stack {
    char arr[100];
    int top;
    int maxSize;
};

struct Stack newStack(int size) {
    struct Stack s;
    s.top = -1;
    s.maxSize = size;
    return s;
}

void push(struct Stack *s, char element) {
    if (s->top < s->maxSize - 1) {
        s.top = s.top + 1;
        s.arr[s->top] = element;
    }
}

char pop(struct Stack *s) {
    if (s->top >= 0) {
        char element = s->arr[s->top];
        s.top = s.top - 1;
        return element;
    }
    return '\0';
}

int valid(char str[]) {
    int len = strlen(str);
    struct Stack s = newStack(len);

    for (int i = 0; i < len; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(&s, str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            char top = pop(&s);
            if ((str[i] == ')' && top != '(') ||
                (str[i] == ']' && top != '[') ||
                (str[i] == '}' && top != '{') ||
                top == '\0') {
                return 0;
                }
        }
    }

    if (s.top == -1) {
        return 1;
    }
    return 0;
}

int main() {
    char str[100];
    printf("Nhập biểu thức: ");
    scanf("%[^\n]", str);

    printf("\"%s\"\n", str);

    if (valid(str)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}