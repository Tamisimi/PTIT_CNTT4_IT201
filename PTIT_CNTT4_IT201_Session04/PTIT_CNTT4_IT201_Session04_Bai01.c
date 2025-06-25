#include <stdio.h>

int findFirst(int a[], int size, int x) {
    for (int i = 0; i < size; i++)
        if (a[i] == x)
            return i;
    return -1;
}

int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    int a[n];
    printf("Nhap mang: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int x;
    printf("Nhap so can tim: ");
    scanf("%d", &x);

    int pos = findFirst(a, n, x);
    if (pos >= 0)
        printf("%d\n", pos);
    else
        printf("Khong tim thay\n");

    return 0;
}