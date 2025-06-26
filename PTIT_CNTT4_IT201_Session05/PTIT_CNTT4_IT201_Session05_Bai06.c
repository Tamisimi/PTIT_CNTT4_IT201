#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int start, int end) {
    if (start >= end) {
        return 1;
    }
    if (str[start] != str[end]) {
        return 0;
    }
    return isPalindrome(str, start + 1, end - 1);
}

int main() { 
    char str[100];
    printf("Nhap mot chuoi: ");
    fgets(str, sizeof(str), stdin);
    
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    
    if (isPalindrome(str, 0, len - 1)) {
        printf("Palindrome valid\n");
    } else {
        printf("Palindrome invalid\n");
    }
    
    return 0;
}