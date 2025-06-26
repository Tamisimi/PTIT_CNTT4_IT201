#include <stdio.h>

unsigned int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &n);
    if (n < 0 || n > 12) {
        printf("Khong hop le\n");
    } else {
        printf("%u\n", factorial(n));
    }
    return 0;
}