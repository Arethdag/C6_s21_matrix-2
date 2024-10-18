#include "s21_matrix.h"

void s21_minor_calculator(double **A, double **aux, int skipRow, int skipCol,
                          int size) {
  for (int row = 0, x = 0; row < size; row += 1) {
    for (int col = 0, y = 0; col < size; col += 1) {
      if (row != skipRow && col != skipCol) {
        aux[x][y++] = A[row][col];
        if (y == size - 1) {
          y = 0;
          x++;
        }
      }
    }
  }
}

double s21_determ_calculator(matrix_t *A, int size) {
  if (size == 1) return A->matrix[0][0];

  matrix_t aux = {0};
  double result = 0;

  s21_create_matrix(size, size, &aux);
  for (int sign = 1, x = 0; x < size; x += 1, sign *= (-1)) {
    s21_minor_calculator(A->matrix, aux.matrix, 0, x, size);
    result += sign * A->matrix[0][x] * s21_determ_calculator(&aux, size - 1);
  }

  s21_remove_matrix(&aux);
  return result;
}

int s21_is_bad_eq_matr(matrix_t *A, matrix_t *B) {
  int status = 1;

  if (s21_is_bad_matr(A) == 0) {
    if (s21_is_bad_matr(B) == 0)
      status = (A->rows == B->rows && A->columns == B->columns) ? 0 : 2;
  }

  return status;
}

int s21_is_bad_matr(matrix_t *A) {
  return (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0);
}
