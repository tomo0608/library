#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include<vector>
#include<cassert>

namespace tomo0608 {

    template <class S, S(*op)(S, S), S(*e)(), S(*inv)(S)>
    struct static_range_sum {
        int n;
        std::vector<S> range_sum;

        static_range_sum(std::vector<S>& a) {
            n = (int)a.size();
            range_sum.resize(n + 1);
            range_sum[0] = e();
            for (int i = 0; i < n; i++) {
                range_sum[i + 1] = op(range_sum[i], a[i]);
            }
        }

        inline S query(int l, int r) const {
            assert(0 <= l && l < r && r <= n);
            return op(inv(range_sum[l]), range_sum[r]);
        }
    };
}
using S = long long;

S op(S x, S y) { return x + y; }

S e() { return 0LL; }

S inv(S x) { return -x; }

#include<iostream>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++)std::cin >> a[i];
    tomo0608::static_range_sum<S, op, e, inv> srs(a);
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        std::cout << srs.query(l, r) << std::endl;
    }
    return 0;
}
