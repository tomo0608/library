#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
#include<bits/stdc++.h>


#include "../../lib/modint_plus.hpp"
#include "../../lib/Formal_Power_Series.hpp"
#include "../../lib/IO.hpp"


using namespace std;
using namespace tomo0608;

typedef formal_power_series<atcoder::modint998244353> fps;
int main() {
    INT(n);
    fps a(n);cin >> a;
    print(a.inv());
}