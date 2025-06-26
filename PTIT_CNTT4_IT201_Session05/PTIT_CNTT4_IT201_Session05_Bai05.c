#include <stdio.h>

int arraySum(int arr[], int size) {
    if (size <= 0) {
        return 0;
    }
    return arr[size - 1] + arraySum(arr, size - 1);
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Khong hop le\n");
        return 0;
    }

    int arr[100];
    printf("Nhap %d phan tu cua mang: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", arraySum(arr, n));
    return 0;
}