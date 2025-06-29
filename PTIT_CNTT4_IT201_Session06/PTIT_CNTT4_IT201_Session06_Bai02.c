#include <stdio.h>

int fib(int n) {
    if (n <= 1) {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

void printFibReverse(int n, int i) {
    if (i < 0) {
        return;
    }
    printf("%d", fib(i));
    if (i > 0) {
        printf(", ");
    }
    printFibReverse(n, i-1);
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le\n");
        return 0;
    }

    printFibReverse(n, n-1);
    printf("\n");

    return 0;
}
