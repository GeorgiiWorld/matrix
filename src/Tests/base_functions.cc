#include "matrix.h"

TEST(EqualMatrix, normal_true) {
  double data[] = {1, 2, 3, 4, 5, 6.5678901, 7, 8, 9};
  double data_res[] = {1, 2, 3, 4, 5, 6.5678901, 7, 8, 9};
  Matrix matrix(3, 3);
  Matrix matrix_res(3, 3);
  FillDataInMatrix(matrix, data);
  FillDataInMatrix(matrix_res, data_res);

  bool res = matrix.EqMatrix(matrix_res);

  ASSERT_EQ(res, true);
}

TEST(EqualMatrix, normal_false) {
  double data[] = {1, 2, 3, 4, 5, 6.5678907, 7, 8, 9};
  double data_res[] = {1, 2, 3, 4, 5, 6.5678901, 7, 8, 9};
  Matrix matrix(3, 3);
  Matrix matrix_res(3, 3);
  FillDataInMatrix(matrix, data);
  FillDataInMatrix(matrix_res, data_res);

  bool res = matrix.EqMatrix(matrix_res);

  ASSERT_EQ(res, false);
}

TEST(SumMatrix, base) {
  Matrix matrix;
  Matrix matrix_2;
  matrix_2.SumMatrix(matrix);
  ASSERT_EQ(matrix_2.EqMatrix(matrix), true);
}

TEST(SumMatrix, normal) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_res[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                       12,  24, 22,  42,   30,   14,   16, 4};
  Matrix matrix(4, 4);
  Matrix matrix_res(4, 4);
  FillDataInMatrix(matrix, data);
  FillDataInMatrix(matrix_res, data_res);

  matrix.SumMatrix(matrix);

  ASSERT_EQ(matrix_res.EqMatrix(matrix), true);
}

TEST(SumMatrix, fail_cols) {
  Matrix matrix(4, 3);
  Matrix matrix_2(4, 4);

  EXPECT_THROW(matrix.SumMatrix(matrix_2), std::invalid_argument);
}

TEST(SumMatrix, fail_rows) {
  Matrix matrix(3, 4);
  Matrix matrix_2(4, 4);

  EXPECT_THROW(matrix.SumMatrix(matrix_2), std::invalid_argument);
}

TEST(SubMatrix, base) {
  Matrix matrix(5, 5);
  Matrix matrix2(5, 5);

  matrix2.SumMatrix(matrix);

  ASSERT_EQ(matrix2.EqMatrix(matrix), true);
}

TEST(SubMatrix, normal) {
  double data[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                   12,  24, 22,  42,   30,   14,   16, 4};
  double result[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                     6,   12, 11,  21,  15,  7,   8, 2};
  Matrix matrix(4, 4);
  Matrix matrix_res(4, 4);
  FillDataInMatrix(matrix, data);
  FillDataInMatrix(matrix_res, result);

  matrix.SubMatrix(matrix_res);

  ASSERT_EQ(matrix_res.EqMatrix(matrix), true);
}

TEST(SubMatrix, fail_cols) {
  Matrix matrix(4, 3);
  Matrix matrix2(4, 4);

  EXPECT_THROW(matrix.SubMatrix(matrix2), std::invalid_argument);
}

TEST(SubMatrix, fail_rows) {
  Matrix matrix(3, 4);
  Matrix matrix2(4, 4);

  EXPECT_THROW(matrix.SubMatrix(matrix2), std::invalid_argument);
}

TEST(MulNumber, base) {
  Matrix matrix;
  matrix.MulNumber(-2);
  ASSERT_EQ(matrix(0, 0), 0);
}

TEST(MulNumber, normal) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  double data_res[] = {2,  4,  6,  8,  10, 12, 14, 16,
                       18, 20, 22, 24, 26, 28, 30, 32};
  Matrix matrix(4, 4);
  Matrix matrix_res(4, 4);
  FillDataInMatrix(matrix, data);
  FillDataInMatrix(matrix_res, data_res);

  matrix.MulNumber(2);

  ASSERT_EQ(matrix_res.EqMatrix(matrix), true);
}

TEST(MulMatrix, normal) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_2[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                     12,  24, 22,  42,   30,   14,   16, 4};
  double data_res[] = {315.02, 224.6,  227.88, 213.82, 310.56, 276.98,
                       270.56, 370.96, 948,    733.2,  714.8,  768,
                       289.8,  368.2,  366,    659.8};
  Matrix matrix_1(4, 4);
  Matrix matrix_2(4, 4);
  Matrix matrix_result(4, 4);
  FillDataInMatrix(matrix_1, data);
  FillDataInMatrix(matrix_2, data_2);
  FillDataInMatrix(matrix_result, data_res);

  matrix_2.MulMatrix(matrix_1);

  bool result = matrix_result.EqMatrix(matrix_2);
  ASSERT_EQ(result, true);
}

TEST(MulMatrix, normal_diff) {
  double data[] = {4, 24, 22, 42, 3.4, 8.1, 7, 23, 0, 1, 3, 3.33};
  double data_2[] = {1, 7, 23, 5, 4, 3, 3.44, 23, 5, 3.6, 3, 7};
  double data_res[] = {210, 179.2, 240.56, 726, 96.1,  333.36, 1001.996, 344.9,
                       99,  118,   240.12, 564, 29.65, 27.988, 43.31,    97.31};
  Matrix matrix_1(4, 3);
  Matrix matrix_2(3, 4);
  Matrix matrix_result(4, 4);
  FillDataInMatrix(matrix_1, data);
  FillDataInMatrix(matrix_2, data_2);
  FillDataInMatrix(matrix_result, data_res);

  matrix_1.MulMatrix(matrix_2);

  bool result = matrix_result.EqMatrix(matrix_1);

  ASSERT_EQ(result, true);
}

TEST(MulMatrix, fail) {
  Matrix matrix(3, 4);
  Matrix matrix2(4, 4);

  EXPECT_THROW(matrix2.MulMatrix(matrix), std::invalid_argument);
}
