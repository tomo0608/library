#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse"
#include<bits/stdc++.h>

#include "../../lib/modint_plus.hpp"
#include "../../lib/Formal_Power_Series.hpp"
#include "../../lib/IO.hpp"

using namespace std;
using namespace tomo0608;
typedef atcoder::modint998244353 mint;
typedef tomo0608::Formal_Power_Series<mint> fps;
int main() {
    INT(n, k);
    fps f(n);
    for (int j = 0; j < k; j++) {
        int i, a;cin >> i >> a;
        f[i] = a;
    }
    auto f_inv = tomo0608::inv_sparse<mint>(f);
    print(f_inv);
}