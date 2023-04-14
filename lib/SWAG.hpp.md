---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/SWAG.test.cpp
    title: test/SWAG.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/SWAG.hpp\"\n#include<vector>\n#include<stack>\n#include<cassert>\n\
    \nnamespace tomo0608 {\n    template<class Monoid, Monoid(*op)(Monoid, Monoid),\
    \ Monoid(*e)()> struct SWAG {\n        SWAG():l(0), r(0), last_i(0), last_j(0),\
    \ front(e()), v(0), back() {}\n        explicit SWAG(std::vector<Monoid>& _v):l(0),\
    \ r(0), last_i(0), last_j(0), front(e()), v(_v.size()), back() {\n           \
    \ std::copy(_v.begin(), _v.end(), v.begin());\n        }\n        void push_back(const\
    \ Monoid& c) {\n            v.push_back(c);\n        }\n        int size() {\n\
    \            return v.size();\n        }\n        Monoid fold(int i, int j) {\
    \ //[l, r)\n            assert(i < j && j <= v.size());\n            assert(last_i\
    \ <= i && last_j <= j);\n            last_i = i, last_j = j;\n            while\
    \ (r < j)front = op(front, v[r++]);\n            while (l < i) {\n           \
    \     if (back.empty()) {\n                    Monoid tmp = e();\n           \
    \         for (int u = r; u-- > l; ) {\n                        tmp = op(v[u],\
    \ tmp);\n                        back.emplace(tmp);\n                    }\n \
    \                   front = e();\n                }\n                back.pop();\n\
    \                ++l;\n            }\n            if (back.empty())return front;\n\
    \            return op(back.top(), front);\n        }\n    private:\n        std::vector<Monoid>\
    \ v;\n        Monoid front;\n        std::stack<Monoid> back;\n        int l,\
    \ r, last_i, last_j;\n    };\n}// namespace tomo0608\n"
  code: "#include<vector>\n#include<stack>\n#include<cassert>\n\nnamespace tomo0608\
    \ {\n    template<class Monoid, Monoid(*op)(Monoid, Monoid), Monoid(*e)()> struct\
    \ SWAG {\n        SWAG():l(0), r(0), last_i(0), last_j(0), front(e()), v(0), back()\
    \ {}\n        explicit SWAG(std::vector<Monoid>& _v):l(0), r(0), last_i(0), last_j(0),\
    \ front(e()), v(_v.size()), back() {\n            std::copy(_v.begin(), _v.end(),\
    \ v.begin());\n        }\n        void push_back(const Monoid& c) {\n        \
    \    v.push_back(c);\n        }\n        int size() {\n            return v.size();\n\
    \        }\n        Monoid fold(int i, int j) { //[l, r)\n            assert(i\
    \ < j && j <= v.size());\n            assert(last_i <= i && last_j <= j);\n  \
    \          last_i = i, last_j = j;\n            while (r < j)front = op(front,\
    \ v[r++]);\n            while (l < i) {\n                if (back.empty()) {\n\
    \                    Monoid tmp = e();\n                    for (int u = r; u--\
    \ > l; ) {\n                        tmp = op(v[u], tmp);\n                   \
    \     back.emplace(tmp);\n                    }\n                    front = e();\n\
    \                }\n                back.pop();\n                ++l;\n      \
    \      }\n            if (back.empty())return front;\n            return op(back.top(),\
    \ front);\n        }\n    private:\n        std::vector<Monoid> v;\n        Monoid\
    \ front;\n        std::stack<Monoid> back;\n        int l, r, last_i, last_j;\n\
    \    };\n}// namespace tomo0608"
  dependsOn: []
  isVerificationFile: false
  path: lib/SWAG.hpp
  requiredBy: []
  timestamp: '2023-04-14 17:06:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/SWAG.test.cpp
documentation_of: lib/SWAG.hpp
layout: document
redirect_from:
- /library/lib/SWAG.hpp
- /library/lib/SWAG.hpp.html
title: lib/SWAG.hpp
---
