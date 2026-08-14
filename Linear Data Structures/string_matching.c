#include <stdio.h>
#include <string.h>

void pattern_matching(const char *text, const char *pattern) {
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    int found = 0;

    for (int i = 0; i <= text_len - pattern_len; i++) {
        int j;
        for (j = 0; j < pattern_len; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == pattern_len) {
            printf("Pattern found at index: %d\n", i);
            found = 1;
        }
    }

    if (!found) {
        printf("Pattern not found.\n");
    }
}

int main() {
    char text[] = "AABAACAADAABAABA";
    char pattern[] = "AABA";

    printf("Text   : %s\n", text);
    printf("Pattern: %s\n\n", pattern);

    pattern_matching(text, pattern);

    return 0;
}
