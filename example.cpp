#include "sml/Matrix.h"
#include <iostream>

int main() {
  // Vector
  auto v1 = Vector<double, 3>();
  auto v2 = Vector<double, 3>(-1.0);
  v2(2) = 3.5;
  v1 += v2;
  std::cout << "v = " << v1 << std::endl;
  std::cout << dot(v1, v2) << std::endl;

  // Matrix
  auto m1 = Matrix<double, 3, 2>();
  auto m2 = Matrix<double, 3, 2>(-2.0);
  m2(2, 0) = -5.0;
  m1 += m2;
  std::cout << "m = " << m1 << std::endl;

  auto m3 = Matrix<double, 2, 5>(4);
  std::cout << dot(m1, m3) << std::endl;
}
