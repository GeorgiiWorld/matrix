#include "matrix.h"

TEST(OverloadEq, normal_true) {
  Matrix matrix;
  Matrix matrix_res;

  bool res = matrix_res == matrix;

  ASSERT_EQ(res, true);
}

TEST(OverloadEq, normal_false) {
  Matrix matrix;
  Matrix matrix_res;

  matrix_res(0, 0) = 1;
  bool res = matrix_res == matrix;
  ASSERT_EQ(res, false);
}

TEST(OverloadPlus, normal) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_res[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                       12,  24, 22,  42,   30,   14,   16, 4};
  Matrix matrix(4, 4);
  Matrix matrix_res(4, 4);
  FillDataInMatrix(matrix, data);
  FillDataInMatrix(matrix_res, data_res);

  Matrix matrix_plus(matrix + matrix);
  bool res = matrix_res == matrix_plus;

  ASSERT_EQ(res, true);
}

TEST(OverloadSub, normal) {
  double data[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                   12,  24, 22,  42,   30,   14,   16, 4};
  double result[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                     6,   12, 11,  21,  15,  7,   8, 2};
  Matrix matrix(4, 4);
  Matrix matrix_res(4, 4);
  FillDataInMatrix(matrix, data);
  FillDataInMatrix(matrix_res, result);

  Matrix matrix_minus(matrix - matrix_res);
  bool res = matrix_res == matrix_minus;

  ASSERT_EQ(res, true);
}

TEST(OverloadMul, normal_diff) {
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

  Matrix matrix_mul = matrix_1 * matrix_2;

  bool res = matrix_result == matrix_mul;
  ASSERT_EQ(res, true);
}

TEST(OverloadMulNum, normal) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_2[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                     12,  24, 22,  42,   30,   14,   16, 4};
  Matrix matrix_1(4, 4);
  Matrix matrix_result(4, 4);
  FillDataInMatrix(matrix_1, data);
  FillDataInMatrix(matrix_result, data_2);

  Matrix matrix_mul = matrix_1 * 2;

  bool res = matrix_result == matrix_mul;
  ASSERT_EQ(res, true);
}

TEST(OverloadSumEq, normal) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_res[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                       12,  24, 22,  42,   30,   14,   16, 4};
  Matrix matrix(4, 4);
  Matrix matrix_res(4, 4);
  FillDataInMatrix(matrix, data);
  FillDataInMatrix(matrix_res, data_res);

  matrix += matrix;
  bool res = matrix_res == matrix;

  ASSERT_EQ(res, true);
}

TEST(OverloadSubEq, normal) {
  double data[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                   12,  24, 22,  42,   30,   14,   16, 4};
  double result[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                     6,   12, 11,  21,  15,  7,   8, 2};
  Matrix matrix(4, 4);
  Matrix matrix_res(4, 4);
  FillDataInMatrix(matrix, data);
  FillDataInMatrix(matrix_res, result);

  matrix -= matrix_res;
  bool res = matrix_res == matrix;

  ASSERT_EQ(res, true);
}

TEST(OverloadMulEq, normal) {
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

  matrix_1 *= matrix_2;

  bool res = matrix_result == matrix_1;
  ASSERT_EQ(res, true);
}

TEST(OverloadMulEqNum, normal) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_2[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                     12,  24, 22,  42,   30,   14,   16, 4};
  Matrix matrix_1(4, 4);
  Matrix matrix_result(4, 4);
  FillDataInMatrix(matrix_1, data);
  FillDataInMatrix(matrix_result, data_2);

  matrix_1 *= 2;

  bool res = matrix_result == matrix_1;
  ASSERT_EQ(res, true);
}

TEST(OverloadIndex, normal_extract) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Matrix matrix_1(3, 3);
  FillDataInMatrix(matrix_1, data);

  ASSERT_EQ(matrix_1(0, 2), 3);
}

TEST(OverloadIndex, normal_set) {
  double data[] = {777};
  Matrix matrix_1;
  Matrix matrix_result;
  FillDataInMatrix(matrix_result, data);

  matrix_1(0, 0) = 777;

  bool result = matrix_1 == matrix_result;
  ASSERT_EQ(result, true);
}

TEST(OverloadIndex, fail_higher) {
  Matrix matrix_1(4, 4);

  EXPECT_THROW(matrix_1(5, 1), std::out_of_range);
}

TEST(OverloadIndex, fail_lower) {
  Matrix matrix_1;

  EXPECT_THROW(matrix_1(-1, 0), std::out_of_range);
}
