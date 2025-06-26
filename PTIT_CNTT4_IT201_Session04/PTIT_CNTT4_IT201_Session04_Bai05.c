#include <stdio.h>

void bubbleSort(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int a[], int size, int x) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x)
            return 1;
        if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}

int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    
    int a[n];
    printf("Nhap mang: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    bubbleSort(a, n);
    
    int x;
    printf("Nhap so can tim: ");
    scanf("%d", &x);
    
    if (binarySearch(a, n, x))
        printf("Phan tu co trong mang\n");
    else
        printf("Phan tu khong co trong mang\n");
    
    return 0;
}