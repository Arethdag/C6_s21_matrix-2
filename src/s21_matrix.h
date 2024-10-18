#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define MATRIX_OK 0
#define MATRIX_INCORRECT 1
#define CALCULATION_ERROR 2
#define MATRIX_ALLOC_FAIL 3

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int s21_is_bad_matr(matrix_t *A);
double s21_determ_calculator(matrix_t *A, int size);
int s21_is_bad_eq_matr(matrix_t *A, matrix_t *B);
int s21_arithmetic(matrix_t *A, matrix_t *B, matrix_t *result, int action);
void s21_minor_calculator(double **A, double **aux, int skipRow, int skipCol,
                          int size);

#endif  // SRC_S21_MATRIX_H_
