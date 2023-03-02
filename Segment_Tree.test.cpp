#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include<bits/stdc++.h>

namespace tomo0608 {
    template<class S, S(*op)(S, S), S(*e)()> struct segment_tree {
        int _n, size, log;
        std::vector<S> d;
        void update(int k) { d[k] = op(d[k * 2], d[k * 2 + 1]); }
        segment_tree(): segment_tree(0) {}
        explicit segment_tree(int n): segment_tree(std::vector<S>(n, e())) {}
        explicit segment_tree(std::vector<S> a): _n((int)a.size()) {
            log = 0;
            while ((1U << log) < (unsigned int)(_n)) log++;
            size = 1 << log;
            d = std::vector<S>(size * 2, e());
            for (int i = 0; i < _n; i++)d[size + i] = a[i];
            for (int i = size - 1; i >= 1; i--)update(i);
        }

        void update(int p, const S& x) {
            assert(0 <= p && p < _n);
            p += size;
            d[p] = x;
            for (int i = 1; i <= log; i++)update(p >> i);
        }

        S get(int p) const {
            assert(0 <= p && p < _n);
            return d[p + size];
        }

        S prod(int l, int r) const {
            assert(0 <= l && l <= r && r <= _n);
            S sml = e(), smr = e();
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
using namespace std;

using S = int;
S op(S x, S y) { return min(x, y); }
S e() { return INT_MAX; }
int main() {
    int n, q;cin >> n >> q;
    tomo0608::segment_tree<S, op, e> seg(n);
    while (q--) {
        int t, x, y;cin >> t >> x >> y;
        if (t == 0)seg.update(x, y);
        else cout << seg.prod(x, y + 1) << "\n";
    }
    return 0;
}