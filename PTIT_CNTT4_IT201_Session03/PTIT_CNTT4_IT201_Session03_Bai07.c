#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    
    printf("Nhap so luong phan tu n (0 < n < 1000): ");
    scanf("%d", &n);
    
    if(n <= 0 || n >= 1000) {
        printf("So phan tu n phai nam trong khoang (0, 1000)\n");
        return 1;
    }
    
    int *arr = (int *)malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Khong cap phat duoc bo nho!\n");
        return 1;
    }
    
    printf("Nhap %d phan tu cua mang:\n", n);
    for(int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("Nhap so luong phan tu them m: ");
    scanf("%d", &m);
    
    if(m < 0 || n + m >= 1000) {
        printf("So phan tu sau khi them phai nho hon 1000\n");
        free(arr);
        return 1;
    }
    
    int *new_arr = (int *)realloc(arr, (n + m) * sizeof(int));
    if(new_arr == NULL) {
        printf("Khong cap phat duoc bo nho!\n");
        free(arr);
        return 1;
    }
    arr = new_arr;
    
    printf("Nhap %d phan tu them:\n", m);
    for(int i = n; i < n + m; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("Mang sau khi them %d phan tu:\n", m);
    for(int i = 0; i < n + m; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    
    return 0;
}