#ifndef GAUSSIAN_ELIMINATION_H
#define GAUSSIAN_ELIMINATION_H

// Declaração da matriz global
extern double M[3][6];

// Protótipos das funções
void swapRows(double M[][6], int row1, int row2, int cols);
int selectPartialPivot(double M[][6], int start_row, int n, int pivot_col);
void eliminateBelowPivot(double M[][6], int pivot_row, int n, int pivot_col, int cols);

#endif
