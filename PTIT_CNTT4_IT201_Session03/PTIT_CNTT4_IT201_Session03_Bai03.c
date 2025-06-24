#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    int tong = 0, dem = 0;
    float trungBinh;

    do {
        printf("Nhap so luong phan tu (0 < n < 1000): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 1000);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Loi cap phat bo nho.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);

        if (arr[i] % 2 == 0) {
            tong += arr[i];
            dem++;
        }
    }

    if (dem == 0) {
        printf("Khong co so chan trong mang.\n");
    } else {
        trungBinh = (float)tong / dem;
        printf("Trung binh cong cac so chan trong mang la: %.2f\n", trungBinh);
    }

    free(arr);

    return 0;
}
