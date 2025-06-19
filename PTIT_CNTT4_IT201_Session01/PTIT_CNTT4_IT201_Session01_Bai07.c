#include <stdio.h>

int main() {
    int a[] = {3, 7, 4, 2, 9, 5, 7};
    int n = 7;
    int i, j;

    int duplicate1 = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                duplicate1 = 1;
                break;
            }
        }
        if (duplicate1 == 1) break;
    }

    if (duplicate1 == 1)
        printf("Mang co phan tu trung lap\n");
    else
        printf("Mang khong co phan tu trung lap\n");

    //Độ phức tạp thời gian: O(n^2)

    int mark[1001] = {0};
    int duplicate2 = 0;

    for (i = 0; i < n; i++) {
        if (mark[a[i]] == 1) {
            duplicate2 = 1;
            break;
        }
        mark[a[i]] = 1;
    }

    if (duplicate2 == 1)
        printf("Mang co phan tu trung lap\n");
    else
        printf("Mang khong co phan tu trung lap\n");

    //Độ phức tạp thời gian:O(n)

    return 0;
}


checkDupSubArray(int numbers[], int size) {
//B1: Tạo ra mảng phụ để kiểm tra xem phần tử trùng lặp
int seenNumbers[1001];
//B2: Xét từng phần tử
for(int i = 0; i < size; i++{
	//B3: Kiểm tra xem phần tử được tìm thấy chưa
	if(seenNumbers(numbers[i]) == 1 {
		//B4: Nếu đã từng được tìm thấy thì trả về giá trị 1
		return 1;
	}
}