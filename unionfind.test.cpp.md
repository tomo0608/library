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
    - https://old.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#include<bits/stdc++.h>\n\nstruct unionfind{\n    public:\n        unionfind():\
    \ _n(0){}\n        unionfind(int n):  _n(n),parent_or_size(n, -1){}\n\n      \
    \  int find(int a){\n            assert(0 <= a && a < _n);\n            if(parent_or_size[a]\
    \ < 0)return a;\n            return parent_or_size[a] = find(parent_or_size[a]);\n\
    \        }\n\n        bool same(int a, int b){\n            assert(0 <= a && a\
    \ < _n && 0 <= b && b < _n);\n            return find(a) == find(b);\n       \
    \ }\n\n        bool merge(int a, int b){\n            assert(0 <= a && a < _n\
    \ && 0 <= b && b < _n);\n            int x = find(a), y = find(b);\n         \
    \   if(x == y)return true;\n            if(-parent_or_size[x] < -parent_or_size[y])std::swap(x,y);\n\
    \            parent_or_size[x] += parent_or_size[y];\n            parent_or_size[y]\
    \ = x;\n            return false;\n        }\n\n    private:\n        int _n;\n\
    \        std::vector<int> parent_or_size;\n};\n\n// https://old.yosupo.jp/problem/unionfind\n\
    using namespace std;\nint main(){\n    int n,q;cin >> n >> q;\n    unionfind uf(n);\n\
    \    while(q--){\n        int t,u,v;cin >> t >> u >> v;\n        if(t)cout <<\
    \ uf.same(u, v) << endl;\n        else uf.merge(u, v);\n    }\n    return 0;\n\
    }\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include<bits/stdc++.h>\n\
    \nstruct unionfind{\n    public:\n        unionfind(): _n(0){}\n        unionfind(int\
    \ n):  _n(n),parent_or_size(n, -1){}\n\n        int find(int a){\n           \
    \ assert(0 <= a && a < _n);\n            if(parent_or_size[a] < 0)return a;\n\
    \            return parent_or_size[a] = find(parent_or_size[a]);\n        }\n\n\
    \        bool same(int a, int b){\n            assert(0 <= a && a < _n && 0 <=\
    \ b && b < _n);\n            return find(a) == find(b);\n        }\n\n       \
    \ bool merge(int a, int b){\n            assert(0 <= a && a < _n && 0 <= b &&\
    \ b < _n);\n            int x = find(a), y = find(b);\n            if(x == y)return\
    \ true;\n            if(-parent_or_size[x] < -parent_or_size[y])std::swap(x,y);\n\
    \            parent_or_size[x] += parent_or_size[y];\n            parent_or_size[y]\
    \ = x;\n            return false;\n        }\n\n    private:\n        int _n;\n\
    \        std::vector<int> parent_or_size;\n};\n\n// https://old.yosupo.jp/problem/unionfind\n\
    using namespace std;\nint main(){\n    int n,q;cin >> n >> q;\n    unionfind uf(n);\n\
    \    while(q--){\n        int t,u,v;cin >> t >> u >> v;\n        if(t)cout <<\
    \ uf.same(u, v) << endl;\n        else uf.merge(u, v);\n    }\n    return 0;\n\
    }\n\n"
  dependsOn: []
  isVerificationFile: true
  path: unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-12-31 18:24:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unionfind.test.cpp
layout: document
redirect_from:
- /verify/unionfind.test.cpp
- /verify/unionfind.test.cpp.html
title: unionfind.test.cpp
---
