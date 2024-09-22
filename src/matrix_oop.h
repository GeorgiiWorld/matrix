#ifndef MATRIXPLUS_SRC_MATRIX_OOP_H_
#define MATRIXPLUS_SRC_MATRIX_OOP_H_

#include <cmath>
#include <cstring>
#include <stdexcept>

constexpr double ACCURACY = 1e-7;

class Matrix {
 private:
  int rows_, cols_;
  double* matrix_;
  double CalcMinor(int i, int j) const;

 public:
  Matrix() noexcept;
  ~Matrix() noexcept;
  Matrix(int rows, int cols);
  Matrix(const Matrix& other) noexcept;
  Matrix(Matrix&& other) noexcept;

  int GetRows() const;
  int GetCols() const;
  void SetRows(int value_rows);
  void SetCols(int value_cols);

  bool operator==(const Matrix& x) const noexcept;
  Matrix& operator+=(const Matrix& x);
  Matrix& operator-=(const Matrix& x);
  Matrix& operator*=(const Matrix& x);
  Matrix& operator*=(const double num);
  Matrix& operator=(const Matrix& x) noexcept;
  Matrix operator+(const Matrix& x) const;
  Matrix operator-(const Matrix& x) const;
  Matrix operator*(const Matrix& x) const;
  Matrix operator*(const double x) const noexcept;
  double& operator()(int row, int col);
  double operator()(int row, int col) const;

  bool EqMatrix(const Matrix& other) const noexcept;
  void SumMatrix(const Matrix& other);
  void SubMatrix(const Matrix& other);
  void MulMatrix(const Matrix& other);
  void MulNumber(const double num) noexcept;
  Matrix CalcComplements();
  Matrix InverseMatrix();
  Matrix Transpose() noexcept;
  double Determinant() const;
};

#endif  // MATRIXPLUS_SRC_MATRIX_OOP_H_
