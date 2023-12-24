#pragma once

#include "Rollback_weighted_dsu.hpp"

#include<map>
#include<algorithm>
#include<tuple>
#include<set>
namespace tomo0608 {
    struct Offline_Dynamic_Connectivity {
    public:
        unsigned int _n, _query_num, segsize;
        Rollback_weighted_dsu<> uf;
        std::vector<std::vector<std::pair<int, int>>> seg;
        std::map<std::pair<int, int>, int> birth;
        std::vector<std::tuple<int,int,int,int>> edges;
        std::set<std::pair<int,int>> appear;

        Offline_Dynamic_Connectivity(int n, int q) : _n(n), _query_num(q), uf(n){
            segsize = 1;
            while(segsize < q)segsize <<= 1;
            seg.resize(2 * segsize);
        }

        void add_edge(int u, int v, int t){
            appear.emplace(std::minmax(u, v));
            birth[std::minmax(u, v)] = t;
        }
        void del_edge(int u, int v, int t){
            appear.erase(std::minmax(u, v));
            edges.emplace_back(birth[std::minmax(u, v)], t, u, v);
            }

        void build() {
            for(auto [u, v]: appear){
                edges.emplace_back(birth[std::minmax(u, v)], _query_num, u, v);
            }
            for(auto [l, r, u, v]: edges){
                seg_set({u, v}, l, r);
            }
        }

        template<typename QUERY_FUNC>
        void run(QUERY_FUNC& query, int k = 1) {
            if(segsize + _query_num <= k)return;
            for(auto &[u, v]: seg[k]){
                uf.merge(u, v);
            }
            if(segsize <= k)query(k - segsize);
            else{
                run(query, k * 2 + 0);
                run(query, k * 2 + 1);
            }
            for(int i = 0; i < seg[k].size(); i++){
                uf.undo();
            }
        }

        void seg_set(std::pair<int, int> e, int l, int r) {
            int L = l + segsize, R = r + segsize;
            while (L < R) {
                if (L & 1)seg[L++].emplace_back(e);
                if (R & 1)seg[--R].emplace_back(e);
                L >>= 1;
                R >>= 1;
            }
        }
    };
}// namespace tomo0608