#pragma once
#include<vector>
#include<atcoder/maxflow>
#include<cassert>

namespace tomo0608 {

    template <class Cap>
    struct mf_graph_with_mincap {
    public:
        mf_graph_with_mincap() : _n(0) {}
        explicit mf_graph_with_mincap(int n, Cap INF = 1e9) : _n(n), X(n), Y(n + 1), sum(0), g(n + 2), in(n), _INF(INF) {}

        int add_edge(int from, int to, Cap max_cap, Cap min_cap = 0) {
            assert(0 <= from && from < _n);
            assert(0 <= to && to < _n);
            assert(0 <= min_cap && min_cap <= max_cap);
            int edge_idx;
            if (min_cap) {
                edge_idx = g.add_edge(from, to, max_cap - min_cap);
                in[from] -= min_cap;
                in[to] += min_cap;
            }
            else {
                edge_idx = g.add_edge(from, to, max_cap);
            }
            return edge_idx;
        }

        void build() {
            for (int i = 0; i < _n; i++) {
                if (in[i] > 0) {
                    g.add_edge(X, i, in[i]);
                    sum += in[i];
                }
                else if (in[i] < 0) {
                    g.add_edge(i, Y, -in[i]);
                }
            }
        }

        bool can_flow(int s, int t) {
            assert(s != t);
            g.add_edge(t, s, _INF);
            //latte = &flow.graph[t].back();
            //malta = &flow.graph[s].back();
            return can_flow();
        }

        bool can_flow() {
            build();
            auto ret = g.flow(X, Y);
            return ret >= sum;
        }

        Cap max_flow(int s, int t) {
            if (can_flow(s, t)) {
                return g.flow(s, t);
            }
            else {
                return -1;
            }
        }
        // TODO min_flow
        // TODO get_edge
        // TODO edges
        // TODO change_edge


    private:
        int _n, X, Y;
        atcoder::mf_graph<Cap> g;
        std::vector<Cap> in;
        Cap sum, _INF;
    };
}