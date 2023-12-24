#pragma once
#include<vector>
#include<assert.h>

namespace tomo0608 {

    template<typename T>
    void fast_zeta_transformation(std::vector<T>& f, bool up = true) {
        int n = f.size();
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j++) {
                if ((j & i) == 0) {
                    if (up)f[j] += f[j | i];
                    else f[j | i] += f[j];
                }
            }
        }
    }

    template<typename T>
    void fast_moebius_transformation(std::vector<T>& f, bool up = true) {
        int n = f.size();
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j++) {
                if ((j & i) == 0) {
                    if (up)f[j] -= f[j | i];
                    else f[j | i] -= f[j];
                }
            }
        }
    }

    template<typename T>
    void fast_walsh_hadamard_transformation(std::vector<T>& f, bool is_inv = false) {
        int n = f.size();
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j++) {
                if ((j & i) == 0) {
                    T x = f[j], y = f[j | i];
                    f[j] = x + y, f[j | i] = x - y;
                }
            }
        }
        if (is_inv) {
            for (int i = 0; i < n; i++)f[i] /= n;
        }
    }

    template<typename T>
    std::vector<T> pointwise_product(std::vector<T>& f, std::vector<T>& g) {
        assert(f.size() == g.size());
        int n = f.size();
        std::vector<T> c(n);
        for (int i = 0; i < n; i++)c[i] = f[i] * g[i];
        return c;
    }

    template<typename T>
    std::vector<T> and_convolution(std::vector<T> f, std::vector<T> g) {
        fast_zeta_transformation(f);
        fast_zeta_transformation(g);
        std::vector<T> c = pointwise_product(f, g);
        fast_moebius_transformation(c);
        return c;
    }

    template<typename T>
    std::vector<T> or_convolution(std::vector<T> f, std::vector<T> g) {
        fast_zeta_transformation(f, false);
        fast_zeta_transformation(g, false);
        std::vector<T> c = pointwise_product(f, g);
        fast_moebius_transformation(c, false);
        return c;
    }

    template<typename T>
    std::vector<T> xor_convolution(std::vector<T> f, std::vector<T> g) {
        fast_walsh_hadamard_transformation(f);
        fast_walsh_hadamard_transformation(g);
        std::vector<T> c = pointwise_product(f, g);
        fast_walsh_hadamard_transformation(c, true);
        return c;
    }


}// namespace tomo0608



// Path: library/lib/Bit_Convolution.hpp