---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Heavy_Light_Decomposition.hpp
    title: lib/Heavy_Light_Decomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/lca.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n\n#include<bits/stdc++.h>\n\n#line 2 \"lib/Heavy_Light_Decomposition.hpp\"\n\
    \nnamespace tomo0608 {\n    struct HeavyLightDecomposition {\n        std::vector<std::vector<int>>\
    \ Forest; // The child of vertex v on heavy edge is G[v][0] unless v is a leaf\n\
    \        int n, time;\n        std::vector<int> parent,    // The parent of vertex\
    \ v\n            size_of_subtree,        // The size of subtree whose root is\
    \ v\n            depth,                  // The distance between the root and\
    \ v\n            head,                   // The vertex closest to the root in\
    \ the heavy path containing v\n            tree_id,                // ID of the\
    \ tree to which vertex v belongs\n            vertex_id,              // ID of\
    \ vertex v\n            vertex_id_inv;\n\n        HeavyLightDecomposition(int\
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
    \ return res;\n        }\n    };\n\n}// namespace tomo0608\n#line 6 \"test/lca.test.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n    int n, q;cin >> n >> q;\n    tomo0608::HeavyLightDecomposition\
    \ g(n);\n    for (int i = 1; i < n; i++) {\n        int p;cin >> p;\n        g.add_edge(i,\
    \ p);\n    }\n    g.build();\n    while (q--) {\n        int u, v;cin >> u >>\
    \ v;\n        cout << g.lca(u, v) << endl;\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include<bits/stdc++.h>\n\
    \n#include \"../lib/Heavy_Light_Decomposition.hpp\"\n\nusing namespace std;\n\n\
    int main() {\n    int n, q;cin >> n >> q;\n    tomo0608::HeavyLightDecomposition\
    \ g(n);\n    for (int i = 1; i < n; i++) {\n        int p;cin >> p;\n        g.add_edge(i,\
    \ p);\n    }\n    g.build();\n    while (q--) {\n        int u, v;cin >> u >>\
    \ v;\n        cout << g.lca(u, v) << endl;\n    }\n    return 0;\n}"
  dependsOn:
  - lib/Heavy_Light_Decomposition.hpp
  isVerificationFile: true
  path: test/lca.test.cpp
  requiredBy: []
  timestamp: '2023-04-14 17:06:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/lca.test.cpp
layout: document
redirect_from:
- /verify/test/lca.test.cpp
- /verify/test/lca.test.cpp.html
title: test/lca.test.cpp
---
