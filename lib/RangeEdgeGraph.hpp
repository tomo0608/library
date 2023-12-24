#pragma once
#include<vector>
#include<utility>

namespace tomo0608 {
    template<typename Weight> // int, long long, mint, double
    struct RangeEdgeGraph {
        int n;
        typedef std::pair<int, Weight> Edge;
        std::vector<std::vector<Edge>> g;
        RangeEdgeGraph(int _n) : n(_n) {
            g.resize(4 * n);
            for (int i = 1; i < n; i++) {
                int lc = i * 2, rc = i * 2 + 1;
                g[i].emplace_back(lc, 0);
                g[i].emplace_back(rc, 0);
                g[lc + 2 * n].emplace_back(i + 2 * n, 0);
                g[rc + 2 * n].emplace_back(i + 2 * n, 0);
            }
            for (int i = n; i < 2 * n; i++)g[i].emplace_back(i + 2 * n, 0);
        }

        // from [l1, r1) to [l2, r2)
        int add_edge(int l1, int r1, int l2, int r2, Weight w) {
            int idx = g.size();
            for (l1 += n, r1 += n; l1 < r1; l1 >>= 1, r1 >>= 1) {
                if (l1 & 1)g[l1 + 2 * n].emplace_back(idx, 0), l1++;
                if (r1 & 1)--r1, g[r1 + 2 * n].emplace_back(idx, 0);
            }
            std::vector<Edge> node;
            for (l2 += n, r2 += n; l2 < r2; l2 >>= 1, r2 >>= 1) {
                if (l2 & 1)node.emplace_back(l2++, w);
                if (r2 & 1)node.emplace_back(--r2, w);
            }
            g.emplace_back(node);
            return idx;
        }
        // TODO Dijkstra
    };
};