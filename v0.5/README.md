# Linear Algebra C++

A lightweight, header-only linear algebra library written in **C++**.

The project is designed as a simple starting point for learning and using fundamental linear algebra operations without external dependencies.

## Features

### Matrix operations
- Matrix multiplication
- Matrix addition
- Matrix subtraction
- Scalar multiplication
- Transpose
- Determinant
- Minor matrix calculation

### Matrix decompositions
- **LU decomposition** — `A = L * U`
- **QR decomposition** — `A = Q * R`

### Linear algebra algorithms
- Gaussian elimination
- Solving linear systems `Ax = b`
- Matrix rank calculation

## Requirements

- C++11 or newer
- Standard C++ library
- No third-party dependencies

## Project structure

```text
v0.5/
├── include/
│   └── Matrix.h
├── examples/
│   └── main.cpp
├── CMakeLists.txt
├── LICENSE
└── README.md
```

## Quick start

Include the header:

```cpp
#include "Matrix.h"
```

Create a matrix:

```cpp
Matrix<double> A(3, 3);

A(0, 0) = 1;
A(0, 1) = 2;
A(0, 2) = 3;

A(1, 0) = 4;
A(1, 1) = 5;
A(1, 2) = 6;

A(2, 0) = 7;
A(2, 1) = 8;
A(2, 2) = 9;
```

### QR decomposition

```cpp
auto qr = A.qrDecompose();

Matrix<double> Q = qr.first;
Matrix<double> R = qr.second;
```

This produces the decomposition:

```text
A = Q * R
```

`Q` contains the orthonormalized columns and `R` is upper triangular.

### Gaussian elimination

```cpp
Matrix<double> G = A.gaussianEliminate();
```

The function returns a row-echelon form of the matrix and does not modify the original matrix.

### Rank

```cpp
int r = A.rank();
```

The rank is calculated from the row-echelon form obtained through Gaussian elimination.

### Solving a linear system

For a system

```text
A x = b
```

use:

```cpp
Matrix<double> x = A.solve(b);
```

The implementation uses Gaussian elimination followed by back substitution.

## Building the example

Using CMake:

```bash
cmake -S . -B build
cmake --build build
```

Then run the generated example executable.

You can also compile the example directly:

```bash
g++ -std=c++11 examples/main.cpp -Iinclude -o matrix_example
```

## Current version

**v0.5**

This version adds:

- QR decomposition
- Gaussian elimination
- Matrix rank

Previous versions introduced the basic matrix operations, transpose, determinant, scalar multiplication, and LU decomposition.

## Implementation notes

This project is intentionally lightweight and educational.

- QR decomposition currently uses the classical Gram-Schmidt approach.
- LU decomposition does not perform full pivoting.
- Gaussian elimination uses partial pivoting.
- Floating-point comparisons use small numerical tolerances where required.
- The library is header-only.

For numerical workloads requiring highly optimized or numerically robust routines, established libraries such as Eigen, BLAS/LAPACK, or similar solutions should be considered.

## License

This project is licensed under the **GNU General Public License v2.0 (GPL-2.0)**.

See [LICENSE](LICENSE) for the full license text.
