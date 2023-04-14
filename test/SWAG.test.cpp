#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "../lib/SWAG.hpp"

#include<iostream>
using namespace std;
#define ll long long
const ll MOD = 998244353;
#define S pair<ll,ll>
S op(S x, S y) {
    S z;
    z.first = x.first * y.first % MOD;
    z.second = (y.first * x.second + y.second) % MOD;
    return z;
}
S e() { return { 1, 0 }; }
int main() {
    int q;cin >> q;
    int l = 0, r = 0;
    tomo0608::SWAG<S, op, e> swag;
    while (q--) {
        int i;cin >> i;
        if (i == 0) {
            ll a, b;cin >> a >> b;
            swag.push_back(S(a, b));
            r++;
        }
        if (i == 1) {
            l++;
        }
        if (i == 2) {
            ll x;cin >> x;
            if (l == r) {
                cout << x << endl;
                continue;
            }
            auto [a, b] = swag.fold(l, r);
            ll fx = (a * x + b) % MOD;
            cout << fx << endl;
        }
    }
}