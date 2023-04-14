#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068"
#include<bits/stdc++.h>

#include "../lib/2D_Segment_Tree.hpp"

using namespace std;



using S = int;
S op(S x, S y) { return min(x, y); }
S e() { return int((1LL << 31) - 1); }

void solve() {
    S r, c, q;cin >> r >> c >> q;
    if (r == 0)exit(0);
    //vector a(r, vector<S>(c));
    //for (int i = 0; i < r; i++)for (int j = 0;j < c;j++)cin >> a[i][j];
    tomo0608::segment_tree_2d<S, op, e> seg(r, c);
    for (int i = 0; i < r; i++)for (int j = 0;j < c;j++) {
        int x;cin >> x;
        seg.update(i, j, x);
    }
    while (q--) {
        S r1, c1, r2, c2;cin >> r1 >> c1 >> r2 >> c2;
        cout << seg.prod(r1, r2 + 1, c1, c2 + 1) << '\n';
    }
}
int main() {
    while (1)solve();
}