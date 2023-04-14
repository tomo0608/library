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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#include<bits/stdc++.h>\n\nnamespace tomo0608 {\n\n    struct unionfind {\n\
    \    public:\n        unionfind(): _n(0) {}\n        unionfind(int n): _n(n),\
    \ parent_or_size(n, -1) {}\n\n        int find(int a) {\n            assert(0\
    \ <= a && a < _n);\n            if (parent_or_size[a] < 0)return a;\n        \
    \    return parent_or_size[a] = find(parent_or_size[a]);\n        }\n\n      \
    \  bool same(int a, int b) {\n            assert(0 <= a && a < _n && 0 <= b &&\
    \ b < _n);\n            return find(a) == find(b);\n        }\n\n        bool\
    \ merge(int a, int b) {\n            assert(0 <= a && a < _n && 0 <= b && b <\
    \ _n);\n            int x = find(a), y = find(b);\n            if (x == y)return\
    \ true;\n            if (-parent_or_size[x] < -parent_or_size[y])std::swap(x,\
    \ y);\n            parent_or_size[x] += parent_or_size[y];\n            parent_or_size[y]\
    \ = x;\n            return false;\n        }\n\n    private:\n        int _n;\n\
    \        std::vector<int> parent_or_size;\n    };\n} // namespace tomo0608\n\n\
    using namespace std;\nint main() {\n    int n, q;cin >> n >> q;\n    tomo0608::unionfind\
    \ uf(n);\n    while (q--) {\n        int t, u, v;cin >> t >> u >> v;\n       \
    \ if (t)cout << uf.same(u, v) << endl;\n        else uf.merge(u, v);\n    }\n\
    \    return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include<bits/stdc++.h>\n\
    \nnamespace tomo0608 {\n\n    struct unionfind {\n    public:\n        unionfind():\
    \ _n(0) {}\n        unionfind(int n): _n(n), parent_or_size(n, -1) {}\n\n    \
    \    int find(int a) {\n            assert(0 <= a && a < _n);\n            if\
    \ (parent_or_size[a] < 0)return a;\n            return parent_or_size[a] = find(parent_or_size[a]);\n\
    \        }\n\n        bool same(int a, int b) {\n            assert(0 <= a &&\
    \ a < _n && 0 <= b && b < _n);\n            return find(a) == find(b);\n     \
    \   }\n\n        bool merge(int a, int b) {\n            assert(0 <= a && a <\
    \ _n && 0 <= b && b < _n);\n            int x = find(a), y = find(b);\n      \
    \      if (x == y)return true;\n            if (-parent_or_size[x] < -parent_or_size[y])std::swap(x,\
    \ y);\n            parent_or_size[x] += parent_or_size[y];\n            parent_or_size[y]\
    \ = x;\n            return false;\n        }\n\n    private:\n        int _n;\n\
    \        std::vector<int> parent_or_size;\n    };\n} // namespace tomo0608\n\n\
    using namespace std;\nint main() {\n    int n, q;cin >> n >> q;\n    tomo0608::unionfind\
    \ uf(n);\n    while (q--) {\n        int t, u, v;cin >> t >> u >> v;\n       \
    \ if (t)cout << uf.same(u, v) << endl;\n        else uf.merge(u, v);\n    }\n\
    \    return 0;\n}\n\n"
  dependsOn: []
  isVerificationFile: true
  path: test/unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-04-14 17:06:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/unionfind.test.cpp
- /verify/test/unionfind.test.cpp.html
title: test/unionfind.test.cpp
---
