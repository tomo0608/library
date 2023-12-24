#pragma once
#include<vector>

namespace tomo0608 {
    template<class T = int>
    struct functional_graph {
        std::vector<std::vector<T>> doubling_f;
        int sz;
        const int log = 63;
        functional_graph(std::vector<T> _f) :sz((int)_f.size()) {
            doubling_f.resize(log + 1, std::vector<T>(sz));
            for (int v = 0; v < sz; v++)doubling_f[0][v] = _f[v];
            for (int i = 0; i + 1 <= log; i++)for (int v = 0; v < sz; v++) {
                doubling_f[i + 1][v] = doubling_f[i][doubling_f[i][v]];
            }
        };
        T apply(long long k, T now) {
            for (int i = log; i >= 0; i--) {
                if (k & (1LL << i))now = doubling_f[i][now];
            }
            return now;
        }
    };
}// namespace tomo0608