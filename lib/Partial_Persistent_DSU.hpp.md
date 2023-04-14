---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/Partial_Persistent_DSU.hpp\"\n#include<vector>\n#include<cassert>\n\
    \n\nnamespace tomo0608 {\n    struct pp_dsu {\n    public:\n        pp_dsu() :\
    \ _n(0) {}\n        pp_dsu(int n) : _n(n), parent_or_size(n, -1), num(n), time(n,\
    \ 1e9) {\n            for (int i = 0; i < _n; ++i)num[i].emplace_back(-1, -1);\n\
    \        }\n        // \u6642\u523Bt\u306B\u304A\u3051\u308Bx\u306E\u89AA\u3092\
    \u8FD4\u3059\n        int find(int a, int t) {\n            assert(0 <= a && a\
    \ < _n);\n            assert(0 <= t && t < 1e9);\n            if (time[a] == -1\
    \ || t < time[a])return a;\n            return find(parent_or_size[a], t);\n \
    \       }\n\n        bool same(int a, int b, int t) {\n            assert(0 <=\
    \ a && a < _n && 0 <= b && b < _n);\n            return find(a, t) == find(b,\
    \ t);\n        }\n\n        bool merge(int a, int b, int t) {\n            assert(0\
    \ <= a && a < _n && 0 <= b && b < _n);\n            assert(0 <= t && t < 1e9);\n\
    \            int x = find(a, t), y = find(b, t);\n            if (x == y)return\
    \ true;\n            if (-parent_or_size[x] < -parent_or_size[y])std::swap(x,\
    \ y);\n            parent_or_size[x] += parent_or_size[y];\n            parent_or_size[y]\
    \ = x;\n            time[y] = t;\n            num[x].emplace_back(t, parent_or_size[x]);\n\
    \            return false;\n        }\n\n        int size(int a, int t) {\n  \
    \          a = find(a, t);\n            return -std::prev(std::lower_bound(num[a].begin(),\
    \ num[a].end(), std::make_pair(t, 0)))->second;\n        }\n    private:\n   \
    \     int _n; // \u5168\u9802\u70B9\u6570\n        std::vector<int> parent_or_size;\
    \ // \u975E\u8CA0\u306E\u5834\u5408\u306F\u89AA, \u8CA0\u306E\u5834\u5408\u306F\
    -size\n        std::vector<int> time; //time[x]:x\u304C\u6839\u3067\u306F\u306A\
    \u304F\u306A\u3063\u305F\u77AC\u9593\u306E\u6642\u523B\n        std::vector<std::vector<std::pair<int,\
    \ int>>> num; // (\u6642\u523B, \u9802\u70B9\u6570)\u3092\u8981\u7D20\u306B\u6301\
    \u3064vector\n    };\n}\n"
  code: "#include<vector>\n#include<cassert>\n\n\nnamespace tomo0608 {\n    struct\
    \ pp_dsu {\n    public:\n        pp_dsu() : _n(0) {}\n        pp_dsu(int n) :\
    \ _n(n), parent_or_size(n, -1), num(n), time(n, 1e9) {\n            for (int i\
    \ = 0; i < _n; ++i)num[i].emplace_back(-1, -1);\n        }\n        // \u6642\u523B\
    t\u306B\u304A\u3051\u308Bx\u306E\u89AA\u3092\u8FD4\u3059\n        int find(int\
    \ a, int t) {\n            assert(0 <= a && a < _n);\n            assert(0 <=\
    \ t && t < 1e9);\n            if (time[a] == -1 || t < time[a])return a;\n   \
    \         return find(parent_or_size[a], t);\n        }\n\n        bool same(int\
    \ a, int b, int t) {\n            assert(0 <= a && a < _n && 0 <= b && b < _n);\n\
    \            return find(a, t) == find(b, t);\n        }\n\n        bool merge(int\
    \ a, int b, int t) {\n            assert(0 <= a && a < _n && 0 <= b && b < _n);\n\
    \            assert(0 <= t && t < 1e9);\n            int x = find(a, t), y = find(b,\
    \ t);\n            if (x == y)return true;\n            if (-parent_or_size[x]\
    \ < -parent_or_size[y])std::swap(x, y);\n            parent_or_size[x] += parent_or_size[y];\n\
    \            parent_or_size[y] = x;\n            time[y] = t;\n            num[x].emplace_back(t,\
    \ parent_or_size[x]);\n            return false;\n        }\n\n        int size(int\
    \ a, int t) {\n            a = find(a, t);\n            return -std::prev(std::lower_bound(num[a].begin(),\
    \ num[a].end(), std::make_pair(t, 0)))->second;\n        }\n    private:\n   \
    \     int _n; // \u5168\u9802\u70B9\u6570\n        std::vector<int> parent_or_size;\
    \ // \u975E\u8CA0\u306E\u5834\u5408\u306F\u89AA, \u8CA0\u306E\u5834\u5408\u306F\
    -size\n        std::vector<int> time; //time[x]:x\u304C\u6839\u3067\u306F\u306A\
    \u304F\u306A\u3063\u305F\u77AC\u9593\u306E\u6642\u523B\n        std::vector<std::vector<std::pair<int,\
    \ int>>> num; // (\u6642\u523B, \u9802\u70B9\u6570)\u3092\u8981\u7D20\u306B\u6301\
    \u3064vector\n    };\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/Partial_Persistent_DSU.hpp
  requiredBy: []
  timestamp: '2023-04-14 17:06:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Partial_Persistent_DSU.hpp
layout: document
redirect_from:
- /library/lib/Partial_Persistent_DSU.hpp
- /library/lib/Partial_Persistent_DSU.hpp.html
title: lib/Partial_Persistent_DSU.hpp
---
