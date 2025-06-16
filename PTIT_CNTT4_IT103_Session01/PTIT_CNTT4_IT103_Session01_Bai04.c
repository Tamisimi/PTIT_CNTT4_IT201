#include <stdio.h>

int sum1(int n) {
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += i;
    }
    return sum;
    //Độ phức tạp thời gian: O(n)
}

int sum2(int n) {
    return n * (n + 1) / 2;
    //Độ phức tạp thời gian: O(1)
}

int main() {
    int n = 10;

    int result1 = sum1(n);
    int result2 = sum2(n);

    printf("Tong bang vong lap: %d\n", result1);
    printf("Tong bang cong thuc: %d\n", result2);

    return 0;
}
