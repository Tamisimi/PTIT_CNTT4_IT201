#include <stdio.h>
#include <string.h>

void sortString(char str[]) {
    int len = strlen(str);
    int i, j;
    char temp;

    for (i = 0; i < len-1; i++) {
        for (j = 0; j < len-i-1; j++) {
            if (str[j] > str[j+1]) {
                temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}

int main() {
    char str[1000];

    fgets(str, sizeof(str), stdin);

    int len = strlen(str);
    if (str[len-1] == '\n') {
        str[len-1] = '\0';
        len--;
    }

    if (len == 0) {
        printf("Chuỗi không hợp lệ\n");
        return 1;
    }

    printf("str = \" %s \"\n", str);

    sortString(str);

    printf("str = \" %s \"\n", str);

    return 0;
}