#ifndef VECTOR_H
#define VECTOR_H

#include <ostream>

template <class T, std::size_t ROWS>
class Vector {
public:
  Vector(T val = 0) {
    for (std::size_t i = 0; i < ROWS; i++) {
      this->data[i] = val;
    }
  }

  Vector(const Vector<T, ROWS>& v) {
    for (std::size_t i = 0; i < ROWS; i++) {
      this->data[i] = v.data[i];
    }
  }

  T& operator()(int row_idx) {
    if (row_idx < 0 || ROWS <= row_idx) {
      throw std::range_error("row index is out of range");
    }
    return this->data[row_idx];
  }

  const T& operator()(int row_idx) const {
    if (row_idx < 0 || ROWS <= row_idx) {
      throw std::range_error("row index is out of range");
    }
    return this->data[row_idx];
  }

  Vector<T, ROWS>& operator+=(const T& x) {
    for (std::size_t i = 0; i < ROWS; i++) {
      this->data[i] += x;
    }
    return *this;
  }

  Vector<T, ROWS>& operator+=(const Vector<T, ROWS>& v) {
    for (std::size_t i = 0; i < ROWS; i++) {
      this->data[i] += v.data[i];
    }
    return *this;
  }

  Vector<T, ROWS>& operator-=(const T& x) {
    for (std::size_t i = 0; i < ROWS; i++) {
      this->data[i] -= x;
    }
    return *this;
  }
  Vector<T, ROWS>& operator-=(const Vector<T, ROWS>& v) {
    for (std::size_t i = 0; i < ROWS; i++) {
      this->data[i] -= v.data[i];
    }
    return *this;
  }

  Vector<T, ROWS>& operator*=(const T& x) {
    for (std::size_t i = 0; i < ROWS; i++) {
      this->data[i] *= x;
    }
    return *this;
  }

  Vector<T, ROWS>& operator*=(const Vector<T, ROWS>& v) {
    for (std::size_t i = 0; i < ROWS; i++) {
      this->data[i] *= v.data[i];
    }
    return *this;
  }

  Vector<T, ROWS>& operator/=(const T& x) {
    for (std::size_t i = 0; i < ROWS; i++) {
      this->data[i] /= x;
    }
    return *this;
  }

  Vector<T, ROWS>& operator/=(const Vector<T, ROWS>& v) {
    for (std::size_t i = 0; i < ROWS; i++) {
      this->data[i] /= v.data[i];
    }
    return *this;
  }

private:
  T data[ROWS];
};

template <class T, std::size_t ROWS>
inline Vector<T, ROWS> operator+(Vector<T, ROWS> v, T x) {
  for (std::size_t i = 0; i < ROWS; i++) {
    v(i) += x;
  }
  return v;
}

template <class T, std::size_t ROWS>
inline Vector<T, ROWS> operator+(Vector<T, ROWS> v, const Vector<T, ROWS>& v2) {
  for (std::size_t i = 0; i < ROWS; i++) {
    v(i) += v2(i);
  }
  return v;
}

template <class T, std::size_t ROWS>
inline Vector<T, ROWS> operator-(Vector<T, ROWS> v, T x) {
  for (std::size_t i = 0; i < ROWS; i++) {
    v(i) -= x;
  }
  return v;
}

template <class T, std::size_t ROWS>
inline Vector<T, ROWS> operator-(Vector<T, ROWS> v, const Vector<T, ROWS>& v2) {
  for (std::size_t i = 0; i < ROWS; i++) {
    v(i) -= v2(i);
  }
  return v;
}

template <class T, std::size_t ROWS>
inline Vector<T, ROWS> operator*(Vector<T, ROWS> v, T x) {
  for (std::size_t i = 0; i < ROWS; i++) {
    v(i) *= x;
  }
  return v;
}

template <class T, std::size_t ROWS>
inline Vector<T, ROWS> operator*(Vector<T, ROWS> v, const Vector<T, ROWS>& v2) {
  for (std::size_t i = 0; i < ROWS; i++) {
    v(i) *= v2(i);
  }
  return v;
}

template <class T, std::size_t ROWS>
inline Vector<T, ROWS> operator/(Vector<T, ROWS> v, T x) {
  for (std::size_t i = 0; i < ROWS; i++) {
    v(i) /= x;
  }
  return v;
}

template <class T, std::size_t ROWS>
inline Vector<T, ROWS> operator/(Vector<T, ROWS> v, const Vector<T, ROWS>& v2) {
  for (std::size_t i = 0; i < ROWS; i++) {
    v(i) /= v2(i);
  }
  return v;
}

template <class T, std::size_t ROWS>
T dot(const Vector<T, ROWS>& v, const Vector<T, ROWS>& v2) {
  T sum = 0;
  for (std::size_t i = 0; i < ROWS; i++) {
    sum += v(i) * v2(i);
  }
  return sum;
}

template <class T, std::size_t ROWS>
inline std::ostream& operator<<(std::ostream& os, const Vector<T, ROWS>& v) {
  for (std::size_t i = 0; i < ROWS; i++) {
    os << v(i) << " ";
  }
  return os;
}

#endif
