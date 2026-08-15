# Linear Algebra C++ (v0.4)

A lightweight header-only linear algebra library written in C++.

## Features

- Matrix addition
- Matrix subtraction
- Matrix multiplication
- Matrix transpose
- Determinant calculation
- Scalar multiplication
- LU Decomposition (Doolittle Algorithm)
- Extract L matrix
- Extract U matrix
- Template-based implementation

## Project Structure

```text
v0.4/
├── include/
│   └── Matrix.h
└── examples/
    └── main.cpp
```

## Usage

```cpp
#include "Matrix.h"
```

See the `examples` folder for sample usage.

## Implemented Algorithms

### Determinant
Recursive minor expansion method.

### LU Decomposition
Doolittle LU factorization:

A = L × U

Returns:
- L (Lower triangular matrix)
- U (Upper triangular matrix)

## Requirements

- C++11 or newer
- Standard Library only

## Version History

### v0.4
- Added scalar multiplication
- Added LU decomposition (A = L × U)
- Added GetL()
- Added GetU()

### v0.3
- Added transpose
- Added determinant calculation

## License

GNU General Public License v2.0 (GPL-2.0)
