#include <stdio.h>

int sum(int first, int second) {
    if (first > second) {
        return 0;
    }
    return first + sum(first + 1, second);
}

int main() {
    int num1, num2;
    printf("Nhap hai so nguyen duong: ");
    scanf("%d %d", &num1, &num2);
    if (num1 <= 0 || num2 <= 0) {
        printf("Khong hop le\n");
    } else {
        printf("%d\n", sum(num1, num2));
    }
    return 0;
}

