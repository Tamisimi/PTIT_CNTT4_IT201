#include <stdio.h>

void search(int arr[], int n, int val, int *pos) {
    int left = 0;
    int right = n - 1;
    *pos = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == val) {
            *pos = mid + 1;
            break;
        }
        if (arr[mid] < val) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le!\n");
        return 0;
    }

    int arr[1000];
    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int val;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &val);

    int pos;
    search(arr, n, val, &pos);

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf(" ]\n");

    if (pos != -1) {
        printf("phan tu vi tri thu %d\n", pos);
    } else {
        printf("Khong ton tai phan tu\n");
    }

    return 0;
}