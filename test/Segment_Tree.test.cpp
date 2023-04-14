#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include<bits/stdc++.h>

#include "../lib/Segment_Tree.hpp"
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