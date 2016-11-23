#ifndef MATRIX_H
#define MATRIX_H

#include <ostream>
#include "Vector.h"

template <class T, std::size_t ROWS, std::size_t COLS>
class Matrix {
public:
  Matrix(T val = 0) {
    for (std::size_t i = 0; i < ROWS; i++) {
      for (std::size_t j = 0; j < COLS; j++) {
        this->data[i][j] = val;
      }
    }
  }

  Matrix(const Matrix<T, ROWS, COLS>& m) {
    for (std::size_t i = 0; i < ROWS; i++) {
      for (std::size_t j = 0; j < COLS; j++) {
        this->data[i][j] = m.data[i][j];
      }
    }
  }

  T& operator()(int row_idx, int col_idx) {
    if (row_idx < 0 || ROWS <= row_idx || col_idx < 0 || COLS <= col_idx) {
      throw std::range_error("row or column index is out of range");
    }
    return this->data[row_idx][col_idx];
  }

  const T& operator()(int row_idx, int col_idx) const {
    if (row_idx < 0 || ROWS <= row_idx || col_idx < 0 || COLS <= col_idx) {
      throw std::range_error("row or column index is out of range");
    }
    return this->data[row_idx][col_idx];
  }

  Matrix<T, ROWS, COLS>& operator+=(const T& x) {
    for (std::size_t i = 0; i < ROWS; i++) {
      for (std::size_t j = 0; j < COLS; j++) {
        this->data[i][j] += x;
      }
    }
    return *this;
  }

  Matrix<T, ROWS, COLS>& operator+=(const Matrix<T, ROWS, COLS>& m) {
    for (std::size_t i = 0; i < ROWS; i++) {
      for (std::size_t j = 0; j < COLS; j++) {
        this->data[i][j] += m.data[i][j];
      }
    }
    return *this;
  }

  Matrix<T, ROWS, COLS>& operator-=(const T& x) {
    for (std::size_t i = 0; i < ROWS; i++) {
      for (std::size_t j = 0; j < COLS; j++) {
        this->data[i][j] -= x;
      }
    }
    return *this;
  }

  Matrix<T, ROWS, COLS>& operator-=(const Matrix<T, ROWS, COLS>& m) {
    for (std::size_t i = 0; i < ROWS; i++) {
      for (std::size_t j = 0; j < COLS; j++) {
        this->data[i][j] -= m.data[i][j];
      }
    }
    return *this;
  }

  Matrix<T, ROWS, COLS>& operator*=(const T& x) {
    for (std::size_t i = 0; i < ROWS; i++) {
      for (std::size_t j = 0; j < COLS; j++) {
        this->data[i][j] *= x;
      }
    }
    return *this;
  }

  Matrix<T, ROWS, COLS>& operator*=(const Matrix<T, ROWS, COLS>& m) {
    for (std::size_t i = 0; i < ROWS; i++) {
      for (std::size_t j = 0; j < COLS; j++) {
        this->data[i][j] *= m.data[i][j];
      }
    }
    return *this;
  }

  Matrix<T, ROWS, COLS>& operator/=(const T& x) {
    for (std::size_t i = 0; i < ROWS; i++) {
      for (std::size_t j = 0; j < COLS; j++) {
        this->data[i][j] /= x;
      }
    }
    return *this;
  }

  Matrix<T, ROWS, COLS>& operator/=(const Matrix<T, ROWS, COLS>& m) {
    for (std::size_t i = 0; i < ROWS; i++) {
      for (std::size_t j = 0; j < COLS; j++) {
        this->data[i][j] /= m.data[i][j];
      }
    }
    return *this;
  }

private:
  T data[ROWS][COLS];
};

template <class T, std::size_t ROWS, std::size_t COLS>
inline Matrix<T, ROWS, COLS> operator+(Matrix<T, ROWS, COLS> m, T x) {
  for (std::size_t i = 0; i < ROWS; i++) {
    for (std::size_t j = 0; j < COLS; j++) {
      m(i, j) += x;
    }
  }
  return m;
}

