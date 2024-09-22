#include "matrix.h"

TEST(constructors, base) {
  Matrix matrix;

  ASSERT_EQ(matrix.GetCols(), 1);
  ASSERT_EQ(matrix.GetRows(), 1);
  ASSERT_EQ(matrix(0, 0), 0);
}

TEST(constructors, param) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  Matrix matrix(4, 4);

  FillDataInMatrix(matrix, data);

  ASSERT_EQ(matrix.GetCols(), 4);
  ASSERT_EQ(matrix.GetRows(), 4);
  ASSERT_EQ(matrix.EqMatrix(matrix), true);
}

TEST(constructors, param_invalid) {
  EXPECT_THROW(Matrix matrix_1(-4, 4), std::invalid_argument);
}

TEST(constructors, copy) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  Matrix expect(4, 4);
  FillDataInMatrix(expect, data);
  Matrix temp(4, 4);
  FillDataInMatrix(temp, data);

  Matrix actual(temp);

  ASSERT_TRUE(actual.EqMatrix(expect));
  ASSERT_EQ(actual.GetCols(), 4);
  ASSERT_EQ(actual.GetRows(), 4);
}

TEST(constructors, move) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  Matrix expect(4, 4);
  FillDataInMatrix(expect, data);
  Matrix temp(4, 4);
  FillDataInMatrix(temp, data);

  Matrix actual(std::move(temp));

  ASSERT_TRUE(actual.EqMatrix(expect));
  ASSERT_EQ(actual.GetCols(), 4);
  ASSERT_EQ(actual.GetRows(), 4);
}
