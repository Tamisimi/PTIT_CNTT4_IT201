#include <stdio.h>

int lastIndex(int a[], int size, int x) {
    int index = -1;
    for (int i = 0; i < size; i++)
        if (a[i] == x)
            index = i;
    return index;
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

    int pos = lastIndex(a, n, x);
    if (pos >= 0)
        printf("%d\n", pos);
    else
        printf("Khong tim thay phan tu\n");

    return 0;
}