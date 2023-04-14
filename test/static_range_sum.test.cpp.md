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
  bundledCode: "#line 1 \"test/static_range_sum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n\n#include<vector>\n#include<cassert>\n\nnamespace tomo0608 {\n\n    template\
    \ <class S, S(*op)(S, S), S(*e)(), S(*inv)(S)>\n    struct static_range_sum {\n\
    \        int n;\n        std::vector<S> range_sum;\n\n        static_range_sum(std::vector<S>&\
    \ a) {\n            n = (int)a.size();\n            range_sum.resize(n + 1);\n\
    \            range_sum[0] = e();\n            for (int i = 0; i < n; i++) {\n\
    \                range_sum[i + 1] = op(range_sum[i], a[i]);\n            }\n \
    \       }\n\n        inline S query(int l, int r) const {\n            assert(0\
    \ <= l && l < r && r <= n);\n            return op(inv(range_sum[l]), range_sum[r]);\n\
    \        }\n    };\n}\nusing S = long long;\n\nS op(S x, S y) { return x + y;\
    \ }\n\nS e() { return 0LL; }\n\nS inv(S x) { return -x; }\n\n#include<iostream>\n\
    \nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<long long>\
    \ a(n);\n    for (int i = 0; i < n; i++)std::cin >> a[i];\n    tomo0608::static_range_sum<S,\
    \ op, e, inv> srs(a);\n    for (int i = 0; i < q; i++) {\n        int l, r;\n\
    \        std::cin >> l >> r;\n        std::cout << srs.query(l, r) << std::endl;\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include<vector>\n#include<cassert>\n\nnamespace tomo0608 {\n\n    template <class\
    \ S, S(*op)(S, S), S(*e)(), S(*inv)(S)>\n    struct static_range_sum {\n     \
    \   int n;\n        std::vector<S> range_sum;\n\n        static_range_sum(std::vector<S>&\
    \ a) {\n            n = (int)a.size();\n            range_sum.resize(n + 1);\n\
    \            range_sum[0] = e();\n            for (int i = 0; i < n; i++) {\n\
    \                range_sum[i + 1] = op(range_sum[i], a[i]);\n            }\n \
    \       }\n\n        inline S query(int l, int r) const {\n            assert(0\
    \ <= l && l < r && r <= n);\n            return op(inv(range_sum[l]), range_sum[r]);\n\
    \        }\n    };\n}\nusing S = long long;\n\nS op(S x, S y) { return x + y;\
    \ }\n\nS e() { return 0LL; }\n\nS inv(S x) { return -x; }\n\n#include<iostream>\n\
    \nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<long long>\
    \ a(n);\n    for (int i = 0; i < n; i++)std::cin >> a[i];\n    tomo0608::static_range_sum<S,\
    \ op, e, inv> srs(a);\n    for (int i = 0; i < q; i++) {\n        int l, r;\n\
    \        std::cin >> l >> r;\n        std::cout << srs.query(l, r) << std::endl;\n\
    \    }\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-04-14 17:06:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/static_range_sum.test.cpp
- /verify/test/static_range_sum.test.cpp.html
title: test/static_range_sum.test.cpp
---
