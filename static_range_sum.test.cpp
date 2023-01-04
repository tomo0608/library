#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <vector>
#include<cassert>

template <class S, S(*op)(S, S), S(*e)(), S(*inv)(S)>
class static_range_sum {
public:
    static_range_sum(): _n(0) {}
    static_range_sum(std::vector<S>& a): _n(a.size()) {
        range_sum.resize(_n + 1);
        range_sum[0] = e();
        for (int i = 0; i < _n; i++) {
            range_sum[i + 1] = op(range_sum[i], a[i]);
        }
    }

    S query(int l, int r) {
        assert(0 <= l && l < r&& r <= _n);
        return op(inv(range_sum[l]), range_sum[r]);
    }

private:
    unsigned _n;
    std::vector<S> range_sum;
};

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
    static_range_sum<S, op, e, inv> srs(a);
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        std::cout << srs.query(l, r) << std::endl;
    }
    return 0;
}
