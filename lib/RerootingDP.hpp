#pragma once
#include <utility>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>

// dp[u] = merge(lift(dp[v_i], uv_i) for v_i in
// adj[u])で木dpを行える時に、全方位木dpを行う

namespace tomo0608 {
template <class RootProperty, class EdgeProperty> struct RerootingDP {
    struct Edge {
        int from, to;
        EdgeProperty property;
        RootProperty dp, ndp; // TODO: わかりやすい名前にする
        Edge(int from, int to, EdgeProperty property, RootProperty dp,
             RootProperty ndp)
            : from(from), to(to), property(property), dp(dp), ndp(ndp) {}
    };
    using MergeFunctionClass = std::function<RootProperty(RootProperty, RootProperty)>;
    using LiftFunctionClass = std::function<RootProperty(RootProperty, Edge)>;

    int num_of_vertices;
    std::vector<std::vector<Edge>> graph;
    const MergeFunctionClass merge;
    const LiftFunctionClass lift;
    const RootProperty identity;

    RerootingDP(int num_of_vertices, const MergeFunctionClass &merge,
                const LiftFunctionClass &lift, const RootProperty &identity)
        : num_of_vertices(num_of_vertices), graph(num_of_vertices),
          merge(merge), lift(lift), identity(identity),
          subdp(num_of_vertices, identity), dp(num_of_vertices, identity) {}

    void add_edge(int u, int v, EdgeProperty property) {
        assert(0 <= u && u < num_of_vertices);
        assert(0 <= v && v < num_of_vertices);
        graph[u].emplace_back(u, v, property, identity, identity);
        graph[v].emplace_back(v, u, property, identity, identity);
    }

    std::vector<RootProperty> solve() {
        dfs_sub(0, -1);
        dfs_all(0, -1, identity);
        return dp;
    }

  private:
    std::vector<RootProperty> subdp, dp;
    void dfs_sub(int u, int p) {
        for (auto &e : graph[u]) {
            if (e.to == p) continue;
            dfs_sub(e.to, u);
            e.dp = lift(subdp[e.to], e);
            subdp[u] = merge(subdp[u], e.dp);
        }
    }
    void dfs_all(int u, int p, RootProperty from_parent) {
        RootProperty dp_left = identity;
        std::for_each(std::begin(graph[u]), std::end(graph[u]),[&](Edge &e){
            e.ndp = dp_left;
            if(e.to == p) e.dp = lift(from_parent, e);
            dp_left = merge(dp_left, e.dp);
        });
        dp[u] = dp_left;
        RootProperty dp_right = identity;
        std::for_each(std::rbegin(graph[u]), std::rend(graph[u]),[&](Edge &e){
            if(e.to != p){
                e.ndp = merge(e.ndp, dp_right);
                dfs_all(e.to, u, e.ndp);
            }
            dp_right = merge(dp_right, e.dp);
        });
    }
};
} // namespace tomo0608
