#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>
class Matrix {
public:
    Matrix(size_t satir, size_t sutun)
        : satir_(satir), sutun_(sutun), data_(satir* sutun) {
    }

    T& operator()(size_t i, size_t j) {
        return data_[i * sutun_ + j];
    }
    const T& operator()(size_t i, size_t j) const {
        return data_[i * sutun_ + j];
    }

    size_t rows() const { return satir_; }
    size_t cols() const { return sutun_; }

    Matrix operator*(const Matrix& other) const {
        if (sutun_ != other.satir_)
            throw std::invalid_argument("Boyutlar uyusmuyor: A.sutun != B.satir");

        Matrix result(satir_, other.sutun_);
        for (size_t i = 0; i < satir_; i++)
            for (size_t k = 0; k < sutun_; k++)
                for (size_t j = 0; j < other.sutun_; j++)
                    result(i, j) += (*this)(i, k) * other(k, j);
        return result;
    }


    
    // Test eklemeleri

    Matrix operator+(const Matrix& other) const {
        if ((sutun_ != other.sutun_)||(satir_ != other.satir_))
            throw std::invalid_argument("Boyutlar uyusmuyor !!!");

        Matrix result(satir_, other.sutun_);
        for (size_t i = 0; i < satir_; i++) {
            for (size_t j = 0; j < other.sutun_; j++) {
                result(i, j) += (*this)(i, j) + other(i, j);
            }
        }     
        return result;
    }


    Matrix operator-(const Matrix& other) const {
        if ((sutun_ != other.sutun_) || (satir_ != other.satir_))
            throw std::invalid_argument("Boyutlar uyusmuyor !!!");

        Matrix result(satir_, other.sutun_);
        for (size_t i = 0; i < satir_; i++) {
            for (size_t j = 0; j < other.sutun_; j++) {
                result(i, j) += (*this)(i, j) - other(i, j);
            }
        }
        return result;
    }

    /////////////////////////



    

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        for (size_t i = 0; i < m.satir_; i++) {
            for (size_t j = 0; j < m.sutun_; j++)
                os << m(i, j) << "  ";
            os << "\n";
        }
        return os;
    }

private:
    size_t satir_, sutun_;
    std::vector<T> data_;
};