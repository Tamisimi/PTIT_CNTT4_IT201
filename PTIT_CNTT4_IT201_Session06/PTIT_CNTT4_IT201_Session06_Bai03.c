#include <stdio.h>

int sum(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sum(n / 10);
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Input khong hop le\n");
        return 0;
    }
    
    printf("%d\n", sum(n));
    
    return 0;
}