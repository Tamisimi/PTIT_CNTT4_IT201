#include <stdio.h>
#include <stdlib.h>

int tinhTongCheoChinh(int **a, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i][i];
    }
    return tong;
}

int tinhTongCheoPhu(int **a, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i][n - 1 - i];
    }
    return tong;
}

int main() {
    int rows, cols;

    do {
        printf("Nhap so hang (0 < rows < 1000): ");
        scanf("%d", &rows);
    } while (rows <= 0 || rows >= 1000);

    do {
        printf("Nhap so cot (0 < cols < 1000): ");
        scanf("%d", &cols);
    } while (cols <= 0 || cols >= 1000);

    if (rows != cols) {
        printf("Chi tinh tong duoc cheo khi ma tran vuong (rows = cols).\n");
        return 1;
    }

    int **a = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        a[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    int tongChinh = tinhTongCheoChinh(a, rows);
    int tongPhu = tinhTongCheoPhu(a, rows);

    printf("Tong duong cheo chinh: %d\n", tongChinh);
    printf("Tong duong cheo phu: %d\n", tongPhu);

    for (int i = 0; i < rows; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}
