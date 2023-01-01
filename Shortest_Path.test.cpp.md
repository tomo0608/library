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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"Shortest_Path.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\
    \n\n#include<cassert>\n#include<vector>\n#include<limits>\n#include<queue>\n#include<algorithm>\n\
    #include<iostream>\n\nclass Weighted_Digraph {\npublic:\n    std::vector<std::vector<std::pair<long\
    \ long, int>>> Adjacency_List, Transpose;\n    unsigned number_of_nodes;\n   \
    \ Weighted_Digraph(unsigned n): number_of_nodes(n), Adjacency_List(n), Transpose(n)\
    \ {};\n\n    void add_edge(int from, int to, unsigned long long weight) {\n  \
    \      assert(0 <= from && from < number_of_nodes);\n        assert(0 <= to &&\
    \ to < number_of_nodes);\n        Adjacency_List[from].emplace_back(weight, to);\n\
    \        Transpose[to].emplace_back(weight, from);\n    }\n\n    std::pair<std::vector<long\
    \ long>, std::vector<int>> Dijkstra(int start) { // start\u3092\u59CB\u70B9\u3068\
    \u3057\u305F\u6700\u77ED\u8DDD\u96E2\u3092\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\
    \u6CD5\u3067\u6C42\u3081\u308B, (\u6700\u77ED\u8DDD\u96E2\u306E\u30EA\u30B9\u30C8\
    , \u6700\u77ED\u7D4C\u8DEF\u6728\u306E\u89AA\u306E\u60C5\u5831)\n        std::vector<long\
    \ long> Dist(number_of_nodes, -1);\n        std::vector<int> par(number_of_nodes,\
    \ -1);\n        using P = std::pair<long long, int>;\n        std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> pq;\n        Dist[start] = 0;\n        pq.emplace(0,\
    \ start);\n        while (!pq.empty()) {\n            auto [d, u] = pq.top();\n\
    \            pq.pop();\n            if (Dist[u] < d)continue;\n            for\
    \ (auto& [w, v] : Adjacency_List[u]) {\n                if (Dist[v] == -1 || Dist[v]\
    \ > Dist[u] + w) {\n                    Dist[v] = Dist[u] + w;\n             \
    \       pq.emplace(Dist[v], v);\n                    par[v] = u;\n           \
    \     }\n            }\n        }\n        return std::make_pair(Dist, par);\n\
    \    }\n};\n\nstd::vector<int> restore_path(std::vector<int> par, int goal) {\n\
    \    std::vector<int> path = { goal };\n    while (par[path.back()] != -1)path.emplace_back(par[path.back()]);\n\
    \    std::reverse(path.begin(), path.end());\n    return path;\n}\n\n\nusing namespace\
    \ std;\n\nint main() {\n    unsigned n, m, s, t;cin >> n >> m >> s >> t;\n   \
    \ Weighted_Digraph g(n);\n    for (int i = 0; i < m; i++) {\n        unsigned\
    \ a, b;cin >> a >> b;\n        long long c;cin >> c;\n        g.add_edge(a, b,\
    \ c);\n    }\n\n    auto [dist, par] = g.Dijkstra(s);\n    if (dist[t] == -1)\
    \ {\n        cout << -1 << endl;\n        return 0;\n    }\n    auto path = restore_path(par,\
    \ t);\n    cout << dist[t] << ' ' << path.size() - 1 << endl;\n    for (int i\
    \ = 0; i < path.size() - 1; i++)cout << path[i] << ' ' << path[i + 1] << endl;\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include<cassert>\n\
    #include<vector>\n#include<limits>\n#include<queue>\n#include<algorithm>\n#include<iostream>\n\
    \nclass Weighted_Digraph {\npublic:\n    std::vector<std::vector<std::pair<long\
    \ long, int>>> Adjacency_List, Transpose;\n    unsigned number_of_nodes;\n   \
    \ Weighted_Digraph(unsigned n): number_of_nodes(n), Adjacency_List(n), Transpose(n)\
    \ {};\n\n    void add_edge(int from, int to, unsigned long long weight) {\n  \
    \      assert(0 <= from && from < number_of_nodes);\n        assert(0 <= to &&\
    \ to < number_of_nodes);\n        Adjacency_List[from].emplace_back(weight, to);\n\
    \        Transpose[to].emplace_back(weight, from);\n    }\n\n    std::pair<std::vector<long\
    \ long>, std::vector<int>> Dijkstra(int start) { // start\u3092\u59CB\u70B9\u3068\
    \u3057\u305F\u6700\u77ED\u8DDD\u96E2\u3092\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\
    \u6CD5\u3067\u6C42\u3081\u308B, (\u6700\u77ED\u8DDD\u96E2\u306E\u30EA\u30B9\u30C8\
    , \u6700\u77ED\u7D4C\u8DEF\u6728\u306E\u89AA\u306E\u60C5\u5831)\n        std::vector<long\
    \ long> Dist(number_of_nodes, -1);\n        std::vector<int> par(number_of_nodes,\
    \ -1);\n        using P = std::pair<long long, int>;\n        std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> pq;\n        Dist[start] = 0;\n        pq.emplace(0,\
    \ start);\n        while (!pq.empty()) {\n            auto [d, u] = pq.top();\n\
    \            pq.pop();\n            if (Dist[u] < d)continue;\n            for\
    \ (auto& [w, v] : Adjacency_List[u]) {\n                if (Dist[v] == -1 || Dist[v]\
    \ > Dist[u] + w) {\n                    Dist[v] = Dist[u] + w;\n             \
    \       pq.emplace(Dist[v], v);\n                    par[v] = u;\n           \
    \     }\n            }\n        }\n        return std::make_pair(Dist, par);\n\
    \    }\n};\n\nstd::vector<int> restore_path(std::vector<int> par, int goal) {\n\
    \    std::vector<int> path = { goal };\n    while (par[path.back()] != -1)path.emplace_back(par[path.back()]);\n\
    \    std::reverse(path.begin(), path.end());\n    return path;\n}\n\n\nusing namespace\
    \ std;\n\nint main() {\n    unsigned n, m, s, t;cin >> n >> m >> s >> t;\n   \
    \ Weighted_Digraph g(n);\n    for (int i = 0; i < m; i++) {\n        unsigned\
    \ a, b;cin >> a >> b;\n        long long c;cin >> c;\n        g.add_edge(a, b,\
    \ c);\n    }\n\n    auto [dist, par] = g.Dijkstra(s);\n    if (dist[t] == -1)\
    \ {\n        cout << -1 << endl;\n        return 0;\n    }\n    auto path = restore_path(par,\
    \ t);\n    cout << dist[t] << ' ' << path.size() - 1 << endl;\n    for (int i\
    \ = 0; i < path.size() - 1; i++)cout << path[i] << ' ' << path[i + 1] << endl;\n\
    \    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: Shortest_Path.test.cpp
  requiredBy: []
  timestamp: '2023-01-01 10:59:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Shortest_Path.test.cpp
layout: document
redirect_from:
- /verify/Shortest_Path.test.cpp
- /verify/Shortest_Path.test.cpp.html
title: Shortest_Path.test.cpp
---
