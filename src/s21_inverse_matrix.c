#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (s21_is_bad_matr(A) == SUCCESS) return MATRIX_INCORRECT;
  if (A->columns != A->rows) return CALCULATION_ERROR;

  double det = 0;
  int status = s21_determinant(A, &det);
  if (fabs(det) < 1e-6 || status != MATRIX_OK) return CALCULATION_ERROR;
  matrix_t aux = {0}, aux_transpose = {0};

  s21_calc_complements(A, &aux);
  s21_transpose(&aux, &aux_transpose);
  s21_create_matrix(A->rows, A->rows, result);

  for (int x = 0; x < A->rows; x += 1) {
    for (int y = 0; y < A->rows; y += 1) {
      result->matrix[x][y] = aux_transpose.matrix[x][y] / det;
    }
  }

  s21_remove_matrix(&aux_transpose);
  s21_remove_matrix(&aux);
  return MATRIX_OK;
}