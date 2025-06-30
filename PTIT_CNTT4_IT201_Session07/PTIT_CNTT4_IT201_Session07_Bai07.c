#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compare(int a, int b) {
    if (a < 0) {
        if (b >= 0) return 1;
        return a < b;
    }
    if (a == 0) {
        if (b > 0) return 1;
        if (b < 0) return 0;
        return 0;
    }
    if (b <= 0) return 0;
    return a < b;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (!compare(arr[j], arr[j+1])) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int n, i;
    int arr[1000];
    
    scanf("%d", &n);
    
    if (n <= 0 || n >= 1000) {
        printf("Số lượng phần tử không hợp lệ\n");
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("[");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n-1) printf(", ");
    }
    printf("]\n");
    
    bubbleSort(arr, n);
    
    printf("[");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n-1) printf(", ");
    }
    printf("]\n");
    
    return 0;
}