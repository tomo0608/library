#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include<iostream>
#include "../lib/DisjointSparseTable.hpp"

int op(int x, int y) { return std::min(x, y); }
using namespace std;
int main() {
    int n, q;cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    tomo0608::DisjointSparseTable<int, op> dat(v);
    while (q--) {
        int l, r;cin >> l >> r;
        cout << dat.query(l, r) << endl;
    }
}