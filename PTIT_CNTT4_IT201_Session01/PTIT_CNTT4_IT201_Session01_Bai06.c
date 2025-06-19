#include <stdio.h>

int main() {
    int a[] = {3, 5, 7, 3, 9, 3, 2, 5};
    int n = 8;
    int x = 3;
    int dem = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            dem++;
        }
    }

    printf("So lan xuat hien cua %d trong mang la: %d\n", x, dem);

    //Độ phức tạp thời gian: O(n)

    return 0;
}
