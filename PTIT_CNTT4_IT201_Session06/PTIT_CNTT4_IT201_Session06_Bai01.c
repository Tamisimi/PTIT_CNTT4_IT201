#include <stdio.h>
#include <stdlib.h>

void binary(int n) {
    if (n == 0) {
        return;
    }
    binary(n / 2);
    printf("%d", n % 2);
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    if (n < 0 || n != 1) {
        printf("Input khong hop le\n");
        return 1;
    }
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    binary(n);
    printf("\n");
    return 0;
}
