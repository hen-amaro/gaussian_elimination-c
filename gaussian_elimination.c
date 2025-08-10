#include <stdlib.h>
#include <stdio.h>

//Matriz para estudo de caso
double M[3][6] = {
    {0, 3, -6, 6, 4, -5},
    {3, -7, 8, -5, 8, 9},
    {3, -9, 12, -9, 6, 15}
};

//Aplica o módulo dado um valor qualquer "x"
double modulo(double x) {
    if (x < 0)
        return -x;
    else
        return x;
}

// Troca os elementos da linha row1 com os da linha row2
void swapRows(double M[][6], int row1, int row2, int cols) {
    int j;
    double aux;
    for(j=0; j < cols; j++) {
        aux = M[row1][j];
        M[row1][j] = M[row2][j];
        M[row2][j] = aux;
    }
}

// Seleciona o pivô parcial na coluna "pivot_col", dentro das linhas de start_row até n-1
int selectPartialPivot(double M[][6], int start_row, int n, int pivot_col) {
    int i, pos = start_row;
    double maior = modulo(M[start_row][pivot_col]);
    for(i = start_row + 1; i < n; i++) {
        double abs_value = modulo(M[i][pivot_col]);
        if (abs_value > maior) {
            maior = abs_value;
            pos = i;
        }
    }
    return pos;
}

// Faz eliminação para zerar elementos abaixo do pivô
void eliminateBelowPivot(double M[][6], int pivot_row, int n, int pivot_col, int cols) {
    int i, j;
    for (i = pivot_row + 1; i < n; i++) {
        double m = M[i][pivot_col] / M[pivot_row][pivot_col];
        for (j = pivot_col; j < cols; j++) {
            M[i][j] = M[i][j] - m * M[pivot_row][j];
        }
    }
}

int main() {
    int n = 3;    // número de linhas
    int cols = 6; // número de colunas

    // Aplica eliminação de Gauss completa (forma escalonada)
    for (int pivot_col = 0, pivot_row = 0; pivot_col < cols - 1 && pivot_row < n; pivot_col++) {
        int pos = selectPartialPivot(M, pivot_row, n, pivot_col);
        
        // Se pivô é zero, pula essa coluna
        if (modulo(M[pos][pivot_col]) == 0) {
            continue;
        }

        // Troca para trazer o maior pivô para a posição atual
        if (pos != pivot_row) {
            swapRows(M, pivot_row, pos, cols);
        }

        // Elimina abaixo do pivô
        eliminateBelowPivot(M, pivot_row, n, pivot_col, cols);

        pivot_row++;
    }

    // Imprime matriz resultante
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%8.2f ", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}
