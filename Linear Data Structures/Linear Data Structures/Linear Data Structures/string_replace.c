#include <stdio.h>
#include <string.h>

void replace_substring(const char *str, const char *old_sub, const char *new_sub, char *result) {
    int i = 0;
    int j = 0;
    int old_len = strlen(old_sub);
    int new_len = strlen(new_sub);

    while (str[i] != '\0') {
        if (strncmp(&str[i], old_sub, old_len) == 0) {
            strcpy(&result[j], new_sub);
            j += new_len;
            i += old_len;
        } else {
            result[j++] = str[i++];
        }
    }

    result[j] = '\0';
}

int main() {
    char text[] = "I like apples and apples";
    char result[100];

    replace_substring(text, "apples", "bananas", result);

    printf("Original: %s\n", text);
    printf("Result  : %s\n", result);

    return 0;
}
