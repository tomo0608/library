#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include<bits/stdc++.h>

namespace tomo0608 {
    template<class T>
    struct Binary_Indexed_Tree {
    public:
        Binary_Indexed_Tree():_n(0) {}
        Binary_Indexed_Tree(int n): _n(n) {
            for (int i = 0; i < 2; i++)data[i].assign(n, 0);
        }

        void add(int l, int r, T x) { // [l, r)にxを加算
            assert(0 <= l && l < r && r <= _n);
            add_sub(0, l, -x * (l - 1));
            add_sub(0, r, x * (r - 1));
            add_sub(1, l, x);
            add_sub(1, r, -x);
        }

        void add(int p, T x) { // pにxを加算
            assert(0 <= p && p < _n);
            add(p, p + 1, x);
        }

        T sum(int r) { // [0, r)
            return sum_sub(0, r) + sum_sub(1, r) * (r - 1);
        }
        T sum(int l, int r) { // [l,r)
            assert(0 <= l && l <= r && r <= _n);
            return sum(r) - sum(l);
        }
        T operator[](int r) { return sum(r + 1) - sum(r); }

        int lower_bound(T w) { // \sum_{i=0}^{x}a_x >= wとなるような最小のx なければn, ただしa_xは全て非負であることが条件
            if (w <= 0)return 0;
            int x = 0, r = 1;
            while (r < _n)r = r << 1;
            for (int len = r; len > 0; len = len >> 1) {
                if (x + len < _n && sum(x, x + len) < w) {
                    w -= sum(x, x + len);
                    x += len;
                }
            }
            if (w > 0)x++;
            return x;
        }

    private:
        int _n;
        std::vector<T> data[2];

        void add_sub(int i, int p, T x) { // 0-indexed
            assert(0 <= p && p <= _n);
            p++; // 内部では1-indexed
            while (p <= _n) {
                data[i][p - 1] += x;
                p += p & -p;
            }
        }
        T sum_sub(int i, int p) {
            T s = 0;
            for (int idx = p; idx > 0; idx -= (idx & -idx)) {
                s += data[i][idx - 1];
            }
            return s;
        }
    };
}
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

using namespace std;

int main() {
    int n, q;cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    tomo0608::HeavyLightDecomposition g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;cin >> u >> v;
        g.add_edge(u, v);
    }
    g.build();

    tomo0608::Binary_Indexed_Tree<long long> BIT(n);
    for (int i = 0; i < n; i++) {
        BIT.add(g.idx(i), a[i]);
    }

    while (q--) {
        int query_type;cin >> query_type;
        if (query_type == 0) {
            long long p, x;cin >> p >> x;
            BIT.add(g.idx(p), x);
        }
        else {
            int u, v;cin >> u >> v;
            long long ans = 0;
            auto f = [&](int s, int t) {return ans += BIT.sum(s, t);};
            g.path_query(u, v, f, true);
            cout << ans << endl;
        }
    }
    return 0;
}