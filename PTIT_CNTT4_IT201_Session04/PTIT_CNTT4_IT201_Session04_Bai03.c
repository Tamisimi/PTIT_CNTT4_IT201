#include <stdio.h>

int minIndex(int a[], int size) {
    int min = a[0];
    int index = 0;
    for (int i = 1; i < size; i++)
        if (a[i] < min) {
            min = a[i];
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
    
    int in = minIndex(a, n);
    printf("%d\n", in);
    
    return 0;
}