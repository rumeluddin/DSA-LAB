#include <stdio.h>
#include <string.h>

void delete_substring(char *str, char *sub, char *result) {
    int i = 0;
    int j = 0;
    int sub_len = strlen(sub);

    while (str[i] != '\0') {
        if (strncmp(&str[i], sub, sub_len) == 0) {
            i += sub_len;
        } else {
            result[j++] = str[i++];
        }
    }

    result[j] = '\0';
}

int main() {
    char text[] = "I like apples and apples";
    char result[100];

    delete_substring(text, "apples", result);

    printf("Original: %s\n", text);
    printf("Result  : %s\n", result);

    return 0;
}
