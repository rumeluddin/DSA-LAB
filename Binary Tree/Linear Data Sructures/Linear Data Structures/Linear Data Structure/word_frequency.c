#include <stdio.h>

void count_frequency(char *str) {
    int freq[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0 && i != ' ') {
            printf("'%c' = %d\n", i, freq[i]);
        }
    }
}

int main() {
    char text[] = "hello world";

    printf("String: %s\n", text);
    printf("Frequency:\n");
    count_frequency(text);

    return 0;
}
