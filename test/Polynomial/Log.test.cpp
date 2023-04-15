#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"
#include<bits/stdc++.h>

#include "../../lib/IO.hpp"
#include "../../lib/Formal_Power_Series.hpp"

using namespace std;
using namespace tomo0608;

typedef formal_power_series<atcoder::modint998244353> fps;
int main() {
    int n;cin >> n;
    fps a(n);cin >> a;
    print(a.log());
}