#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = (s21_is_bad_matr(A) || s21_is_bad_matr(B));

  if (status == 0 && (status = A->columns != B->rows ? 2 : 0) == 0) {
    if ((status = s21_create_matrix(A->rows, B->columns, result)) == 0) {
      for (int x = 0; x < A->rows; x += 1) {
        for (int y = 0; y < B->columns; y += 1) {
          for (int z = 0; z < B->rows; z += 1)
            result->matrix[x][y] += A->matrix[x][z] * B->matrix[z][y];
        }
      }
    }
  }

  return status;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = s21_is_bad_matr(A);

  if (status == 0) {
    if ((status = s21_create_matrix(A->rows, A->columns, result)) == 0) {
      for (int x = 0; x < A->rows; x += 1) {
        for (int y = 0; y < A->columns; y += 1)
          result->matrix[x][y] = A->matrix[x][y] * number;
      }
    }
  }

  return status;
}