#include <stdio.h>

void allIndex(int a[], int size, int x) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] == x) {
            if (found > 0) {
                printf(", ");
            }
            printf("%d", i);
            found++;
        }
    }
    if (found == 0) {
        printf("Phan tu khong co trong mang\n");
    } else {
        printf("\n");
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
    
    int x;
    printf("Nhap so can tim: ");
    scanf("%d", &x);
    
    allIndex(a, n, x);
    
    return 0;
}