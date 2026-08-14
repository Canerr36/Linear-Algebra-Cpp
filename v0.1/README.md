# Matrix Multiplication (C++)

A simple console application that multiplies two square matrices, using dynamically allocated memory (`std::unique_ptr`) instead of raw pointers or `new`/`delete`.

This is the first step toward a small Eigen-like matrix library — more features (addition, subtraction, transpose, determinant, etc.) will be added over time.

> **Note:** The console prompts and output are in Turkish.

## Build

### With CMake (cross-platform)

```bash
mkdir build && cd build
cmake ..
cmake --build .
./matrix_multiplication
```

### With Visual Studio

Open `src/main.cpp` in a new C++ Console App project, or generate a Visual Studio solution from CMake:

```bash
cmake -G "Visual Studio 17 2022" -B build
```

## Usage

The program asks for the matrix size, then the elements of matrix A and matrix B, and prints the resulting product matrix A × B.

## Roadmap

- [ ] Refactor into a reusable `Matrix` class/template
- [ ] Addition, subtraction, transpose
- [ ] Determinant, inverse
- [ ] Operator overloading (`+`, `-`, `*`)
- [ ] Unit tests

## License

