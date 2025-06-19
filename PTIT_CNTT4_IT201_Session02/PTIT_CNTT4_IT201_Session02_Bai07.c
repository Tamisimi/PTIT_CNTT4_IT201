#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so phan tu cua mang ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return 1;
    }

    printf("Nhap %d phan tu cua mang:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Nhap so nguyen de tim cap phan tu co tong bang: ");
    scanf("%d", &target);

    int found = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("%d,%d\n", arr[i], arr[j]);
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        printf("Khong tim thay\n");
    }

    free(arr);
    return 0;
}