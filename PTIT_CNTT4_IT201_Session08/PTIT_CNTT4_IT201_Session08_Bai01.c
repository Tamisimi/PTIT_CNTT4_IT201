#include <stdio.h>

void search(int arr[], int n, int val, int *pos) {
    *pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            *pos = i + 1;
            break;
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
        printf("vi tri thu %d\n", pos);
    } else {
        printf("Khong ton tai phan tu\n");
    }

    printf("Do phuc tap thoi gian:\n");
    printf("- Truong hop tot nhat: O(1)\n");
    printf("- Truong hop xau nhat: O(%d)\n", n);

    return 0;
}