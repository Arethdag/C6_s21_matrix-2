#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_arithmetic(A, B, result, 1);
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_arithmetic(A, B, result, 2);
}

int s21_arithmetic(matrix_t *A, matrix_t *B, matrix_t *result, int action) {
  int status = s21_is_bad_eq_matr(A, B);

  if (status == 0) {
    if ((status = s21_create_matrix(A->rows, A->columns, result)) == 0) {
      for (int x = 0; x < A->rows; x += 1) {
        for (int y = 0; y < A->columns; y += 1) {
          if (action == 1)
            result->matrix[x][y] = A->matrix[x][y] + B->matrix[x][y];
          else if (action == 2)
            result->matrix[x][y] = A->matrix[x][y] - B->matrix[x][y];
        }
      }
    }
  }

  return status;
}
