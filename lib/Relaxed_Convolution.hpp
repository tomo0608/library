#pragma once

#include<vector>
#include <bit>
#include <cassert>
#include<atcoder/convolution>

namespace tomo0608 {
    template<typename T>
    struct Relaxed_Convolution {
        unsigned int n;
        std::vector<T> a, b, c;
        Relaxed_Convolution() : n(0) {
        }
        T query(T a_i, T b_i) {
            a.emplace_back(a_i);
            b.emplace_back(b_i);
            c.emplace_back(T(0));
            if (n > 0) {
                c.emplace_back(0);
            }
            int p = std::countr_zero(n + 2);
            for (int j = 0; j <= p; j++) {
                std::vector<T> a1(1 << j);
                for (int k = 0; k < (1 << j); k++) {
                    a1[k] = a[(1 << j) - 1 + k];
                }
                std::vector<T> b1(1 << j);
                for (int k = 0; k < (1 << j); k++) {
                    b1[k] = b[n - ((1 << j) - 1 - k)];
                }
                std::vector<T> c1 = atcoder::convolution(a1, b1);
                for (int k = 0; k < (1 << (j + 1)) - 1; k++) {
                    c[n + k] += c1[k];
                }
                if ((1 << p) == n + 2 && j == p - 1) {
                    break;
                }
                std::vector<T> a2(1 << j);
                for (int k = 0; k < (1 << j); k++) {
                    a2[k] = a[n - ((1 << j) - 1 - k)];
                }
                std::vector<T> b2(1 << j);
                for (int k = 0; k < (1 << j); k++) {
                    b2[k] = b[(1 << j) - 1 + k];
                }
                std::vector<T> c2 = atcoder::convolution(a2, b2);
                for (int k = 0; k < (1 << (j + 1)) - 1; k++) {
                    c[n + k] += c2[k];
                }
            }
            n++;
            return c[n - 1];
        }
    };

    template<typename T>
    struct  relaxed_integral {
        unsigned int n;
        T pre;
        std::vector<T> f, F;
        relaxed_integral() : n(0), pre(T(0)) {}
        T query(T f_i) {
            T res = pre;
            n++;
            pre = f_i / n;
            return res;
        }
    };

    template<typename T>
    struct relaxed_exp {
        unsigned int n;
        T pre;
        Relaxed_Convolution<T> rc;
        // g = exp(f)
        //   = \int f' g dx
        T query(T f_i) {
            n++;
            if (n == 1) {
                assert(f_i == T(0));
                return pre = T(1);
            }
            else {
                return pre = rc.query(pre, f_i * (n - 1)) / (n - 1);
            }
        }
    };

};//namespace tomo0608