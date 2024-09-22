#include "matrix.h"

TEST(get, rows) {
  Matrix matrix(5, 10);
  ASSERT_EQ(matrix.GetRows(), 5);
}

TEST(get, cols) {
  Matrix matrix(5, 10);
  ASSERT_EQ(matrix.GetCols(), 10);
}

TEST(set, rows_lower) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  double data_res[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix actual(4, 4);
  Matrix expect(3, 4);
  FillDataInMatrix(actual, data);
  FillDataInMatrix(expect, data_res);

  actual.SetRows(3);

  bool result = actual.EqMatrix(expect);
  ASSERT_EQ(result, true);
}

TEST(set, rows_higher) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  double data_res[] = {1,  2,  3,  4,  5,  6,  7, 8, 9, 10,
                       11, 12, 13, 14, 15, 16, 0, 0, 0, 0};
  Matrix actual(4, 4);
  Matrix expect(5, 4);
  FillDataInMatrix(actual, data);
  FillDataInMatrix(expect, data_res);

  actual.SetRows(5);

  bool result = actual.EqMatrix(expect);
  ASSERT_EQ(result, true);
}

TEST(set, rows_zero) {
  Matrix actual(4, 4);

  EXPECT_THROW(actual.SetRows(0), std::invalid_argument);
}

TEST(set, rows_lessZero) {
  Matrix actual(4, 4);

  EXPECT_THROW(actual.SetRows(-1), std::invalid_argument);
}

TEST(set, cols_lower) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  double data_res[] = {1, 2, 3, 5, 6, 7, 9, 10, 11, 13, 14, 15};
  Matrix actual(4, 4);
  Matrix expect(4, 3);
  FillDataInMatrix(actual, data);
  FillDataInMatrix(expect, data_res);

  actual.SetCols(3);

  bool result = actual.EqMatrix(expect);
  ASSERT_EQ(result, true);
}

TEST(set, cols_higher) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  double data_res[] = {1, 2,  3,  4,  0, 5,  6,  7,  8,  0,
                       9, 10, 11, 12, 0, 13, 14, 15, 16, 0};
  Matrix actual(4, 4);
  Matrix expect(4, 5);
  FillDataInMatrix(actual, data);
  FillDataInMatrix(expect, data_res);

  actual.SetCols(5);

  bool result = actual.EqMatrix(expect);
  ASSERT_EQ(result, true);
}

TEST(set, cols_zero) {
  Matrix actual(4, 4);

  EXPECT_THROW(actual.SetCols(0), std::invalid_argument);
}

TEST(set, cols_lessZero) {
  Matrix actual(4, 4);

  EXPECT_THROW(actual.SetRows(-1), std::invalid_argument);
}
