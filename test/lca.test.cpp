#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include<bits/stdc++.h>

#include "../lib/Heavy_Light_Decomposition.hpp"

using namespace std;

int main() {
    int n, q;cin >> n >> q;
    tomo0608::HeavyLightDecomposition g(n);
    for (int i = 1; i < n; i++) {
        int p;cin >> p;
        g.add_edge(i, p);
    }
    g.build();
    while (q--) {
        int u, v;cin >> u >> v;
        cout << g.lca(u, v) << endl;
    }
    return 0;
}