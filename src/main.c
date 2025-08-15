#include "utils.h"
#include "gaussian_elimination.h"
#include <stdlib.h>
#include <stdio.h>



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
