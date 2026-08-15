#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>
#include <utility>

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


    // Matrislerde Çarpma
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


    // Matrislerde toplama
    Matrix operator+(const Matrix& other) const {
        if ((sutun_ != other.sutun_) || (satir_ != other.satir_))
            throw std::invalid_argument("Boyutlar uyusmuyor !!!");

        Matrix result(satir_, other.sutun_);
        for (size_t i = 0; i < satir_; i++) {
            for (size_t j = 0; j < other.sutun_; j++) {
                result(i, j) = (*this)(i, j) + other(i, j);
            }
        }
        return result;
    }

    // Matrislerde çýkarma
    Matrix operator-(const Matrix& other) const {
        if ((sutun_ != other.sutun_) || (satir_ != other.satir_))
            throw std::invalid_argument("Boyutlar uyusmuyor !!!");

        Matrix result(satir_, other.sutun_);
        for (size_t i = 0; i < satir_; i++) {
            for (size_t j = 0; j < other.sutun_; j++) {
                result(i, j) = (*this)(i, j) - other(i, j);
            }
        }
        return result;
    }


    // Devrik/transpoze
    Matrix Trans() const {
        Matrix result(sutun_, satir_);
        for (size_t i = 0; i < satir_; i++) {
            for (size_t j = 0; j < sutun_; j++) {
                result(j, i) = (*this)(i, j);
            }
        }

        return result;
    }


    // Deterinant 
    T Det() const {
        if (satir_ == 1) return (*this)(0, 0);
        if (satir_ == 2 && sutun_ == 2)
            return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);           // 2x2 matris determinant 

        T det = T();
        int k = 1;
        for (size_t j = 0; j < sutun_; j++) {
            Matrix minor = Minor(0, j);
            det += k * (*this)(0, j) * minor.Det();
            k = -k;
        }
        return det;
    }

    // Minor Hesaplama (determinant için )
    Matrix Minor(size_t skipRow, size_t skipCol) const {        // daha alt matrislere indirme /Minor
        Matrix result(satir_ - 1, sutun_ - 1);
        size_t r = 0;
        for (size_t i = 0; i < satir_; i++) {
            if (i == skipRow) continue;
            size_t c = 0;
            for (size_t j = 0; j < sutun_; j++) {
                if (j == skipCol) continue;
                result(r, c) = (*this)(i, j);
                c++;
            }
            r++;
        }
        return result;
    }


    //////////////////////////////////////////////Test Denemesi
    
    //skaler çarpým
    Matrix Sklr(T n) const {
        Matrix result(satir_, sutun_);
        for (size_t i = 0; i < satir_; i++) {
            for (size_t j = 0; j < sutun_; j++) {
                result(i, j) = (*this)(i, j) * n;
            }
        }

        return result;
    }


    // A = L * U  (Dolittle algoritmasý)
    // Kare matrisler için çalýþýr. Döndürür: pair(L, U)
    std::pair<Matrix, Matrix> LU_Decompose() const {
        if (satir_ != sutun_)
            throw std::invalid_argument("LU ayrýþtýrmasý sadece kare matris için geçerli.");

        size_t n = satir_;
        Matrix L(n, n);
        Matrix U(n, n);

        // Baþlangýçta tüm elemanlar sýfýr (varsayýlan) — diyagonal L için 1 koyacaðýz.
        for (size_t i = 0; i < n; ++i)
            L(i, i) = static_cast<T>(1);

        for (size_t i = 0; i < n; ++i) {
            // U'nin i. satýrý
            for (size_t k = i; k < n; ++k) {
                T sum = T();
                for (size_t j = 0; j < i; ++j)
                    sum += L(i, j) * U(j, k);
                U(i, k) = (*this)(i, k) - sum;
            }

            // L'in i. sütunu
            for (size_t k = i + 1; k < n; ++k) {
                T sum = T();
                for (size_t j = 0; j < i; ++j)
                    sum += L(k, j) * U(j, i);

                if (U(i, i) == T())
                    throw std::runtime_error("Pivot sifiri, tam pivotlama gereklidir.");

                L(k, i) = ((*this)(k, i) - sum) / U(i, i);
            }
        }

        return std::make_pair(L, U);
    }

    // Sadece U'yu almak 
    Matrix GetU() const {
        return LU_Decompose().second;
    }

    // Sadece L'yi almak 
    Matrix GetL() const {
        return LU_Decompose().first;
    }

    /////////////////////////////////////////////////////////////////////////


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