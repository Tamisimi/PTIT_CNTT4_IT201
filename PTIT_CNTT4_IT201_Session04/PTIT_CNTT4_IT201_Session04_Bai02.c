#include <stdio.h>

int maxIndex(int a[], int size) {
    int max = a[0];
    int index = 0;
    for (int i = 1; i < size; i++)
        if (a[i] > max) {
            max = a[i];
            index = i;
        }
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
    
    int pos = maxIndex(a, n);
    printf("%d\n", pos);
    
    return 0;
}