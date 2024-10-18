#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (s21_is_bad_matr(A) == SUCCESS) return MATRIX_INCORRECT;
  if (A->columns != A->rows) return CALCULATION_ERROR;

  if (A->rows == 1)
    *result = A->matrix[0][0];
  else
    *result = s21_determ_calculator(A, A->rows);

  return MATRIX_OK;
}