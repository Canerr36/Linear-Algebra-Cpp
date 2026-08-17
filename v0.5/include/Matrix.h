#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>
#include <utility>
#include <cmath>

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


    // A = L * U  ayrýþmasý (L: alt üçgensel, U: üst üçgensel)
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






    ////////////////////////////////////////////////////// Test için deneme 


    // A = Q * R ayrýþtýrmasý (Q: ortonormal, R: üst üçgensel)
    std::pair<Matrix<T>, Matrix<T>> qrDecompose() const {
        int m = satir_;      // satýr sayýsý
        int n = sutun_;      // sütun sayýsý

        Matrix<T> Q(m, n);
        Matrix<T> R(n, n);

        for (int j = 0; j < n; ++j) {
            // j. sütunu al
            std::vector<T> v(m);
            for (int i = 0; i < m; ++i)
                v[i] = (*this)(i, j);

            // önceki Q sütunlarýna izdüþümü çýkar
            for (int k = 0; k < j; ++k) {
                T dot = T(0);
                for (int i = 0; i < m; ++i)
                    dot += Q(i, k) * (*this)(i, j);

                R(k, j) = dot;

                for (int i = 0; i < m; ++i)
                    v[i] -= dot * Q(i, k);
            }

            // normu hesapla
            T norm = T(0);
            for (int i = 0; i < m; ++i)
                norm += v[i] * v[i];
            norm = std::sqrt(norm);

            R(j, j) = norm;

            // normalize edip Q'ya yaz
            for (int i = 0; i < m; ++i)
                Q(i, j) = (norm > T(1e-12)) ? v[i] / norm : T(0);
        }

        return { Q, R };
    }
    // Sadece Q'yi almak 
    Matrix GetQ() const {
        return qrDecompose().first;
    }

    // Sadece R'yi almak 
    Matrix GetR() const {
        return qrDecompose().second;
    }



    // Satýr eþelon formuna (REF) indirger, orijinal matrisi deðiþtirmez
    Matrix<T> gaussianEliminate() const {
        int m = satir_;
        int n = sutun_;
        Matrix<T> A(*this); // kopya üzerinde çalýþ

        int pivotRow = 0;

        for (int col = 0; col < n && pivotRow < m; ++col) {
            // kýsmi pivotlama: bu sütunda mutlak deðeri en büyük satýrý bul
            int maxRow = pivotRow;
            T maxVal = std::abs(A(pivotRow, col));
            for (int i = pivotRow + 1; i < m; ++i) {
                if (std::abs(A(i, col)) > maxVal) {
                    maxVal = std::abs(A(i, col));
                    maxRow = i;
                }
            }

            // pivot sýfýrsa bu sütunu atla
            if (maxVal < T(1e-12))
                continue;

            // pivot satýrýný üste taþý
            if (maxRow != pivotRow) {
                for (int j = 0; j < n; ++j)
                    std::swap(A(pivotRow, j), A(maxRow, j));
            }

            // alt satýrlarý sýfýrla
            for (int i = pivotRow + 1; i < m; ++i) {
                T factor = A(i, col) / A(pivotRow, col);
                for (int j = col; j < n; ++j)
                    A(i, j) -= factor * A(pivotRow, j);
            }

            ++pivotRow;
        }

        return A;
    }

    // Ax = b sistemini Gaussian elimination + geri yerine koyma ile çözer
    // A: n x n kare katsayý matrisi, b: n x 1 sütun vektörü
    Matrix<T> solve(const Matrix<T>& b) const {
        int n = satir_;
        if (n != sutun_)
            throw std::runtime_error("Matris kare degil");

        // A ve b'yi birlestirip (augmented matrix) elimine et
        Matrix<T> Aug(n, n + 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                Aug(i, j) = (*this)(i, j);
            Aug(i, n) = b(i, 0);
        }

        Aug = Aug.gaussianEliminate();

        // geri yerine koyma (back substitution)
        Matrix<T> x(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            T sum = Aug(i, n);
            for (int j = i + 1; j < n; ++j)
                sum -= Aug(i, j) * x(j, 0);

            if (std::abs(Aug(i, i)) < T(1e-12))
                throw std::runtime_error("Sistem tekil (singular) - cozum yok veya sonsuz cozum");

            x(i, 0) = sum / Aug(i, i);
        }

        return x;
    }



    // Matrisin rankini bulma (bagimsiz satir/sutun sayisi)
    int rank() const {
        Matrix<T> R = gaussianEliminate(); // satir eselon formu
        int m = R.satir_;
        int n = R.sutun_;

        int rnk = 0;
        for (int i = 0; i < m; ++i) {
            bool nonZeroRow = false;
            for (int j = 0; j < n; ++j) {
                if (std::abs(R(i, j)) > T(1e-9)) {
                    nonZeroRow = true;
                    break;
                }
            }
            if (nonZeroRow)
                ++rnk;
        }

        return rnk;
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