template <class T, std::size_t ROWS, std::size_t COLS>
inline Matrix<T, ROWS, COLS> operator+(Matrix<T, ROWS, COLS> m, const Matrix<T, ROWS, COLS>& m2) {
  for (std::size_t i = 0; i < ROWS; i++) {
    for (std::size_t j = 0; j < COLS; j++) {
      m(i, j) += m2(i, j);
    }
  }
  return m;
}

template <class T, std::size_t ROWS, std::size_t COLS>
inline Matrix<T, ROWS, COLS> operator-(Matrix<T, ROWS, COLS> m, T x) {
  for (std::size_t i = 0; i < ROWS; i++) {
    for (std::size_t j = 0; j < COLS; j++) {
      m(i, j) -= x;
    }
  }
  return m;
}

template <class T, std::size_t ROWS, std::size_t COLS>
inline Matrix<T, ROWS, COLS> operator-(Matrix<T, ROWS, COLS> m, const Matrix<T, ROWS, COLS>& m2) {
  for (std::size_t i = 0; i < ROWS; i++) {
    for (std::size_t j = 0; j < COLS; j++) {
      m(i, j) -= m2(i, j);
    }
  }
  return m;
}

template <class T, std::size_t ROWS, std::size_t COLS>
inline Matrix<T, ROWS, COLS> operator*(Matrix<T, ROWS, COLS> m, T x) {
  for (std::size_t i = 0; i < ROWS; i++) {
    for (std::size_t j = 0; j < COLS; j++) {
      m(i, j) *= x;
    }
  }
  return m;
}

template <class T, std::size_t ROWS, std::size_t COLS>
inline Matrix<T, ROWS, COLS> operator*(Matrix<T, ROWS, COLS> m, const Matrix<T, ROWS, COLS>& m2) {
  for (std::size_t i = 0; i < ROWS; i++) {
    for (std::size_t j = 0; j < COLS; j++) {
      m(i, j) *= m2(i, j);
    }
  }
  return m;
}

template <class T, std::size_t ROWS, std::size_t COLS>
inline Matrix<T, ROWS, COLS> operator/(Matrix<T, ROWS, COLS> m, T x) {
  for (std::size_t i = 0; i < ROWS; i++) {
    for (std::size_t j = 0; j < COLS; j++) {
      m(i, j) /= x;
    }
  }
  return m;
}

template <class T, std::size_t ROWS, std::size_t COLS>
inline Matrix<T, ROWS, COLS> operator/(Matrix<T, ROWS, COLS> m, const Matrix<T, ROWS, COLS>& m2) {
  for (std::size_t i = 0; i < ROWS; i++) {
    for (std::size_t j = 0; j < COLS; j++) {
      m(i, j) /= m2(i, j);
    }
  }
  return m;
}

template <class T, std::size_t ROWS, std::size_t MSIZE, std::size_t COLS>
inline Matrix<T, ROWS, COLS> dot(Matrix<T, ROWS, MSIZE> m1, const Matrix<T, MSIZE, COLS>& m2) {
  Matrix<T, ROWS, COLS> m;
  for (std::size_t i = 0; i < ROWS; i++) {
    for (std::size_t j = 0; j < COLS; j++) {
      for (std::size_t k = 0; k < MSIZE; k++) {
        m(i, j) += m1(i, k) * m2(k, j);
      }
    }
  }
  return m;
}

template <class T, std::size_t ROWS, std::size_t COLS>
inline std::ostream& operator<<(std::ostream& os, const Matrix<T, ROWS, COLS>& m) {
  for (std::size_t i = 0; i < ROWS; i++) {
    for (std::size_t j = 0; j < COLS; j++) {
      os << m(i, j) << " ";
    }
    os << "; ";
  }
  return os;
}

#endif
