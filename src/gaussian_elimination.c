#include <stdio.h>
#include "gaussian_elimination.h"
#include "utils.h"

// Definição da matriz global
double M[3][6] = {
    {0, 3, -6, 6, 4, -5},
    {3, -7, 8, -5, 8, 9},
    {3, -9, 12, -9, 6, 15}
};

void swapRows(double M[][6], int row1, int row2, int cols) {
    int j;
    double aux;
    for(j = 0; j < cols; j++) {
        aux = M[row1][j];
        M[row1][j] = M[row2][j];
        M[row2][j] = aux;
    }
}

int selectPartialPivot(double M[][6], int start_row, int n, int pivot_col) {
    int i, pos = start_row;
    double maior = modulo(M[start_row][pivot_col]);
    for(i = start_row + 1; i < n; i++) {
        double abs_value = modulo(M[i][pivot_col]);
        if(abs_value > maior) {
            maior = abs_value;
            pos = i;
        }
    }
    return pos;
}

void eliminateBelowPivot(double M[][6], int pivot_row, int n, int pivot_col, int cols) {
    int i, j;
    for(i = pivot_row + 1; i < n; i++) {
        double m = M[i][pivot_col] / M[pivot_row][pivot_col];
        for(j = pivot_col; j < cols; j++) {
            M[i][j] = M[i][j] - m * M[pivot_row][j];
        }
    }
}
