#include <stdio.h>

void sameIndex(int a[], int size) {
    int found = 0;
    for (int i = 0; i < size / 2; i++) {
        if (a[i] == a[size - 1 - i]) {
            printf("Cap doi xung: (%d, %d)\n", a[i], a[size - 1 - i]);
            found++;
        }
    }
    if (found == 0) {
        printf("Khong co phan tu doi xung\n");
    }
}

int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    int a[n];
    printf("Nhap mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sameIndex(a, n);

    return 0;
}