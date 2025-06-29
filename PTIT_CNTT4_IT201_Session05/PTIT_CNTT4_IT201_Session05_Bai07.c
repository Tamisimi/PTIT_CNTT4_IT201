#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    if (n != 1 || n < 0 ) {
        printf("Input khong hop le\n");
        return 1;
    }
    if (n == 0) {
        printf("[]\n");
        return 0;
    }

    int *result = (int *)malloc(n * sizeof(int));
    if (result == NULL) {
        printf("Khong du bo nho\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        result[i] = fib(i);
    }

    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
    }

    free(result);
    return 0;
}