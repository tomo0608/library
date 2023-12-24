#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"
#include<bits/stdc++.h>

#include "../../lib/modint_plus.hpp"
#include "../../lib/Number_Theory.hpp"
#include "../../lib/IO.hpp"

using namespace std;
using namespace tomo0608;
typedef atcoder::modint998244353 mint;
int main() {
    LL(n);
    V<mint> a(n+1), b(n+1);
    rep(i,1,n+1)cin >> a[i];
    rep(i,1,n+1)cin >> b[i];
    auto c = gcd_convolution(a, b);
    rep(i,1,n+1)cout << c[i] << (i == n ? '\n' :' ');
}