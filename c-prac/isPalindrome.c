#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char* str) {
    int length = strlen(str);
    int start = 0;
    int end = length-1;
    while (start<end) {
        if(strncmp(&str[start], &str[end], 1)==0) {
            end--;
            start++;
        }
        else
            return 0;
    }
    return 1;
}


int main() {
    char *str = "10fjf01";
    printf("This is the result: %d", isPalindrome(str));
    return 0;
}
