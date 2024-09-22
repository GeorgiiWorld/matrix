#include "matrix.h"

TEST(EqMatrix, base) {
  Matrix matrix(4, 4);
  Matrix matrix_2(4, 4);

  bool result = matrix.EqMatrix(matrix_2);

  ASSERT_EQ(result, true);
}

TEST(EqMatrix, normal) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  Matrix matrix(4, 4);
  Matrix matrix_2(4, 4);
  FillDataInMatrix(matrix, data);
  FillDataInMatrix(matrix_2, data);

  bool result = matrix.EqMatrix(matrix_2);

  ASSERT_EQ(result, true);
}

TEST(EqMatrix, fail) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_2[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                     6,   12, 11,  21,  15,  7,   8, 3};
  Matrix matrix(4, 4);
  Matrix matrix_2(4, 4);
  FillDataInMatrix(matrix, data);
  FillDataInMatrix(matrix_2, data_2);

  bool result = matrix.EqMatrix(matrix_2);

  ASSERT_EQ(result, false);
}

TEST(EqMatrix, fail_cols) {
  Matrix matrix(4, 4);
  Matrix matrix_2(4, 3);

  bool result = matrix.EqMatrix(matrix_2);

  ASSERT_EQ(result, false);
}

TEST(EqMatrix, fail_rows) {
  Matrix matrix(4, 4);
  Matrix matrix_2(3, 4);

  bool result = matrix.EqMatrix(matrix_2);

  ASSERT_EQ(result, false);
}
