# Matrix Library

A lightweight and educational **C++ matrix library** developed from scratch.

This project aims to grow into a general-purpose linear algebra library for C++, with a long-term focus on performance, usability, and numerical computing.

> **Status:** Early development

---

## 🚀 Project Goals

The main goal of this project is to build a C++ linear algebra library from the ground up while gradually implementing fundamental matrix and numerical algorithms.

The project is developed incrementally through versioned releases such as `v0.1`, `v0.2`, `v0.3`, and beyond.

Long-term goals include functionality similar to established C++ linear algebra libraries such as Eigen.

---

## 📦 Versions

| Version | Status      | Description                   |
| ------- | ----------- | ----------------------------- |
| `v0.1`  | ✅ Available | Initial matrix implementation |
| `v0.2`  | ✅ Available | Extended matrix functionality |
| `v0.3`  | 🔄 Planned  | Additional matrix operations  |
| `v1.0`  | 🔮 Future   | Stable initial release        |

Each version contains its own README describing the functionality and usage of that specific version.

---

## ✨ Current Features

Depending on the version, the library currently focuses on fundamental matrix operations.

* Matrix creation
* Matrix storage
* Matrix element access
* Matrix multiplication
* Basic matrix manipulation

More functionality will be added progressively.

---

## 🛠️ Planned Features

The long-term roadmap includes:

### Matrix Operations

* [x] Matrix creation
* [x] Matrix multiplication
* [x] Matrix addition
* [x] Matrix subtraction
* [ ] Scalar multiplication
* [ ] Transpose
* [ ] Determinant
* [ ] Matrix inverse

### Linear Algebra

* [ ] Vector support
* [ ] Identity matrices
* [ ] Diagonal matrices
* [ ] LU decomposition
* [ ] QR decomposition
* [ ] Gaussian elimination
* [ ] Rank
* [ ] Eigenvalues
* [ ] Eigenvectors

### Performance

* [ ] Move semantics optimization
* [ ] Expression templates
* [ ] Cache-friendly operations
* [ ] SIMD optimizations
* [ ] Multithreading
* [ ] GPU acceleration

### Developer Experience

* [ ] CMake integration
* [ ] Unit tests
* [ ] Documentation
* [ ] Examples
* [ ] Benchmarking
* [ ] Continuous Integration

---

## 💻 Example

A basic example of matrix multiplication:

```cpp
#include "Matrix.h"

int main()
{
    Matrix A(2, 2);
    Matrix B(2, 2);

    // Set matrix elements
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(1, 0) = 3;
    A(1, 1) = 4;

    B(0, 0) = 5;
    B(0, 1) = 6;
    B(1, 0) = 7;
    B(1, 1) = 8;

    Matrix C = A * B;

    return 0;
}
```

> The API shown above may change as the library evolves.

---

## 🏗️ Project Structure

```text
Matrix-Library/
│
├── README.md
├── LICENSE
│
├── v0.1/
│   ├── README.md
│   └── ...
│
├── v0.2/
│   ├── README.md
│   └── ...
│
└── ...
```

Each version is maintained separately so that the development history and evolution of the library remain clear.

---

## 🗺️ Roadmap

The project will evolve gradually from a basic matrix implementation into a more complete linear algebra library.

```text
Basic Matrix
     │
     ▼
Matrix Operations
     │
     ▼
Vectors & Linear Algebra
     │
     ▼
Decompositions
     │
     ▼
Eigenvalues / Eigenvectors
     │
     ▼
Performance Optimization
     │
     ▼
Advanced Numerical Computing
```

The roadmap may change as development progresses.

---

## 🎯 Long-Term Vision

The long-term objective is to create a modern C++ linear algebra library capable of being used in areas such as:

* Scientific computing
* Computational physics
* Numerical analysis
* Engineering
* Machine learning
* Simulation
* Data analysis

The project is also intended as a practical exploration of:

* Modern C++
* Generic programming
* Templates
* Memory management
* Numerical algorithms
* Algorithm optimization
* High-performance computing

---

## 📚 Learning & Development

This project is being developed from the ground up rather than relying on an existing matrix implementation.

The purpose is not only to create a usable library, but also to understand the underlying algorithms, data structures, memory management techniques, and performance considerations behind linear algebra software.

---

## 📄 License

This project is licensed under the terms specified in the [`LICENSE`](LICENSE) file.

Please review the license before using, modifying, or distributing the project.

---

## ⭐ Project Status

This project is currently in **early development**.

The API, internal architecture, and project structure may change significantly between versions.

Contributions, suggestions, and discussions are welcome as the project evolves.
