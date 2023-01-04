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
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"tree_diameter.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\
    \n\n#include<iostream>\n#include<algorithm>\n#include<vector>\n#include<utility>\n\
    #include<queue>\n#include<tuple>\n\nstd::vector<int> restore_path(std::vector<int>\
    \ par, int goal) {\n    std::vector<int> path = { goal };\n    while (par[path.back()]\
    \ != -1)path.emplace_back(par[path.back()]);\n    std::reverse(path.begin(), path.end());\n\
    \    return path;\n}\n\nusing namespace std;\n\nint main() {\n    int n;\n   \
    \ cin >> n;\n    vector<vector<pair<int, long long>>> wt(n);\n    for (int i =\
    \ 0; i < n - 1; i++) {\n        int a, b;\n        long long c;\n        cin >>\
    \ a >> b >> c;\n        wt[a].emplace_back(b, c);\n        wt[b].emplace_back(a,\
    \ c);\n    }\n    auto get_dist = [&](int st)->tuple<vector<long long>, vector<int>,\
    \ int> {\n        vector<long long> dist(n, -1);\n        vector<int> par(n, -1);\n\
    \        dist[st] = 0;\n        queue<int> que;\n        que.emplace(st);\n  \
    \      int farthest_point = st;\n        long long max_dist = 0;\n        while\
    \ (!que.empty()) {\n            int now = que.front();\n            que.pop();\n\
    \            for (auto& [to, cost] : wt[now]) {\n                if (dist[to]\
    \ == -1) {\n                    dist[to] = dist[now] + cost;\n               \
    \     if (max_dist < dist[to]) {\n                        max_dist = dist[to];\n\
    \                        farthest_point = to;\n                    }\n       \
    \             que.emplace(to);\n                    par[to] = now;\n         \
    \       }\n            }\n        }\n        return make_tuple(dist, par, farthest_point);\n\
    \    };\n\n    auto [_, __, s] = get_dist(0);\n    auto [dist, par, t] = get_dist(s);\n\
    \n    auto path = restore_path(par, t);\n    cout << dist[t] << ' ' << path.size()\
    \ << endl;\n    for (int i = 0; i < path.size(); i++)cout << path[i] << ' ';\n\
    \    cout << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include<iostream>\n\
    #include<algorithm>\n#include<vector>\n#include<utility>\n#include<queue>\n#include<tuple>\n\
    \nstd::vector<int> restore_path(std::vector<int> par, int goal) {\n    std::vector<int>\
    \ path = { goal };\n    while (par[path.back()] != -1)path.emplace_back(par[path.back()]);\n\
    \    std::reverse(path.begin(), path.end());\n    return path;\n}\n\nusing namespace\
    \ std;\n\nint main() {\n    int n;\n    cin >> n;\n    vector<vector<pair<int,\
    \ long long>>> wt(n);\n    for (int i = 0; i < n - 1; i++) {\n        int a, b;\n\
    \        long long c;\n        cin >> a >> b >> c;\n        wt[a].emplace_back(b,\
    \ c);\n        wt[b].emplace_back(a, c);\n    }\n    auto get_dist = [&](int st)->tuple<vector<long\
    \ long>, vector<int>, int> {\n        vector<long long> dist(n, -1);\n       \
    \ vector<int> par(n, -1);\n        dist[st] = 0;\n        queue<int> que;\n  \
    \      que.emplace(st);\n        int farthest_point = st;\n        long long max_dist\
    \ = 0;\n        while (!que.empty()) {\n            int now = que.front();\n \
    \           que.pop();\n            for (auto& [to, cost] : wt[now]) {\n     \
    \           if (dist[to] == -1) {\n                    dist[to] = dist[now] +\
    \ cost;\n                    if (max_dist < dist[to]) {\n                    \
    \    max_dist = dist[to];\n                        farthest_point = to;\n    \
    \                }\n                    que.emplace(to);\n                   \
    \ par[to] = now;\n                }\n            }\n        }\n        return\
    \ make_tuple(dist, par, farthest_point);\n    };\n\n    auto [_, __, s] = get_dist(0);\n\
    \    auto [dist, par, t] = get_dist(s);\n\n    auto path = restore_path(par, t);\n\
    \    cout << dist[t] << ' ' << path.size() << endl;\n    for (int i = 0; i < path.size();\
    \ i++)cout << path[i] << ' ';\n    cout << endl;\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2023-01-04 18:51:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/tree_diameter.test.cpp
- /verify/tree_diameter.test.cpp.html
title: tree_diameter.test.cpp
---
