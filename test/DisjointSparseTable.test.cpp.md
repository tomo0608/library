---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DisjointSparseTable.hpp
    title: lib/DisjointSparseTable.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/DisjointSparseTable.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/staticrmq\"\n\n#include<iostream>\n#line 1 \"\
    lib/DisjointSparseTable.hpp\"\n#include<vector>\n#include<cassert>\n\nnamespace\
    \ tomo0608 {\n    template<typename S, S(*op)(S, S)> struct DisjointSparseTable\
    \ {\n        std::vector<std::vector<S>> dst;\n        int n;\n\n        DisjointSparseTable(const\
    \ std::vector<S>& v) {\n            n = (int)v.size();\n            dst.emplace_back(v);\n\
    \            for (int i = 2; i < n; i <<= 1) {\n                dst.emplace_back(std::vector<S>(n));\n\
    \                for (int j = i; j < n; j += i << 1) {\n                    dst.back()[j\
    \ - 1] = dst[0][j - 1];\n                    for (int k = 2; k <= i; k++) {\n\
    \                        dst.back()[j - k] = op(dst[0][j - k], dst.back()[j -\
    \ k + 1]);\n                    }\n                    dst.back()[j] = dst[0][j];\n\
    \                    for (int k = 2; k <= i && j + k <= n; k++) {\n          \
    \              dst.back()[j + k - 1] = op(dst.back()[j + k - 2], dst[0][j + k\
    \ - 1]);\n                    }\n                }\n            }\n        }\n\
    \n        inline S query(int l, int r)const {\n            assert(0 <= l && l\
    \ <= r && r <= n);\n            r--;\n            if (l == r)return dst[0][l];\n\
    \            int k = 31 - __builtin_clz(l ^ r);\n            return op(dst[k][l],\
    \ dst[k][r]);\n        }\n    };\n} // namespace tomo0608\n#line 5 \"test/DisjointSparseTable.test.cpp\"\
    \n\nint op(int x, int y) { return std::min(x, y); }\nusing namespace std;\nint\
    \ main() {\n    int n, q;cin >> n >> q;\n    vector<int> v(n);\n    for (int i\
    \ = 0; i < n; i++)cin >> v[i];\n    tomo0608::DisjointSparseTable<int, op> dat(v);\n\
    \    while (q--) {\n        int l, r;cin >> l >> r;\n        cout << dat.query(l,\
    \ r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include<iostream>\n\
    #include \"../lib/DisjointSparseTable.hpp\"\n\nint op(int x, int y) { return std::min(x,\
    \ y); }\nusing namespace std;\nint main() {\n    int n, q;cin >> n >> q;\n   \
    \ vector<int> v(n);\n    for (int i = 0; i < n; i++)cin >> v[i];\n    tomo0608::DisjointSparseTable<int,\
    \ op> dat(v);\n    while (q--) {\n        int l, r;cin >> l >> r;\n        cout\
    \ << dat.query(l, r) << endl;\n    }\n}"
  dependsOn:
  - lib/DisjointSparseTable.hpp
  isVerificationFile: true
  path: test/DisjointSparseTable.test.cpp
  requiredBy: []
  timestamp: '2023-04-14 17:06:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DisjointSparseTable.test.cpp
layout: document
redirect_from:
- /verify/test/DisjointSparseTable.test.cpp
- /verify/test/DisjointSparseTable.test.cpp.html
title: test/DisjointSparseTable.test.cpp
---
