#pragma once
#include<iostream>
#include<vector>
#include<assert.h>
#include<utility>

namespace tomo0608 {
    template<typename T>
    struct Matrix : public std::vector<std::vector<T>> {
        using std::vector<std::vector<T>>::vector;
        using std::vector<std::vector<T>>::operator=;

        Matrix() {}
        Matrix(size_t n, size_t m) : std::vector<std::vector<T>>(n, std::vector< T >(m, 0)) {};
        
        size_t height() const { return ((*this).size()); }
        size_t width() const { return ((*this)[0].size()); }
        static Matrix I(size_t n) {
            Matrix mat(n, n);
            for (int i = 0; i < n; i++) mat[i][i] = 1;
            return (mat);
        }

        Matrix& operator+=(const Matrix& B) {
            size_t n = height(), m = width();
            assert(n == B.height() && m == B.width());
            for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)(*this)[i][j] += B[i][j];
            return (*this);
        }

        Matrix& operator-=(const Matrix& B) {
            size_t n = height(), m = width();
            assert(n == B.height() && m == B.width());
            for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)(*this)[i][j] -= B[i][j];
            return (*this);
        }

        template<typename U>
        Matrix& operator*=(const U m){
            for(int i = 0; i < height(); i++)for(int j = 0; j < width(); j++)(*this)[i][j] *= m;
            return (*this);
        }

        Matrix& operator*=(const Matrix& B) {
            size_t n = height(), m = B.width(), p = width();
            assert(p == B.height());
            Matrix C(n, m);
            for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)for (int k = 0; k < p; k++)C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
            (*this).swap(C);
            return (*this);
        }

        Matrix& operator^=(long long k) {
            Matrix B = Matrix::I(height());
            while (k > 0) {
                if (k & 1) B *= *this;
                *this *= *this;
                k >>= 1LL;
            }
            (*this).swap(B);
            return (*this);
        }

        Matrix operator+(const Matrix& B) const { return (Matrix(*this) += B); }
        Matrix operator-(const Matrix& B) const { return (Matrix(*this) -= B); }
        Matrix operator*(const Matrix& B) const { return (Matrix(*this) *= B); }
        template<typename U>
        Matrix operator*(const U m) const {return  (Matrix(*this) *= m);}
        Matrix operator^(const long long k) const { return (Matrix(*this) ^= k); }
        friend std::ostream& operator<<(std::ostream& os, Matrix& p) { size_t n = p.height(), m = p.width();for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) { os << p[i][j] << (j + 1 == m ? "\n" : " "); } }return (os); }
    };

    template<typename T>
    std::pair<int, T> GaussElimination(std::vector<std::vector<T>>& a, int pivot_end = -1, bool diagonalize = false) {
        int H = a.size(), W = a[0].size(), rank = 0;
        if (pivot_end == -1)pivot_end = W;
        T det = 1;
        for (int j = 0; j < pivot_end; j++) {
            int idx = -1;
            for (int i = rank; i < H; i++) {
                if (a[i][j] != T(0)) {
                    idx = i;
                    break;
                }
            }
            if (idx == -1) {
                det = 0;
                continue;
            }
            if (rank != idx)det = -det, swap(a[rank], a[idx]);
            det *= a[rank][j];
            if (diagonalize && a[rank][j] != T(1)) {
                T coef = T(1) / a[rank][j];
                for (int k = j; k < W; k++)a[rank][k] *= coef;
            }
            int is = diagonalize ? 0 : rank + 1;
            for (int i = is; i < H; i++) {
                if (i == rank)continue;
                if (a[i][j] != T(0)) {
                    T coef = a[i][j] / a[rank][j];
                    for (int k = j; k < W; k++)a[i][k] -= a[rank][k] * coef;
                }
            }
            rank++;
        }
        return std::make_pair(rank, det);
    }
}