#include "matrix.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

void FillDataInMatrix(Matrix &matrix, const double *data) {
  int col = matrix.GetCols();
  for (int i = 0; i < matrix.GetRows() * matrix.GetCols(); ++i) {
    matrix(i / col, i % col) = data[i];
  }
}

void print(Matrix &matrix) {
  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      std::cout << std::fixed << std::setprecision(7) << matrix(i, j) << "\t";
    }
    std::cout << std::endl;
  }
}
