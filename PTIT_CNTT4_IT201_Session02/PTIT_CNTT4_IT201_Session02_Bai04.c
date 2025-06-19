#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so phan tu cua mang ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("So phan tu khong hop le!\n");
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

    int position, value;
    printf("Nhap vi tri muon sua ");
    scanf("%d", &position);
    if (position < 0 || position >= n) {
        printf("Vi tri khong hop le\n");
        free(arr);
        return 1;
    }

    printf("Nhap gia tri moi: ");
    scanf("%d", &value);

    arr[position] = value;

    printf("Mang sau khi cap nhat: ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }

    free(arr);

    return 0;
}