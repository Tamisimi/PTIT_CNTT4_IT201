#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so phan tu cua mang ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("So phan tu khong hop le\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Cap phat bo nho that bai\n");
        return 1;
    }

    printf("Nhap %d phan tu cua mang:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int position;
    printf("Nhap vi tri muon xoa ");
    scanf("%d", &position);

    if (position < 0 || position >= n) {
        printf("Khong hop le\n");
        free(arr);
        return 1;
    }

    for (int i = position; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    int *newArr = (int *)realloc(arr, (n - 1) * sizeof(int));
    if (newArr == NULL && n > 1) {
        printf("Cap phat bo nho moi that bai\n");
        free(arr);
        return 1;
    }
    arr = newArr;
    n--;

    printf("Mang sau khi xoa ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }

    free(arr);

    return 0;
}