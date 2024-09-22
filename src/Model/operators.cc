#include "../matrix_oop.h"

double& Matrix::operator()(int rows, int cols) {
  if (rows < 0 || rows >= rows_ || cols < 0 || cols >= cols_) {
    throw std::out_of_range("Incorrect input, index is outside the matrix");
  }
  return matrix_[rows * cols_ + cols];
}

double Matrix::operator()(int rows, int cols) const {
  if (rows < 0 || rows >= rows_ || cols < 0 || cols >= cols_) {
    throw std::out_of_range("Incorrect input, index is outside the matrix");
  }
  return matrix_[rows * cols_ + cols];
}

Matrix& Matrix::operator=(const Matrix& other) noexcept {
  if (this != &other) {
    Matrix temp(other);
    std::swap(rows_, temp.rows_);
    std::swap(cols_, temp.cols_);
    std::swap(matrix_, temp.matrix_);
  }
  return *this;
}

Matrix Matrix::operator+(const Matrix& other) const {
  Matrix res(*this);
  res.SumMatrix(other);
  return res;
}

Matrix Matrix::operator-(const Matrix& other) const {
  Matrix res(*this);
  res.SubMatrix(other);
  return res;
}

Matrix Matrix::operator*(const Matrix& other) const {
  Matrix res(*this);
  res.MulMatrix(other);
  return res;
}

Matrix Matrix::operator*(const double num) const noexcept {
  Matrix res(*this);
  res.MulNumber(num);
  return res;
}

Matrix& Matrix::operator+=(const Matrix& other) {
  this->SumMatrix(other);
  return *(this);
}

Matrix& Matrix::operator-=(const Matrix& other) {
  this->SubMatrix(other);
  return *(this);
}

Matrix& Matrix::operator*=(const Matrix& other) {
  this->MulMatrix(other);
  return *(this);
}

Matrix& Matrix::operator*=(const double other) {
  this->MulNumber(other);
  return *(this);
}

bool Matrix::operator==(const Matrix& other) const noexcept {
  return (*this).EqMatrix(other);
}
