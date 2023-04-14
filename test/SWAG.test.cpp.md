---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/SWAG.hpp
    title: lib/SWAG.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/SWAG.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#line 1 \"lib/SWAG.hpp\"\n#include<vector>\n#include<stack>\n#include<cassert>\n\
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
    \ r, last_i, last_j;\n    };\n}// namespace tomo0608\n#line 4 \"test/SWAG.test.cpp\"\
    \n\n#include<iostream>\nusing namespace std;\n#define ll long long\nconst ll MOD\
    \ = 998244353;\n#define S pair<ll,ll>\nS op(S x, S y) {\n    S z;\n    z.first\
    \ = x.first * y.first % MOD;\n    z.second = (y.first * x.second + y.second) %\
    \ MOD;\n    return z;\n}\nS e() { return { 1, 0 }; }\nint main() {\n    int q;cin\
    \ >> q;\n    int l = 0, r = 0;\n    tomo0608::SWAG<S, op, e> swag;\n    while\
    \ (q--) {\n        int i;cin >> i;\n        if (i == 0) {\n            ll a, b;cin\
    \ >> a >> b;\n            swag.push_back(S(a, b));\n            r++;\n       \
    \ }\n        if (i == 1) {\n            l++;\n        }\n        if (i == 2) {\n\
    \            ll x;cin >> x;\n            if (l == r) {\n                cout <<\
    \ x << endl;\n                continue;\n            }\n            auto [a, b]\
    \ = swag.fold(l, r);\n            ll fx = (a * x + b) % MOD;\n            cout\
    \ << fx << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include \"../lib/SWAG.hpp\"\n\n#include<iostream>\nusing namespace std;\n\
    #define ll long long\nconst ll MOD = 998244353;\n#define S pair<ll,ll>\nS op(S\
    \ x, S y) {\n    S z;\n    z.first = x.first * y.first % MOD;\n    z.second =\
    \ (y.first * x.second + y.second) % MOD;\n    return z;\n}\nS e() { return { 1,\
    \ 0 }; }\nint main() {\n    int q;cin >> q;\n    int l = 0, r = 0;\n    tomo0608::SWAG<S,\
    \ op, e> swag;\n    while (q--) {\n        int i;cin >> i;\n        if (i == 0)\
    \ {\n            ll a, b;cin >> a >> b;\n            swag.push_back(S(a, b));\n\
    \            r++;\n        }\n        if (i == 1) {\n            l++;\n      \
    \  }\n        if (i == 2) {\n            ll x;cin >> x;\n            if (l ==\
    \ r) {\n                cout << x << endl;\n                continue;\n      \
    \      }\n            auto [a, b] = swag.fold(l, r);\n            ll fx = (a *\
    \ x + b) % MOD;\n            cout << fx << endl;\n        }\n    }\n}"
  dependsOn:
  - lib/SWAG.hpp
  isVerificationFile: true
  path: test/SWAG.test.cpp
  requiredBy: []
  timestamp: '2023-04-14 17:06:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/SWAG.test.cpp
layout: document
redirect_from:
- /verify/test/SWAG.test.cpp
- /verify/test/SWAG.test.cpp.html
title: test/SWAG.test.cpp
---
