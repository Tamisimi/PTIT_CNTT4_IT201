#include <stdio.h>

int tong_cheo_chinh(int a[][1000], int m, int n) {
    int s = 0;
    int min = m < n ? m : n;
    for(int i = 0; i < min; i++) {
        s += a[i][i];
    }
    return s;
}

int tong_cheo_phu(int a[][1000], int m, int n) {
    int s = 0;
    int min = m < n ? m : n;
    for(int i = 0; i < min; i++) {
        s += a[i][n-1-i];
    }
    return s;
}

int main() {
    int m, n;

    printf("Nhap so hang (0 < m < 1000): ");
    scanf("%d", &m);
    printf("Nhap so cot (0 < n < 1000): ");
    scanf("%d", &n);

    if(m <= 0 || m >= 1000 || n <= 0 || n >= 1000) {
        printf("So hang va cot phai nam trong khoang (0, 1000)\n");
        return 1;
    }

    int a[1000][1000];

    // Nhập mảng
    printf("Nhap cac phan tu mang:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    int s1 = tong_cheo_chinh(a, m, n);
    int s2 = tong_cheo_phu(a, m, n);

    printf("Tong cheo chinh: %d\n", s1);
    printf("Tong cheo phu: %d\n", s2);

    return 0;
}
```