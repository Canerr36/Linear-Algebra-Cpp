# Matrix Library

A lightweight, header-only C++ matrix class developed as a personal learning project.

The project is currently in an early development stage and is intended to evolve into a more complete linear algebra library.

## Current Features

- Template-based `Matrix<T>` class
- Dynamic matrix dimensions
- Element access with `operator()`
- Matrix multiplication
- Matrix addition
- Matrix subtraction
- Basic dimension validation
- Stream output with `operator<<`
- Header-only matrix implementation

## Project Structure

```text
v0.2/
├── examples/
│   └── main.cpp
├── include/
│   └── Matrix.h
├── CMakeLists.txt
├── LICENSE
└── README.md
```

## Requirements

- C++17 compatible compiler
- CMake 3.16 or newer (optional)

Tested conceptually with standard C++ toolchains such as GCC, Clang, and MSVC.

## Build with CMake

```bash
cmake -S . -B build
cmake --build build
```

Then run the generated example executable.

## Build without CMake

You can also compile the example directly:

```bash
g++ -std=c++17 examples/main.cpp -Iinclude -o matrix_example
```

Run:

```bash
./matrix_example
```

On Windows with MSVC, the same project can be opened/configured through Visual Studio using CMake.

## Example

```cpp
Matrix<int> A(2, 2);
Matrix<int> B(2, 2);

A(0, 0) = 1;
A(0, 1) = 2;
A(1, 0) = 3;
A(1, 1) = 4;

B(0, 0) = 4;
B(0, 1) = 3;
B(1, 0) = 2;
B(1, 1) = 1;

Matrix<int> C = A * B;
```

## Roadmap

This project is intentionally kept small at the current stage. Planned development may include:

- Improved constructors and initialization
- Bounds checking
- Scalar operations
- Transpose
- Determinant
- Inverse
- Identity and zero matrices
- More complete tests
- Performance improvements
- Better documentation
- More advanced linear algebra functionality

The long-term goal is to build a C++ linear algebra library inspired by projects such as Eigen, while developing the implementation step by step.

## Version

**v0.2**

This is an early development version and the API may change in future releases.

## License

This project is released under a custom non-commercial license.

See [`LICENSE`](LICENSE) for the complete terms.
