#include "matrix.h"

TEST(Transpose, base) {
  Matrix matr;
  Matrix matr2;
  matr.Transpose();
  ASSERT_EQ(matr.EqMatrix(matr2), true);
}

TEST(Transpose, normal) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double result[] = {1, 4, 7, 2, 5, 8, 3, 6, 9};
  Matrix matrix(3, 3);
  Matrix matr_res(3, 3);
  FillDataInMatrix(matrix, data);
  FillDataInMatrix(matr_res, result);

  Matrix matr2 = matrix.Transpose();

  ASSERT_EQ(matr_res.EqMatrix(matr2), true);
}

TEST(Transpose, normal_diff_rows) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double result[] = {1, 4, 2, 5, 3, 6};
  Matrix matrix(2, 3);
  Matrix matr_res(3, 2);
  FillDataInMatrix(matrix, data);
  FillDataInMatrix(matr_res, result);

  Matrix matr2 = matrix.Transpose();

  ASSERT_EQ(matr_res.EqMatrix(matr2), true);
}

TEST(Transpose, normal_diff_cols) {
  double data[] = {1, 2, 3, 4, 5, 6};
  double result[] = {1, 3, 5, 2, 4, 6};
  Matrix matrix(3, 2);
  Matrix matr_res(2, 3);
  FillDataInMatrix(matrix, data);
  FillDataInMatrix(matr_res, result);

  Matrix matr2 = matrix.Transpose();

  ASSERT_EQ(matr_res.EqMatrix(matr2), true);
}

TEST(Determinant, normal_zero_1) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Matrix matr(3, 3);
  FillDataInMatrix(matr, data);

  double result = matr.Determinant();

  ASSERT_EQ(result, 0.0);
}

TEST(Determinant, normal_zero_2) {
  double data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  Matrix matr(3, 3);
  FillDataInMatrix(matr, data);
  double result = matr.Determinant();
  ASSERT_DOUBLE_EQ(result, 0.0);
}

TEST(Determinant, normal_1) {
  double data[] = {9.1, 8, 7, 6, 5, 4, 3, 2, 1};
  Matrix matr(3, 3);
  FillDataInMatrix(matr, data);

  double result = matr.Determinant();

  ASSERT_NEAR(result, -0.299999999999999, ACCURACY);
}

TEST(Determinant, normal_2) {
  double data[] = {51, 2, 2, 1, 0, 0, 3, 43, 0, 0, 0, 3, 51, 0, 0, 1};
  Matrix matr(4, 4);
  FillDataInMatrix(matr, data);

  double result = matr.Determinant();

  ASSERT_DOUBLE_EQ(result, -918.0);
}

TEST(Determinant, fail_rows) {
  Matrix matr(3, 4);

  EXPECT_THROW(matr.Determinant(), std::invalid_argument);
}

TEST(Determinant, fail_cols) {
  Matrix matr(4, 3);

  EXPECT_THROW(matr.Determinant(), std::invalid_argument);
}

TEST(CalcComplements, base) {
  double data[] = {1};
  double data_res[] = {1};
  Matrix matr;
  Matrix matr_res;
  FillDataInMatrix(matr, data);
  FillDataInMatrix(matr_res, data_res);

  Matrix matr2 = matr.CalcComplements();

  bool res = matr2.EqMatrix(matr_res);
  ASSERT_EQ(res, true);
}

TEST(CalcComplements, normal_1) {
  double data[] = {6.7, 5, -4, 99};
  double data_res[] = {99, 4, -5, 6.7};
  Matrix matr(2, 2);
  Matrix matr_res(2, 2);
  FillDataInMatrix(matr, data);
  FillDataInMatrix(matr_res, data_res);

  Matrix matr2 = matr.CalcComplements();

  ASSERT_EQ(matr2.EqMatrix(matr_res), true);
}

TEST(CalcComplements, normal_2) {
  double data[] = {2, 0, 0, 0, 2, 0, 0, 0, 2};
  double data_res[] = {4, 0, 0, 0, 4, 0, 0, 0, 4};
  Matrix matr(3, 3);
  Matrix matr_res(3, 3);
  FillDataInMatrix(matr, data);
  FillDataInMatrix(matr_res, data_res);

  Matrix matr2 = matr.CalcComplements();

  ASSERT_EQ(matr2.EqMatrix(matr_res), true);
}

TEST(CalcComplements, fail_rows) {
  Matrix matr(2, 3);

  EXPECT_THROW(matr.CalcComplements(), std::invalid_argument);
}

TEST(CalcComplements, fail_cols) {
  Matrix matr(3, 2);

  EXPECT_THROW(matr.CalcComplements(), std::invalid_argument);
}

TEST(InverseMatrix, normal) {
  double data[] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  double result[] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  Matrix matr(3, 3);
  Matrix matr_res(3, 3);
  FillDataInMatrix(matr, data);
  FillDataInMatrix(matr_res, result);

  Matrix matr2 = matr.InverseMatrix();

  ASSERT_EQ(matr2.EqMatrix(matr_res), true);
}

TEST(InverseMatrix, fail_rows) {
  Matrix matr(2, 3);

  EXPECT_THROW(matr.InverseMatrix(), std::invalid_argument);
}

TEST(InverseMatrix, fail_cols) {
  Matrix matr(3, 2);

  EXPECT_THROW(matr.InverseMatrix(), std::invalid_argument);
}

TEST(InverseMatrix, fail_det) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Matrix matr(3, 3);
  FillDataInMatrix(matr, data);

  EXPECT_THROW(matr.InverseMatrix(), std::invalid_argument);
}

TEST(InverseMatrix, test_4) {
  double data[] = {0};
  Matrix matr;
  FillDataInMatrix(matr, data);
  EXPECT_THROW(matr.InverseMatrix(), std::invalid_argument);
}
