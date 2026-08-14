#include <stdio.h>
#include <string.h>

int is_palindrome(const char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main() {
    char text1[] = "madam";
    char text2[] = "hello";

    if (is_palindrome(text1)) {
        printf("\"%s\" is a Palindrome\n", text1);
    } else {
        printf("\"%s\" is NOT a Palindrome\n", text1);
    }

    if (is_palindrome(text2)) {
        printf("\"%s\" is a Palindrome\n", text2);
    } else {
        printf("\"%s\" is NOT a Palindrome\n", text2);
    }

    return 0;
}
