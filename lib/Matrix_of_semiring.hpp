#pragma once
#include<vector>
#include<assert.h>
#include<iostream>
#include<limits.h>
#include<algorithm>

namespace tomo0608 {
    template<class S, S(*addition)(S, S), S(*zero)(), S(*multiplication)(S, S), S(*one)()>
    struct Matrix_of_semiring {
        std::vector<std::vector<S>> A;
        Matrix_of_semiring() {}
        Matrix_of_semiring(size_t n, size_t m) : A(n, std::vector< S >(m, zero())) {}
        Matrix_of_semiring(size_t n) : A(n, std::vector< S >(n, zero())) {};

        size_t height() const { return (A.size()); }
        size_t width() const { return (A[0].size()); }
        inline const std::vector< S >& operator[](int k) const { return (A.at(k)); }
        inline std::vector< S >& operator[](int k) { return (A.at(k)); }

        static Matrix_of_semiring I(size_t n) {
            Matrix_of_semiring mat(n);
            for (int i = 0; i < n; i++) mat[i][i] = one();
            return (mat);
        }

        Matrix_of_semiring& operator+=(const Matrix_of_semiring& B) {
            size_t n = height(), m = width();
            assert(n == B.height() && m == B.width());
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    (*this)[i][j] = addition((*this)[i][j], B[i][j]);
            return (*this);
        }
        Matrix_of_semiring& operator*=(const Matrix_of_semiring& B) {
            size_t n = height(), m = B.width(), p = width();
            assert(p == B.height());
            std::vector< std::vector< S > > C(n, std::vector< S >(m, zero()));
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    for (int k = 0; k < p; k++)
                        C[i][j] = addition(C[i][j], multiplication((*this)[i][k], B[k][j]));
            A.swap(C);
            return (*this);
        }
        Matrix_of_semiring& operator^=(long long k) {
            assert(height() == width());
            Matrix_of_semiring B = Matrix_of_semiring::I(height());
            while (k > 0) {
                if (k & 1) B *= *this;
                *this *= *this;
                k >>= 1LL;
            }
            A.swap(B.A);
            return (*this);
        }
        Matrix_of_semiring operator+(const Matrix_of_semiring& B) const { return (Matrix_of_semiring(*this) += B); }
        Matrix_of_semiring operator*(const Matrix_of_semiring& B) const { return (Matrix_of_semiring(*this) *= B); }
        Matrix_of_semiring operator^(const long long k) const { return (Matrix_of_semiring(*this) ^= k); }
        friend std::ostream& operator<<(std::ostream& os, Matrix_of_semiring& p) {
            size_t n = p.height(), m = p.width();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    os << p[i][j] << (j + 1 == m ? "\n" : " ");
                }
            }
            return (os);
        }

    };

    long long minplus_addition(long long x, long long y) { return std::min(x, y); }
    long long minplus_zero() { return LLONG_MAX / 2; }
    long long minplus_multiplication(long long x, long long y) {
        if (std::max(x, y) == minplus_zero()) return minplus_zero();
        return x + y;
    }
    long long minplus_one() { return 0; }
    long long maxplus_addition(long long x, long long y) { return std::max(x, y); }
    long long maxplus_zero() { return LLONG_MIN / 2; }
    long long maxplus_multiplication(long long x, long long y) {
        if (std::min(x, y) == maxplus_zero()) return maxplus_zero();
        return x + y;
    }
    long long maxplus_one() { return 0; }
    typedef Matrix_of_semiring<long long, minplus_addition, minplus_zero, minplus_multiplication, minplus_one> Minplus_Matrix;
    typedef Matrix_of_semiring<long long, maxplus_addition, maxplus_zero, maxplus_multiplication, maxplus_one> Maxplus_Matrix;

    long long minmax_addition(long long x, long long y) { return std::min(x, y); }
    long long minmax_zero() { return LLONG_MAX / 2; }
    long long minmax_multiplication(long long x, long long y) { return std::max(x, y); }
    long long minmax_one() { return LLONG_MIN / 2; }
    typedef Matrix_of_semiring<long long, minmax_addition, minmax_zero, minmax_multiplication, minmax_one> Minmax_Matrix;
    typedef Matrix_of_semiring<long long, minmax_multiplication, minmax_one, minmax_addition, minmax_zero> Maxmin_Matrix;

    long long xorand_addition(long long x, long long y) { return x ^ y; }
    long long xorand_zero() { return 0; }
    long long xorand_multiplication(long long x, long long y) { return x & y; }
    long long xorand_one() { return LLONG_MAX; } // 2^63 - 1
    typedef Matrix_of_semiring<long long, xorand_addition, xorand_zero, xorand_multiplication, xorand_one> Xorand_Matrix;
}// namespace tomo0608