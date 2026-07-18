#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n = 3;
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Using malloc:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }

    n = 5;
    arr = (int *)realloc(arr, n * sizeof(int));

    printf("\n\nAfter realloc:\n");
    for (int i = 3; i < n; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    arr = (int *)calloc(4, sizeof(int));

    printf("\n\nUsing calloc:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d ", arr[i]);   
    }

    free(arr);  

    return 0;
}
