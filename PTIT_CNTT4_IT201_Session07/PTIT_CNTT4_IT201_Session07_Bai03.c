#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n, i;
    int arr[1000];
    
    scanf("%d", &n);
    
    if (n <= 0 || n >= 1000) {
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("before: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    insertionSort(arr, n);
    
    printf("after: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}