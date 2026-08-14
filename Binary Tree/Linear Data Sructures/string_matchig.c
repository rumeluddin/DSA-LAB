#include <stdio.h>
#include <string.h>

void stringMatching(char text[], char pattern[]) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int found = 0;

    for (int i = 0; i <= textLen - patternLen; i++) {
        int j;

        for (j = 0; j < patternLen; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == patternLen) {
            printf("Pattern found at index: %d\n", i);
            found = 1;
        }
    }

    if (!found) {
        printf("Pattern not found in the text.\n");
    }
}

int main() {
    char text[100], pattern[50];

    printf("Enter Main Text: ");
    scanf("%s", text);

    printf("Enter Pattern to Match: ");
    scanf("%s", pattern);

    printf("\n--- Result ---\n");
    stringMatching(text, pattern);

    return 0;
}
