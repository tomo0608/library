#pragma once
#include<vector>
#include<cassert>
#include<utility>
#include<algorithm>
namespace tomo0608 {

    struct TwoEdgeCC {
    public:
        std::vector<std::vector<int>> comp_g, two_scc_components;
        std::vector<std::vector<int>> g;
        TwoEdgeCC() :_n(0) {}
        TwoEdgeCC(int n) : _n(n), g(n) {}

        int operator[](const int& u) {
            assert(0 <= u && u < _n);
            return comp_idx[u];
        }
        bool is_bridge(const int edge_index) {
            auto [u, v] = edges[edge_index];
            return (_ord[u] < _low[v]) || (_ord[v] < _low[u]);
        }
        void add_edge(int u, int v, bool minus_one = true) {
            if (minus_one) {
                u--;
                v--;
            }
            assert(0 <= u && u < _n);
            assert(0 <= v && v < _n);
            g[u].emplace_back(v);
            g[v].emplace_back(u);
            edges.emplace_back(u, v);
        }

        void build() {
            _used.assign(_n, 0);
            _low.assign(_n, 0);
            _ord.assign(_n, 0);
            comp_idx.assign(_n, -1);
            int k = 0;
            for (int i = 0; i < _n; i++) {
                if (!_used[i])k = lowlink(i, k, -1);
            }
            int twcc_index = 0;
            for (int i = 0; i < _n; i++) {
                if (comp_idx[i] == -1)dfs(i, -1, twcc_index);
            }
            comp_g.resize(twcc_index);
            two_scc_components.resize(twcc_index);
            for (const auto& [u, v] : bridges) {
                comp_g[comp_idx[u]].emplace_back(comp_idx[v]);
                comp_g[comp_idx[v]].emplace_back(comp_idx[u]);
            }
            for(int i = 0; i < _n; i++)two_scc_components[comp_idx[i]].emplace_back(i);
        }

    private:
        int _n;
        std::vector<int> _ord, _low, _used;
        std::vector<std::pair<int, int>> edges;
        std::vector<std::pair<int, int>> bridges;
        std::vector<int> comp_idx;

        int lowlink(int idx, int k, int par) {
            _used[idx] = true;
            _ord[idx] = k++;
            _low[idx] = _ord[idx];
            int cnt = 0;
            bool one_parent = true;
            for (const auto& to : g[idx]) {
                if(to == par && one_parent){
                    one_parent = false;
                    continue;
                }
                if (!_used[to]) {
                    ++cnt;
                    k = lowlink(to, k, idx);
                    _low[idx] = std::min(_low[idx], _low[to]);
                    if (_ord[idx] < _low[to])bridges.emplace_back(std::minmax(idx, (int)to));
                }else {
                    _low[idx] = std::min(_low[idx], _ord[to]);
                }
            }
            return k;
        }

        void dfs(int idx, int par, int& twcc_index) {
            if (~par && _ord[par] >= _low[idx])comp_idx[idx] = comp_idx[par];
            else comp_idx[idx] = twcc_index++;
            for (const auto& to : g[idx]) {
                if (comp_idx[to] == -1)dfs(to, idx, twcc_index);
            }
        }
    };
} // namespace tomo0608
