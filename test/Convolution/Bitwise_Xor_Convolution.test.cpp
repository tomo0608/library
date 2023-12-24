#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"
#include<bits/stdc++.h>

#include "../../lib/IO.hpp"
#include "../../lib/Bit_Convolution.hpp"

using namespace std;
using namespace tomo0608;

typedef atcoder::modint998244353 mint;
int main() {
    INT(n);
    vector<mint> a(1 << n), b(1 << n);cin >> a >> b;
    print(xor_convolution(a, b));
}