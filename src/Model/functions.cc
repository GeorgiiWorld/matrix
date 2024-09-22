#include "../matrix_oop.h"

int Matrix::GetRows() const { return rows_; }

int Matrix::GetCols() const { return cols_; }

void Matrix::SetRows(int value_rows) {
  if (value_rows <= 0) {
    throw std::invalid_argument(
        "Incorrect input, number of rows must be more than zero");
  }
  Matrix other(value_rows, cols_);
  std::memcpy(other.matrix_, matrix_,
              std::min(rows_, value_rows) * cols_ * sizeof(double));
  (*this) = other;
  rows_ = other.rows_;
}

void Matrix::SetCols(int value_cols) {
  if (value_cols <= 0) {
    throw std::invalid_argument(
        "Incorrect input, number of cols must be more than zero");
  }
  Matrix other(rows_, value_cols);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < std::min(cols_, value_cols); j++) {
      other(i, j) = (*this)(i, j);
    }
  }
  (*this) = other;
}

void Matrix::SumMatrix(const Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Incorrect input, different matrix dimensions");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) += other(i, j);
    }
  }
}

void Matrix::SubMatrix(const Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Incorrect input, different matrix dimensions");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) -= other(i, j);
    }
  }
}

void Matrix::MulMatrix(const Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "Incorrect input, the number of columns of the first matrix is not "
        "equal to the number of rows of the second matrix");
  }
  Matrix result(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        result(i, j) += (*this)(i, k) * other(k, j);
      }
    }
  }
  (*this) = result;
}

void Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) *= num;
    }
  }
}

bool Matrix::EqMatrix(const Matrix& other) const noexcept {
  bool exit = true;
  if ((rows_ != other.rows_) || (cols_ != other.cols_)) {
    exit = false;
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (fabs((*this)(i, j) - other(i, j)) > ACCURACY) exit = false;
      }
    }
  }
  return exit;
}

Matrix Matrix::Transpose() noexcept {
  Matrix other(cols_, rows_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      other(j, i) = (*this)(i, j);
    }
  }
  return other;
}

Matrix Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::invalid_argument("Incorrect input, the matrix is not square");
  }
  Matrix result(rows_, cols_);
  if (rows_ == 1 && cols_ == 1) {
    result(0, 0) = (*this)(0, 0);
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        int sign = ((i + j) % 2 == 0) ? 1 : -1;
        double minor = (*this).CalcMinor(i, j);
        result(i, j) = sign * minor;
      }
    }
  }
  return result;
}

double Matrix::CalcMinor(int i, int j) const {
  Matrix other(rows_ - 1, cols_ - 1);
  for (int k = 0; k < rows_; k++) {
    for (int l = 0; l < cols_; l++) {
      if (k == i || l == j) continue;
      int ii = (k < i) ? k : k - 1;
      int jj = (l < j) ? l : l - 1;
      other(ii, jj) = (*this)(k, l);
    }
  }
  double minor = 0;
  minor = other.Determinant();
  return minor;
}

double Matrix::Determinant() const {
  double result = 0;
  if (rows_ != cols_) {
    throw std::invalid_argument("Incorrect input, the matrix is not square");
  }
  if (rows_ == 1) {
    result = (*this)(0, 0);
  } else if (rows_ == 2) {
    result = (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
  } else {
    for (int i = 0; i < rows_; i++) {
      Matrix other(rows_ - 1, cols_ - 1);
      for (int j = 1; j < rows_; j++) {
        for (int k = 0, l = 0; k < cols_; k++) {
          if (k == i || j == 0) continue;
          other(j - 1, l) = (*this)(j, k);
          l++;
        }
      }
      double sign = (i % 2 == 0) ? 1 : -1;
      double minor = 0;
      minor = other.Determinant();
      result += sign * (*this)(0, i) * minor;
    }
  }
  return result;
}

Matrix Matrix::InverseMatrix() {
  double determinant = (*this).Determinant();
  if (determinant == 0) {
    throw std::invalid_argument("Incorrect input, matrix determinant is 0");
  }
  Matrix tempMatrix = (*this).CalcComplements();
  (*this) = tempMatrix.Transpose();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) = 1 / determinant * (*this)(i, j);
    }
  }
  return (*this);
}
