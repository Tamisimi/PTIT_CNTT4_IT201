#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Số lượng phần tử không được âm\n");
        return 0;
    }
    if (n == 0) {
        printf("Số lượng phần tử phải lớn hơn 0\n");
        return 0;
    }
    if (n >= 1000) {
        printf("Số lượng phần tử phải nhỏ hơn 1000\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("Số thứ %d = %d\n", i + 1, arr[i]);
    }

    free(arr);

    return 0;
}