#include <stdio.h>

int sum(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + sum(n - 1);
}

int main() {
    int n;

    printf("Nhap mot so nguyen: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Khong hop le\n");
    } else {
        printf("%d\n", sum(n));
    }

    return 0;
}