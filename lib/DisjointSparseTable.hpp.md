---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DisjointSparseTable.test.cpp
    title: test/DisjointSparseTable.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/DisjointSparseTable.hpp\"\n#include<vector>\n#include<cassert>\n\
    \nnamespace tomo0608 {\n    template<typename S, S(*op)(S, S)> struct DisjointSparseTable\
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
    \ dst[k][r]);\n        }\n    };\n} // namespace tomo0608\n"
  code: "#include<vector>\n#include<cassert>\n\nnamespace tomo0608 {\n    template<typename\
    \ S, S(*op)(S, S)> struct DisjointSparseTable {\n        std::vector<std::vector<S>>\
    \ dst;\n        int n;\n\n        DisjointSparseTable(const std::vector<S>& v)\
    \ {\n            n = (int)v.size();\n            dst.emplace_back(v);\n      \
    \      for (int i = 2; i < n; i <<= 1) {\n                dst.emplace_back(std::vector<S>(n));\n\
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
    \ dst[k][r]);\n        }\n    };\n} // namespace tomo0608"
  dependsOn: []
  isVerificationFile: false
  path: lib/DisjointSparseTable.hpp
  requiredBy: []
  timestamp: '2023-04-14 17:06:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DisjointSparseTable.test.cpp
documentation_of: lib/DisjointSparseTable.hpp
layout: document
redirect_from:
- /library/lib/DisjointSparseTable.hpp
- /library/lib/DisjointSparseTable.hpp.html
title: lib/DisjointSparseTable.hpp
---
