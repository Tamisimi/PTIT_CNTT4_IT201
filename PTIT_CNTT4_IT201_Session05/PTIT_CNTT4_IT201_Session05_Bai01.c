#include <stdio.h>

void print(int n) {
    if (n == 0) return;
    print(n - 1);
    printf("%d ", n);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    if (n > 0) {
        print(n);
        printf("\n");
    } else {
        printf("Nhap so nguyen duong.\n");
    }

    return 0;
}
