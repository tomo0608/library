#pragma once
#include<vector>
#include<assert.h>

namespace tomo0608 {
    template<class Monoid, Monoid(*op)(Monoid, Monoid), Monoid(*e)()> 
    struct segment_tree {
        int _n, size, log;
        std::vector<Monoid> d;
        void update(int k) { d[k] = op(d[k * 2], d[k * 2 + 1]); }
        segment_tree() : segment_tree(0) {}
        explicit segment_tree(int n) : segment_tree(std::vector<Monoid>(n, e())) {}
        explicit segment_tree(std::vector<Monoid> a) : _n((int)a.size()) {
            log = 0;
            while ((1U << log) < (unsigned int)(_n)) log++;
            size = 1 << log;
            d = std::vector<Monoid>(size * 2, e());
            for (int i = 0; i < _n; i++)d[size + i] = a[i];
            for (int i = size - 1; i >= 1; i--)update(i);
        }

        void update(int p, const Monoid& x) {
            assert(0 <= p && p < _n);
            p += size;
            d[p] = x;
            for (int i = 1; i <= log; i++)update(p >> i);
        }

        Monoid get(int p) const {
            assert(0 <= p && p < _n);
            return d[p + size];
        }

        Monoid prod(int l, int r) const {
            assert(0 <= l && l <= r && r <= _n);
            Monoid sml = e(), smr = e();
            l += size;
            r += size;

            while (l < r) {
                if (l & 1) sml = op(sml, d[l++]);
                if (r & 1) smr = op(d[--r], smr);
                l >>= 1;
                r >>= 1;
            }
            return op(sml, smr);
        }
    };
} // namespace tomo0608