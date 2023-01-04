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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"static_range_sum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n\n#include <vector>\n#include<cassert>\n\ntemplate <class S, S(*op)(S, S), S(*e)(),\
    \ S(*inv)(S)>\nclass static_range_sum {\npublic:\n    static_range_sum(): _n(0)\
    \ {}\n    static_range_sum(std::vector<S>& a): _n(a.size()) {\n        range_sum.resize(_n\
    \ + 1);\n        range_sum[0] = e();\n        for (int i = 0; i < _n; i++) {\n\
    \            range_sum[i + 1] = op(range_sum[i], a[i]);\n        }\n    }\n\n\
    \    S query(int l, int r) {\n        assert(0 <= l && l < r&& r <= _n);\n   \
    \     return op(inv(range_sum[l]), range_sum[r]);\n    }\n\nprivate:\n    unsigned\
    \ _n;\n    std::vector<S> range_sum;\n};\n\nusing S = long long;\n\nS op(S x,\
    \ S y) { return x + y; }\n\nS e() { return 0LL; }\n\nS inv(S x) { return -x; }\n\
    \n#include<iostream>\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\
    \    std::vector<long long> a(n);\n    for (int i = 0; i < n; i++)std::cin >>\
    \ a[i];\n    static_range_sum<S, op, e, inv> srs(a);\n    for (int i = 0; i <\
    \ q; i++) {\n        int l, r;\n        std::cin >> l >> r;\n        std::cout\
    \ << srs.query(l, r) << std::endl;\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <vector>\n#include<cassert>\n\ntemplate <class S, S(*op)(S, S), S(*e)(),\
    \ S(*inv)(S)>\nclass static_range_sum {\npublic:\n    static_range_sum(): _n(0)\
    \ {}\n    static_range_sum(std::vector<S>& a): _n(a.size()) {\n        range_sum.resize(_n\
    \ + 1);\n        range_sum[0] = e();\n        for (int i = 0; i < _n; i++) {\n\
    \            range_sum[i + 1] = op(range_sum[i], a[i]);\n        }\n    }\n\n\
    \    S query(int l, int r) {\n        assert(0 <= l && l < r&& r <= _n);\n   \
    \     return op(inv(range_sum[l]), range_sum[r]);\n    }\n\nprivate:\n    unsigned\
    \ _n;\n    std::vector<S> range_sum;\n};\n\nusing S = long long;\n\nS op(S x,\
    \ S y) { return x + y; }\n\nS e() { return 0LL; }\n\nS inv(S x) { return -x; }\n\
    \n#include<iostream>\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\
    \    std::vector<long long> a(n);\n    for (int i = 0; i < n; i++)std::cin >>\
    \ a[i];\n    static_range_sum<S, op, e, inv> srs(a);\n    for (int i = 0; i <\
    \ q; i++) {\n        int l, r;\n        std::cin >> l >> r;\n        std::cout\
    \ << srs.query(l, r) << std::endl;\n    }\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-01-04 15:56:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/static_range_sum.test.cpp
- /verify/static_range_sum.test.cpp.html
title: static_range_sum.test.cpp
---
