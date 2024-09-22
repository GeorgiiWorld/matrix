#include "../matrix_oop.h"

Matrix::Matrix() noexcept : rows_(1), cols_(1) {
  matrix_ = new double[rows_ * cols_]();
}

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument(
        "Incorrect input, index must be more than zero");
  }
  matrix_ = new double[rows_ * cols_]();
}

Matrix::Matrix(const Matrix& other) noexcept {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = new double[other.rows_ * other.cols_]();
  std::memcpy(matrix_, other.matrix_,
              other.rows_ * other.cols_ * sizeof(double));
}

Matrix::Matrix(Matrix&& other) noexcept {
  matrix_ = other.matrix_;
  rows_ = other.rows_;
  cols_ = other.cols_;

  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

Matrix::~Matrix() noexcept {
  if (matrix_) {
    delete[] matrix_;
  }
}
