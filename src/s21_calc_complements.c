#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (s21_is_bad_matr(A) == SUCCESS) return MATRIX_INCORRECT;
  if (A->columns != A->rows) return CALCULATION_ERROR;

  s21_create_matrix(A->columns, A->rows, result);
  if (A->rows != 1) {
    matrix_t aux = {0};

    s21_create_matrix(A->rows, A->rows, &aux);
    for (int sign = 0, x = 0; x < A->rows; x += 1) {
      for (int y = 0; y < A->columns; y += 1) {
        s21_minor_calculator(A->matrix, aux.matrix, x, y, A->rows);
        sign = ((x + y) % 2 == 0) ? 1 : (-1);
        result->matrix[x][y] = sign * s21_determ_calculator(&aux, A->rows - 1);
      }
    }

    s21_remove_matrix(&aux);
  } else {
    result->matrix[0][0] = 1;
  }

  return MATRIX_OK;
}