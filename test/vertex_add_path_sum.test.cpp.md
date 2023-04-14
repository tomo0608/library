---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/vertex_add_path_sum.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n#include<bits/stdc++.h>\n\
    \nnamespace tomo0608 {\n    template<class T>\n    struct Binary_Indexed_Tree\
    \ {\n    public:\n        Binary_Indexed_Tree():_n(0) {}\n        Binary_Indexed_Tree(int\
    \ n): _n(n) {\n            for (int i = 0; i < 2; i++)data[i].assign(n, 0);\n\
    \        }\n\n        void add(int l, int r, T x) { // [l, r)\u306Bx\u3092\u52A0\
    \u7B97\n            assert(0 <= l && l < r && r <= _n);\n            add_sub(0,\
    \ l, -x * (l - 1));\n            add_sub(0, r, x * (r - 1));\n            add_sub(1,\
    \ l, x);\n            add_sub(1, r, -x);\n        }\n\n        void add(int p,\
    \ T x) { // p\u306Bx\u3092\u52A0\u7B97\n            assert(0 <= p && p < _n);\n\
    \            add(p, p + 1, x);\n        }\n\n        T sum(int r) { // [0, r)\n\
    \            return sum_sub(0, r) + sum_sub(1, r) * (r - 1);\n        }\n    \
    \    T sum(int l, int r) { // [l,r)\n            assert(0 <= l && l <= r && r\
    \ <= _n);\n            return sum(r) - sum(l);\n        }\n        T operator[](int\
    \ r) { return sum(r + 1) - sum(r); }\n\n        int lower_bound(T w) { // \\sum_{i=0}^{x}a_x\
    \ >= w\u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5C0F\u306Ex \u306A\u3051\u308C\
    \u3070n, \u305F\u3060\u3057a_x\u306F\u5168\u3066\u975E\u8CA0\u3067\u3042\u308B\
    \u3053\u3068\u304C\u6761\u4EF6\n            if (w <= 0)return 0;\n           \
    \ int x = 0, r = 1;\n            while (r < _n)r = r << 1;\n            for (int\
    \ len = r; len > 0; len = len >> 1) {\n                if (x + len < _n && sum(x,\
    \ x + len) < w) {\n                    w -= sum(x, x + len);\n               \
    \     x += len;\n                }\n            }\n            if (w > 0)x++;\n\
    \            return x;\n        }\n\n    private:\n        int _n;\n        std::vector<T>\
    \ data[2];\n\n        void add_sub(int i, int p, T x) { // 0-indexed\n       \
    \     assert(0 <= p && p <= _n);\n            p++; // \u5185\u90E8\u3067\u306F\
    1-indexed\n            while (p <= _n) {\n                data[i][p - 1] += x;\n\
    \                p += p & -p;\n            }\n        }\n        T sum_sub(int\
    \ i, int p) {\n            T s = 0;\n            for (int idx = p; idx > 0; idx\
    \ -= (idx & -idx)) {\n                s += data[i][idx - 1];\n            }\n\
    \            return s;\n        }\n    };\n}\nnamespace tomo0608 {\n    struct\
    \ HeavyLightDecomposition {\n        std::vector<std::vector<int>> Forest; //\
    \ The child of vertex v on heavy edge is G[v][0] unless v is a leaf\n        int\
    \ n, time;\n        std::vector<int> parent,    // The parent of vertex v\n  \
    \          size_of_subtree,        // The size of subtree whose root is v\n  \
    \          depth,                  // The distance between the root and v\n  \
    \          head,                   // The vertex closest to the root in the heavy\
    \ path containing v\n            tree_id,                // ID of the tree to\
    \ which vertex v belongs\n            vertex_id,              // ID of vertex\
    \ v\n            vertex_id_inv;\n\n        HeavyLightDecomposition(int n):\n \
    \           Forest(n),\n            n(n),\n            time(0),\n            parent(n,\
    \ -1),\n            size_of_subtree(n),\n            depth(n),\n            head(n),\n\
    \            tree_id(n, -1),\n            vertex_id(n, -1),\n            vertex_id_inv(n)\
    \ {}\n\n        HeavyLightDecomposition(std::vector<std::vector<int>>& G):\n \
    \           Forest(G),\n            n(G.size()),\n            time(0),\n     \
    \       parent(G.size(), -1),\n            size_of_subtree(G.size()),\n      \
    \      depth(G.size()),\n            head(G.size()),\n            tree_id(G.size(),\
    \ -1),\n            vertex_id(G.size(), -1),\n            vertex_id_inv(G.size())\
    \ {}\n\n        void add_edge(int u, int v) {\n            assert(0 <= u && u\
    \ < n);\n            assert(0 <= v && v < n);\n            Forest[u].emplace_back(v);\n\
    \            Forest[v].emplace_back(u);\n        }\n\n        void build(std::vector<int>\
    \ roots_of_Forest = { 0 }) {\n            int tree_idx = 0;\n            for (int&\
    \ root : roots_of_Forest) {\n                assert(0 <= root && root < n);\n\
    \                dfs_sz(root);\n                head[root] = root;\n         \
    \       dfs_hld(root, tree_idx++);\n            }\n            assert(time ==\
    \ n);\n            for (int v = 0; v < n; v++)vertex_id_inv[vertex_id[v]] = v;\n\
    \        }\n\n        int idx(int v)const { return vertex_id[v]; }\n\n       \
    \ int ancestor(int v, int k)const {\n            assert(0 <= v && v < n);\n  \
    \          assert(0 <= k && k <= depth[v]);\n            while (true) {\n    \
    \            int u = head[v];\n                if (vertex_id[v] - vertex_id[u]\
    \ >= k)return vertex_id_inv[vertex_id[v] - k];\n                k -= vertex_id[v]\
    \ - vertex_id[u] + 1;\n                v = parent[u];\n            }\n       \
    \ }\n\n        int lca(int u, int v) const {\n            assert(0 <= u && u <\
    \ n);\n            assert(0 <= v && v < n);\n            assert(tree_id[u] ==\
    \ tree_id[v]);\n            for (;; v = parent[head[v]]) {\n                if\
    \ (vertex_id[u] > vertex_id[v])std::swap(u, v);\n                if (head[u] ==\
    \ head[v])return u;\n            }\n        }\n\n        int distance(int u, int\
    \ v)const {\n            assert(0 <= u && u < n);\n            assert(0 <= v &&\
    \ v < n);\n            assert(tree_id[u] == tree_id[v]);\n            return depth[u]\
    \ + depth[v] - 2 * depth[lca(u, v)];\n        }\n\n        int jump(int u, int\
    \ v, int i) const {\n            assert(0 <= u and u < n);\n            assert(0\
    \ <= v and v < n);\n            assert(0 <= i);\n            if (tree_id[u] !=\
    \ tree_id[v]) return -1;\n            if (i == 0) return u;\n            int p\
    \ = lca(u, v), d = depth[u] + depth[v] - 2 * depth[p];\n            if (d < i)\
    \ return -1;\n            if (depth[u] - depth[p] >= i) return ancestor(u, i);\n\
    \            return ancestor(v, d - i);\n        }\n\n        template<typename\
    \ Function> void path_query(int u, int v, const Function& f, bool is_vertex_query\
    \ = false)const {\n            assert(0 <= u and u < n);\n            assert(0\
    \ <= v and v < n);\n            assert(tree_id[u] == tree_id[v]);\n          \
    \  int p = lca(u, v);\n            for (auto& e : ascend(u, p))f(e.second, e.first\
    \ + 1);\n            if (is_vertex_query)f(vertex_id[p], vertex_id[p] + 1);\n\
    \            for (auto& e : descend(p, v))f(e.first, e.second + 1);\n        }\n\
    \n        template<typename Function> void subtree_query(int u, const Function&\
    \ f, bool is_vertex_query = false)const {\n            assert(0 <= u && u < n);\n\
    \            f(vertex_id[u] + !is_vertex_query, vertex_id[u] + size_of_subtree[u]);\n\
    \        }\n\n\n    private:\n        void dfs_sz(int v) {\n            size_of_subtree[v]\
    \ = 1;\n            if (!Forest[v].empty() && Forest[v].front() == parent[v])std::swap(Forest[v].front(),\
    \ Forest[v].back());\n            for (int& child : Forest[v]) {\n           \
    \     if (child == parent[v])continue;\n                parent[child] = v;\n \
    \               depth[child] = depth[v] + 1;\n                dfs_sz(child);\n\
    \                size_of_subtree[v] += size_of_subtree[child];\n             \
    \   if (size_of_subtree[child] > size_of_subtree[Forest[v].front()])std::swap(child,\
    \ Forest[v].front());\n            }\n        }\n\n        void dfs_hld(int v,\
    \ int tree_idx) {\n            vertex_id[v] = time++;\n            tree_id[v]\
    \ = tree_idx;\n            for (int& child : Forest[v]) {\n                if\
    \ (child == parent[v])continue;\n                head[child] = (child == Forest[v][0]\
    \ ? head[v] : child);\n                dfs_hld(child, tree_idx);\n           \
    \ }\n        }\n\n        std::vector<std::pair<int, int>> ascend(int u, int v)const\
    \ { // [u, v) v is an ancestor of u\n            std::vector<std::pair<int, int>>\
    \ res;\n            while (head[u] != head[v]) {\n                res.emplace_back(vertex_id[u],\
    \ vertex_id[head[u]]);\n                u = parent[head[u]];\n            }\n\
    \            if (u != v)res.emplace_back(vertex_id[u], vertex_id[v] + 1);\n  \
    \          return res;\n        }\n\n        std::vector<std::pair<int, int>>\
    \ descend(int u, int v)const { // (u, v] u is an ancestor of v\n            if\
    \ (u == v)return {};\n            if (head[u] == head[v])return { {vertex_id[u]\
    \ + 1, vertex_id[v]} };\n            auto res = descend(u, parent[head[v]]);\n\
    \            res.emplace_back(vertex_id[head[v]], vertex_id[v]);\n           \
    \ return res;\n        }\n    };\n\n}// namespace tomo0608\n\nusing namespace\
    \ std;\n\nint main() {\n    int n, q;cin >> n >> q;\n    vector<long long> a(n);\n\
    \    for (int i = 0; i < n; i++)cin >> a[i];\n    tomo0608::HeavyLightDecomposition\
    \ g(n);\n    for (int i = 0; i < n - 1; i++) {\n        int u, v;cin >> u >> v;\n\
    \        g.add_edge(u, v);\n    }\n    g.build();\n\n    tomo0608::Binary_Indexed_Tree<long\
    \ long> BIT(n);\n    for (int i = 0; i < n; i++) {\n        BIT.add(g.idx(i),\
    \ a[i]);\n    }\n\n    while (q--) {\n        int query_type;cin >> query_type;\n\
    \        if (query_type == 0) {\n            long long p, x;cin >> p >> x;\n \
    \           BIT.add(g.idx(p), x);\n        }\n        else {\n            int\
    \ u, v;cin >> u >> v;\n            long long ans = 0;\n            auto f = [&](int\
    \ s, int t) {return ans += BIT.sum(s, t);};\n            g.path_query(u, v, f,\
    \ true);\n            cout << ans << endl;\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    #include<bits/stdc++.h>\n\nnamespace tomo0608 {\n    template<class T>\n    struct\
    \ Binary_Indexed_Tree {\n    public:\n        Binary_Indexed_Tree():_n(0) {}\n\
    \        Binary_Indexed_Tree(int n): _n(n) {\n            for (int i = 0; i <\
    \ 2; i++)data[i].assign(n, 0);\n        }\n\n        void add(int l, int r, T\
    \ x) { // [l, r)\u306Bx\u3092\u52A0\u7B97\n            assert(0 <= l && l < r\
    \ && r <= _n);\n            add_sub(0, l, -x * (l - 1));\n            add_sub(0,\
    \ r, x * (r - 1));\n            add_sub(1, l, x);\n            add_sub(1, r, -x);\n\
    \        }\n\n        void add(int p, T x) { // p\u306Bx\u3092\u52A0\u7B97\n \
    \           assert(0 <= p && p < _n);\n            add(p, p + 1, x);\n       \
    \ }\n\n        T sum(int r) { // [0, r)\n            return sum_sub(0, r) + sum_sub(1,\
    \ r) * (r - 1);\n        }\n        T sum(int l, int r) { // [l,r)\n         \
    \   assert(0 <= l && l <= r && r <= _n);\n            return sum(r) - sum(l);\n\
    \        }\n        T operator[](int r) { return sum(r + 1) - sum(r); }\n\n  \
    \      int lower_bound(T w) { // \\sum_{i=0}^{x}a_x >= w\u3068\u306A\u308B\u3088\
    \u3046\u306A\u6700\u5C0F\u306Ex \u306A\u3051\u308C\u3070n, \u305F\u3060\u3057\
    a_x\u306F\u5168\u3066\u975E\u8CA0\u3067\u3042\u308B\u3053\u3068\u304C\u6761\u4EF6\
    \n            if (w <= 0)return 0;\n            int x = 0, r = 1;\n          \
    \  while (r < _n)r = r << 1;\n            for (int len = r; len > 0; len = len\
    \ >> 1) {\n                if (x + len < _n && sum(x, x + len) < w) {\n      \
    \              w -= sum(x, x + len);\n                    x += len;\n        \
    \        }\n            }\n            if (w > 0)x++;\n            return x;\n\
    \        }\n\n    private:\n        int _n;\n        std::vector<T> data[2];\n\
    \n        void add_sub(int i, int p, T x) { // 0-indexed\n            assert(0\
    \ <= p && p <= _n);\n            p++; // \u5185\u90E8\u3067\u306F1-indexed\n \
    \           while (p <= _n) {\n                data[i][p - 1] += x;\n        \
    \        p += p & -p;\n            }\n        }\n        T sum_sub(int i, int\
    \ p) {\n            T s = 0;\n            for (int idx = p; idx > 0; idx -= (idx\
    \ & -idx)) {\n                s += data[i][idx - 1];\n            }\n        \
    \    return s;\n        }\n    };\n}\nnamespace tomo0608 {\n    struct HeavyLightDecomposition\
    \ {\n        std::vector<std::vector<int>> Forest; // The child of vertex v on\
    \ heavy edge is G[v][0] unless v is a leaf\n        int n, time;\n        std::vector<int>\
    \ parent,    // The parent of vertex v\n            size_of_subtree,        //\
    \ The size of subtree whose root is v\n            depth,                  //\
    \ The distance between the root and v\n            head,                   //\
    \ The vertex closest to the root in the heavy path containing v\n            tree_id,\
    \                // ID of the tree to which vertex v belongs\n            vertex_id,\
    \              // ID of vertex v\n            vertex_id_inv;\n\n        HeavyLightDecomposition(int\
    \ n):\n            Forest(n),\n            n(n),\n            time(0),\n     \
    \       parent(n, -1),\n            size_of_subtree(n),\n            depth(n),\n\
    \            head(n),\n            tree_id(n, -1),\n            vertex_id(n, -1),\n\
    \            vertex_id_inv(n) {}\n\n        HeavyLightDecomposition(std::vector<std::vector<int>>&\
    \ G):\n            Forest(G),\n            n(G.size()),\n            time(0),\n\
    \            parent(G.size(), -1),\n            size_of_subtree(G.size()),\n \
    \           depth(G.size()),\n            head(G.size()),\n            tree_id(G.size(),\
    \ -1),\n            vertex_id(G.size(), -1),\n            vertex_id_inv(G.size())\
    \ {}\n\n        void add_edge(int u, int v) {\n            assert(0 <= u && u\
    \ < n);\n            assert(0 <= v && v < n);\n            Forest[u].emplace_back(v);\n\
    \            Forest[v].emplace_back(u);\n        }\n\n        void build(std::vector<int>\
    \ roots_of_Forest = { 0 }) {\n            int tree_idx = 0;\n            for (int&\
    \ root : roots_of_Forest) {\n                assert(0 <= root && root < n);\n\
    \                dfs_sz(root);\n                head[root] = root;\n         \
    \       dfs_hld(root, tree_idx++);\n            }\n            assert(time ==\
    \ n);\n            for (int v = 0; v < n; v++)vertex_id_inv[vertex_id[v]] = v;\n\
    \        }\n\n        int idx(int v)const { return vertex_id[v]; }\n\n       \
    \ int ancestor(int v, int k)const {\n            assert(0 <= v && v < n);\n  \
    \          assert(0 <= k && k <= depth[v]);\n            while (true) {\n    \
    \            int u = head[v];\n                if (vertex_id[v] - vertex_id[u]\
    \ >= k)return vertex_id_inv[vertex_id[v] - k];\n                k -= vertex_id[v]\
    \ - vertex_id[u] + 1;\n                v = parent[u];\n            }\n       \
    \ }\n\n        int lca(int u, int v) const {\n            assert(0 <= u && u <\
    \ n);\n            assert(0 <= v && v < n);\n            assert(tree_id[u] ==\
    \ tree_id[v]);\n            for (;; v = parent[head[v]]) {\n                if\
    \ (vertex_id[u] > vertex_id[v])std::swap(u, v);\n                if (head[u] ==\
    \ head[v])return u;\n            }\n        }\n\n        int distance(int u, int\
    \ v)const {\n            assert(0 <= u && u < n);\n            assert(0 <= v &&\
    \ v < n);\n            assert(tree_id[u] == tree_id[v]);\n            return depth[u]\
    \ + depth[v] - 2 * depth[lca(u, v)];\n        }\n\n        int jump(int u, int\
    \ v, int i) const {\n            assert(0 <= u and u < n);\n            assert(0\
    \ <= v and v < n);\n            assert(0 <= i);\n            if (tree_id[u] !=\
    \ tree_id[v]) return -1;\n            if (i == 0) return u;\n            int p\
    \ = lca(u, v), d = depth[u] + depth[v] - 2 * depth[p];\n            if (d < i)\
    \ return -1;\n            if (depth[u] - depth[p] >= i) return ancestor(u, i);\n\
    \            return ancestor(v, d - i);\n        }\n\n        template<typename\
    \ Function> void path_query(int u, int v, const Function& f, bool is_vertex_query\
    \ = false)const {\n            assert(0 <= u and u < n);\n            assert(0\
    \ <= v and v < n);\n            assert(tree_id[u] == tree_id[v]);\n          \
    \  int p = lca(u, v);\n            for (auto& e : ascend(u, p))f(e.second, e.first\
    \ + 1);\n            if (is_vertex_query)f(vertex_id[p], vertex_id[p] + 1);\n\
    \            for (auto& e : descend(p, v))f(e.first, e.second + 1);\n        }\n\
    \n        template<typename Function> void subtree_query(int u, const Function&\
    \ f, bool is_vertex_query = false)const {\n            assert(0 <= u && u < n);\n\
    \            f(vertex_id[u] + !is_vertex_query, vertex_id[u] + size_of_subtree[u]);\n\
    \        }\n\n\n    private:\n        void dfs_sz(int v) {\n            size_of_subtree[v]\
    \ = 1;\n            if (!Forest[v].empty() && Forest[v].front() == parent[v])std::swap(Forest[v].front(),\
    \ Forest[v].back());\n            for (int& child : Forest[v]) {\n           \
    \     if (child == parent[v])continue;\n                parent[child] = v;\n \
    \               depth[child] = depth[v] + 1;\n                dfs_sz(child);\n\
    \                size_of_subtree[v] += size_of_subtree[child];\n             \
    \   if (size_of_subtree[child] > size_of_subtree[Forest[v].front()])std::swap(child,\
    \ Forest[v].front());\n            }\n        }\n\n        void dfs_hld(int v,\
    \ int tree_idx) {\n            vertex_id[v] = time++;\n            tree_id[v]\
    \ = tree_idx;\n            for (int& child : Forest[v]) {\n                if\
    \ (child == parent[v])continue;\n                head[child] = (child == Forest[v][0]\
    \ ? head[v] : child);\n                dfs_hld(child, tree_idx);\n           \
    \ }\n        }\n\n        std::vector<std::pair<int, int>> ascend(int u, int v)const\
    \ { // [u, v) v is an ancestor of u\n            std::vector<std::pair<int, int>>\
    \ res;\n            while (head[u] != head[v]) {\n                res.emplace_back(vertex_id[u],\
    \ vertex_id[head[u]]);\n                u = parent[head[u]];\n            }\n\
    \            if (u != v)res.emplace_back(vertex_id[u], vertex_id[v] + 1);\n  \
    \          return res;\n        }\n\n        std::vector<std::pair<int, int>>\
    \ descend(int u, int v)const { // (u, v] u is an ancestor of v\n            if\
    \ (u == v)return {};\n            if (head[u] == head[v])return { {vertex_id[u]\
    \ + 1, vertex_id[v]} };\n            auto res = descend(u, parent[head[v]]);\n\
    \            res.emplace_back(vertex_id[head[v]], vertex_id[v]);\n           \
    \ return res;\n        }\n    };\n\n}// namespace tomo0608\n\nusing namespace\
    \ std;\n\nint main() {\n    int n, q;cin >> n >> q;\n    vector<long long> a(n);\n\
    \    for (int i = 0; i < n; i++)cin >> a[i];\n    tomo0608::HeavyLightDecomposition\
    \ g(n);\n    for (int i = 0; i < n - 1; i++) {\n        int u, v;cin >> u >> v;\n\
    \        g.add_edge(u, v);\n    }\n    g.build();\n\n    tomo0608::Binary_Indexed_Tree<long\
    \ long> BIT(n);\n    for (int i = 0; i < n; i++) {\n        BIT.add(g.idx(i),\
    \ a[i]);\n    }\n\n    while (q--) {\n        int query_type;cin >> query_type;\n\
    \        if (query_type == 0) {\n            long long p, x;cin >> p >> x;\n \
    \           BIT.add(g.idx(p), x);\n        }\n        else {\n            int\
    \ u, v;cin >> u >> v;\n            long long ans = 0;\n            auto f = [&](int\
    \ s, int t) {return ans += BIT.sum(s, t);};\n            g.path_query(u, v, f,\
    \ true);\n            cout << ans << endl;\n        }\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2023-04-14 17:06:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_add_path_sum.test.cpp
- /verify/test/vertex_add_path_sum.test.cpp.html
title: test/vertex_add_path_sum.test.cpp
---
