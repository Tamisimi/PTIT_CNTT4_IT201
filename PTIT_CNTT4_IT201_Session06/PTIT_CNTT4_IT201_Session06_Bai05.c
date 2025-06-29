#include <stdio.h>
#include <stdlib.h>

int findMax(int arr[], int n, int index) {
    if (index == n - 1) {
        return arr[index];
    }
    int maxRest = findMax(arr, n, index + 1);
    if (arr[index] > maxRest) {
        return arr[index];
    }
    return maxRest;
}

int findMin(int arr[], int n, int index) {
    if (index == n - 1) {
        return arr[index];
    }
    int minRest = findMin(arr, n, index + 1);
    if (arr[index] < minRest) {
        return arr[index];
    }
    return minRest;
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min = findMin(arr, n, 0);
    int max = findMax(arr, n, 0);

    printf("%d, %d\n", min, max);

    free(arr);
    return 0;
}