#include <stdio.h>

int main() {
    int array[] = {3, 1, 3, 2, 1, 3, 2, 2, 2};
    int size = 9;
    int i, maxCount = 0, most = array[0];

    for (i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (array[i] == array[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            most = array[i];
        }
    }

    printf("Phan tu xuat hien nhieu nhat la: %d (xuat hien %d lan)\n", most, maxCount);

    //Độ phức tạp thời gian: O(n^2)

    return 0;
}
