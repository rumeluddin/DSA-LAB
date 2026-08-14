#include <stdio.h>
#include <string.h>

void count_frequency(const char *str) {
    int freq[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("'%c' : %d\n", i, freq[i]);
        }
    }
}

int main() {
    char text[] = "hello world";

    count_frequency(text);

    return 0;
}
