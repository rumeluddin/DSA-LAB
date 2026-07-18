#include <stdio.h>

int sumSeries(int n) {
    if (n == 0)
        return 0;
    return n + sumSeries(n - 1);
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Sum = %d\n", sumSeries(n));

    return 0;
}
