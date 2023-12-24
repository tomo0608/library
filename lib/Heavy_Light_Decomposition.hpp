#pragma once

#include<vector>
#include<assert.h>

namespace tomo0608 {
    struct HeavyLightDecomposition {
        std::vector<std::vector<int>> Forest; // The child of vertex v on heavy edge is G[v][0] unless v is a leaf
        int n, time;
        std::vector<int> parent,    // The parent of vertex v
            size_of_subtree,        // The size of subtree whose root is v
            depth,                  // The distance between the root and v
            head,                   // The vertex closest to the root in the heavy path containing v
            tree_id,                // ID of the tree to which vertex v belongs
            vertex_id,              // ID of vertex v
            vertex_id_inv;

        HeavyLightDecomposition(int n):
            Forest(n),
            n(n),
            time(0),
            parent(n, -1),
            size_of_subtree(n),
            depth(n),
            head(n),
            tree_id(n, -1),
            vertex_id(n, -1),
            vertex_id_inv(n) {}

        HeavyLightDecomposition(std::vector<std::vector<int>>& G):
            Forest(G),
            n(G.size()),
            time(0),
            parent(G.size(), -1),
            size_of_subtree(G.size()),
            depth(G.size()),
            head(G.size()),
            tree_id(G.size(), -1),
            vertex_id(G.size(), -1),
            vertex_id_inv(G.size()) {}

        void add_edge(int u, int v) {
            assert(0 <= u && u < n);
            assert(0 <= v && v < n);
            Forest[u].emplace_back(v);
            Forest[v].emplace_back(u);
        }

        void build(std::vector<int> roots_of_Forest = { 0 }) {
            int tree_idx = 0;
            for (int& root : roots_of_Forest) {
                assert(0 <= root && root < n);
                dfs_sz(root);
                head[root] = root;
                dfs_hld(root, tree_idx++);
            }
            assert(time == n);
            for (int v = 0; v < n; v++)vertex_id_inv[vertex_id[v]] = v;
        }

        int idx(int v)const { return vertex_id[v]; }

        int ancestor(int v, int k)const {
            assert(0 <= v && v < n);
            assert(0 <= k && k <= depth[v]);
            while (true) {
                int u = head[v];
                if (vertex_id[v] - vertex_id[u] >= k)return vertex_id_inv[vertex_id[v] - k];
                k -= vertex_id[v] - vertex_id[u] + 1;
                v = parent[u];
            }
        }

        int lca(int u, int v) const {
            assert(0 <= u && u < n);
            assert(0 <= v && v < n);
            assert(tree_id[u] == tree_id[v]);
            for (;; v = parent[head[v]]) {
                if (vertex_id[u] > vertex_id[v])std::swap(u, v);
                if (head[u] == head[v])return u;
            }
        }

        int distance(int u, int v)const {
            assert(0 <= u && u < n);
            assert(0 <= v && v < n);
            assert(tree_id[u] == tree_id[v]);
            return depth[u] + depth[v] - 2 * depth[lca(u, v)];
        }

        int jump(int u, int v, int i) const {
            assert(0 <= u and u < n);
            assert(0 <= v and v < n);
            assert(0 <= i);
            if (tree_id[u] != tree_id[v]) return -1;
            if (i == 0) return u;
            int p = lca(u, v), d = depth[u] + depth[v] - 2 * depth[p];
            if (d < i) return -1;
            if (depth[u] - depth[p] >= i) return ancestor(u, i);
            return ancestor(v, d - i);
        }

        template<typename Function> void path_query(int u, int v, const Function& f, bool is_vertex_query = false)const {
            assert(0 <= u and u < n);
            assert(0 <= v and v < n);
            assert(tree_id[u] == tree_id[v]);
            int p = lca(u, v);
            for (auto& e : ascend(u, p))f(e.second, e.first + 1);
            if (is_vertex_query)f(vertex_id[p], vertex_id[p] + 1);
            for (auto& e : descend(p, v))f(e.first, e.second + 1);
        }

        template<typename Function> void subtree_query(int u, const Function& f, bool is_vertex_query = false)const {
            assert(0 <= u && u < n);
            f(vertex_id[u] + !is_vertex_query, vertex_id[u] + size_of_subtree[u]);
        }


    private:
        void dfs_sz(int v) {
            size_of_subtree[v] = 1;
            if (!Forest[v].empty() && Forest[v].front() == parent[v])std::swap(Forest[v].front(), Forest[v].back());
            for (int& child : Forest[v]) {
                if (child == parent[v])continue;
                parent[child] = v;
                depth[child] = depth[v] + 1;
                dfs_sz(child);
                size_of_subtree[v] += size_of_subtree[child];
                if (size_of_subtree[child] > size_of_subtree[Forest[v].front()])std::swap(child, Forest[v].front());
            }
        }

        void dfs_hld(int v, int tree_idx) {
            vertex_id[v] = time++;
            tree_id[v] = tree_idx;
            for (int& child : Forest[v]) {
                if (child == parent[v])continue;
                head[child] = (child == Forest[v][0] ? head[v] : child);
                dfs_hld(child, tree_idx);
            }
        }

        std::vector<std::pair<int, int>> ascend(int u, int v)const { // [u, v) v is an ancestor of u
            std::vector<std::pair<int, int>> res;
            while (head[u] != head[v]) {
                res.emplace_back(vertex_id[u], vertex_id[head[u]]);
                u = parent[head[u]];
            }
            if (u != v)res.emplace_back(vertex_id[u], vertex_id[v] + 1);
            return res;
        }

        std::vector<std::pair<int, int>> descend(int u, int v)const { // (u, v] u is an ancestor of v
            if (u == v)return {};
            if (head[u] == head[v])return { {vertex_id[u] + 1, vertex_id[v]} };
            auto res = descend(u, parent[head[v]]);
            res.emplace_back(vertex_id[head[v]], vertex_id[v]);
            return res;
        }
    };

}// namespace tomo0608