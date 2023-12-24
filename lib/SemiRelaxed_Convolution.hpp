#pragma once

#include<vector>
#include <bit>
#include <cassert>
#include<atcoder/convolution>

namespace tomo0608 {
    template<typename T>
    struct SemiRelaxed_Convolution {
        unsigned int MAX_SIZE, n;
        std::vector<T> a, b, c;
        SemiRelaxed_Convolution(std::vector<T> &_b):n(0), MAX_SIZE(std::bit_ceil(_b.size())*2){
            b.resize(MAX_SIZE);
            c.resize(MAX_SIZE);
            for(int i = 0; i < _b.size(); i++){
                b[i] = _b[i];
            }
        }
        T query(T a_i){
            a.emplace_back(a_i);
            c[n] += a_i * b[0];
            c[n+1] += a_i * b[1];
            if(n){
                int p = std::countr_zero(n);
                for(int j = 1; j <= p; j++){
                    std::vector<T> a1(1 << j);
                    for(int k = 0; k < (1 << j); k++){
                        a1[k] = a[n - (1 << j) + k];
                    }
                    std::vector<T> b1(1 << j);
                    for(int k = 0; k < (1 << j); k++){
                        b1[k] = b[(1 << j) + k];
                    }
                    std::vector<T> c1 = atcoder::convolution(a1, b1);
                    for(int k = 0; k < (1 << (j + 1)) - 1; k++){
                        c[n + k] += c1[k];
                    }
                }
            }
            n++;
            return c[n - 1];
        }
    };
} // namespace tomo0608