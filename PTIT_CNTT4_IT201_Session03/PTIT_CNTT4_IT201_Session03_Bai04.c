#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *a;
    int tong = 0, dem = 0;
    float trungBinh;

    do {
        printf("Nhap so luong phan tu (0 < n < 1000): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 1000);

    a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);

        if (a[i] % 2 == 0) {
            tong += a[i];
            dem++;
        }
    }

    if (dem == 0) {
        printf("Khong co so chan trong mang.\n");
    } else {
        trungBinh = (float)tong / dem;
        printf("Trung binh cong cac so chan trong mang la: %.2f\n", trungBinh);
    }

    free(a);

    return 0;
}
