
# Static Matrix Library

## Overview

This is a mathematical vector, matrix and tensor library by static allocations.

Template is utilized to specify the element type and sizes of vector, matrix
and tensor. Dynamic allocations (`new[]`/`delete[]`) by specifying sizes at
constructor's parameters do not adopted.

## Tutorial

```
auto v = Vector<double, 3>();       // zero-filled vector, shape = (3)
auto m = Matrix<double, 3, 4>();    // zero-filled matrix, shape = (3, 4)
```

## Unit Tests

### Pre-requisits

* Google Tests must be installed.

### Commands

```
cmake tests
```

## Supported Environments

* C++ compilers supporting C++11

## Tested Environments

## Author

Yudai Shimbo <yudai.shimbo@gmail.com>

## References

### Notation

x: scalar
v: vector
m: matrix

### Vector

* v += v2
* v -= v2
* v *= v2
* v /= v2

* v += x
* v -= x
* v *= x
* v /= x

* v + v2 => v3
* v - v2 => v3
* v * v2 => v3
* v / v2 => v3

* v + x => v2
* v - x => v2
* v * x => v2
* v / x => v2

* dot(v, v2) => x

### Matrix

* m += m2
* m -= m2
* m *= m2
* m /= m2

* m += x
* m -= x
* m *= x
* m /= x

* m + m2 => m3
* m - m2 => m3
* m * m2 => m3
* m / m2 => m3

* m + x => m2
* m - x => m2
* m * x => m2
* m / x => m2

* dot(m, m2) => m3
