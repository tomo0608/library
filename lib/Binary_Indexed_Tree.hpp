#pragma once
#include<vector>
#include<cassert>

namespace tomo0608 {
    template<class T>
    struct Binary_Indexed_Tree {
    public:
        Binary_Indexed_Tree() :_n(0) {}
        explicit Binary_Indexed_Tree(int n) : _n(n), _depth(std::__lg(n)), data(n + 1) {}

        void add(int p, T x) {
            assert(0 <= p && p < _n);
            p++;
            while (p <= _n) {
                data[p - 1] += x;
                p += p & -p;
            }
        }

        T sum(int l, int r) {
            assert(0 <= l && l <= r && r <= _n);
            return sum(r) - sum(l);
        }

        T operator[](int r) { return sum(r + 1) - sum(r); }

        // minimize i s.t. a_0 + ... + a_{i-1} >= w, n+1 if not exist
        unsigned lower_bound(T w) {
            assert(w > 0);
            unsigned i = 0;
            for (unsigned k = (1 << _depth); k; k >>= 1) {
                if (i + k <= _n && data[i + k - 1] < w) {
                    w -= data[i + k - 1];
                    i += k;
                }
            }
            return i + 1; // 0-indexed
        }

        // minimize i s.t. a_0 + ... + a_{i-1} > w, n+1 if not exist
        unsigned upper_bound(T w) {
            assert(w >= 0);
            unsigned i = 0;
            for (unsigned k = (1 << _depth); k; k >>= 1) {
                if (i + k <= _n && data[i + k - 1] <= w) {
                    w -= data[i + k - 1];
                    i += k;
                }
            }
            return i + 1;
        }

    private:
        unsigned _n, _depth;
        std::vector<T> data; //data[p-1] = [p-2^k,p) (k = __lg(p & -p))

        T sum(int r) {
            T s = 0;
            while (r > 0) {
                s += data[r - 1];
                r -= r & -r;
            }
            return s;
        }

    };
}
