#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum"

#include "../../lib/Offline_Dynamic_Connectivity.hpp"

#include "../../lib/IO.hpp"
using namespace std;
using namespace tomo0608;
int main() {
    INT(n,q);
    Offline_Dynamic_Connectivity dc(n, q);
    rep(i,n){
        LL(a);
        dc.uf.add_weight(i, a);
    }
    V<tuple<ll,ll,ll>> query_list(q, {-1,-1,-1});
    rep(i, q){
        INT(t);
        if(t == 0){
            INT(u, v);
            dc.add_edge(u, v, i);
        }
        if(t == 1){
            INT(u, v);
            dc.del_edge(u, v, i);
        }
        if(t == 2){
            LL(v, x);
            query_list[i] = {2, v, x};
        }
        if(t == 3){
            INT(v);
            query_list[i] = {3, v, -1};
        }
    }
    dc.build();
    auto query = [&](ll t)->void{
        auto [type, v, x] = query_list[t];
        if(type == 2)dc.uf.add_weight(v, x);
        if(type == 3){
            print(dc.uf.get_leaders_weight(v));
        }
    };

    dc.run(query);
}