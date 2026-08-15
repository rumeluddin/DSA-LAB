#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void findSaddlePoint(int matrix[MAX][MAX], int rows, int cols) {
    bool found = false;

    for (int i = 0; i < rows; i++) {
        int min_row = matrix[i][0];
        int col_ind = 0;

        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] < min_row) {
                min_row = matrix[i][j];
                col_ind = j;
            }
        }

        bool isSaddle = true;
        for (int k = 0; k < rows; k++) {
            if (matrix[k][col_ind] > min_row) {
                isSaddle = false;
                break;
            }
        }

        if (isSaddle) {
            printf("Saddle Point found at Index (%d, %d): %d\n", i, col_ind, min_row);
            found = true;
        }
    }

    if (!found) {
        printf("No Saddle Point found.\n");
    }
}

int main() {
    int rows = 3, cols = 3;

    int matrix[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    findSaddlePoint(matrix, rows, cols);

    return 0;
}
