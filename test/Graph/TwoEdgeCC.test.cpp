#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "TwoEdgeCC.hpp"

#include<iostream>
using namespace std;

int main(){
    int n,m;cin >> n >> m;
    tomo0608::TwoEdgeCC tecc(n);
    for(int i = 0; i < m; i++){
        int u,v;cin >> u >> v;
        tecc.add_edge(u, v, false);
    }
    tecc.build();
    cout << tecc.comp_g.size() << '\n';
    for(const auto &v: tecc.two_scc_components){
        cout << v.size();
        for(const auto &u: v)cout << ' ' << u;
        cout << '\n';
    }
}