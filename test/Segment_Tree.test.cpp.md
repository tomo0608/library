---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Segment_Tree.hpp
    title: lib/Segment_Tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"test/Segment_Tree.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include<bits/stdc++.h>\n\n#line 3 \"lib/Segment_Tree.hpp\"\n\nnamespace tomo0608\
    \ {\n    template<class S, S(*op)(S, S), S(*e)()> struct segment_tree {\n    \
    \    int _n, size, log;\n        std::vector<S> d;\n        void update(int k)\
    \ { d[k] = op(d[k * 2], d[k * 2 + 1]); }\n        segment_tree(): segment_tree(0)\
    \ {}\n        explicit segment_tree(int n): segment_tree(std::vector<S>(n, e()))\
    \ {}\n        explicit segment_tree(std::vector<S> a): _n((int)a.size()) {\n \
    \           log = 0;\n            while ((1U << log) < (unsigned int)(_n)) log++;\n\
    \            size = 1 << log;\n            d = std::vector<S>(size * 2, e());\n\
    \            for (int i = 0; i < _n; i++)d[size + i] = a[i];\n            for\
    \ (int i = size - 1; i >= 1; i--)update(i);\n        }\n\n        void update(int\
    \ p, const S& x) {\n            assert(0 <= p && p < _n);\n            p += size;\n\
    \            d[p] = x;\n            for (int i = 1; i <= log; i++)update(p >>\
    \ i);\n        }\n\n        S get(int p) const {\n            assert(0 <= p &&\
    \ p < _n);\n            return d[p + size];\n        }\n\n        S prod(int l,\
    \ int r) const {\n            assert(0 <= l && l <= r && r <= _n);\n         \
    \   S sml = e(), smr = e();\n            l += size;\n            r += size;\n\n\
    \            while (l < r) {\n                if (l & 1) sml = op(sml, d[l++]);\n\
    \                if (r & 1) smr = op(d[--r], smr);\n                l >>= 1;\n\
    \                r >>= 1;\n            }\n            return op(sml, smr);\n \
    \       }\n    };\n} // namespace tomo0608\n#line 6 \"test/Segment_Tree.test.cpp\"\
    \nusing namespace std;\n\nusing S = int;\nS op(S x, S y) { return min(x, y); }\n\
    S e() { return INT_MAX; }\nint main() {\n    int n, q;cin >> n >> q;\n    tomo0608::segment_tree<S,\
    \ op, e> seg(n);\n    while (q--) {\n        int t, x, y;cin >> t >> x >> y;\n\
    \        if (t == 0)seg.update(x, y);\n        else cout << seg.prod(x, y + 1)\
    \ << \"\\n\";\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include<bits/stdc++.h>\n\n#include \"../lib/Segment_Tree.hpp\"\nusing namespace\
    \ std;\n\nusing S = int;\nS op(S x, S y) { return min(x, y); }\nS e() { return\
    \ INT_MAX; }\nint main() {\n    int n, q;cin >> n >> q;\n    tomo0608::segment_tree<S,\
    \ op, e> seg(n);\n    while (q--) {\n        int t, x, y;cin >> t >> x >> y;\n\
    \        if (t == 0)seg.update(x, y);\n        else cout << seg.prod(x, y + 1)\
    \ << \"\\n\";\n    }\n    return 0;\n}"
  dependsOn:
  - lib/Segment_Tree.hpp
  isVerificationFile: true
  path: test/Segment_Tree.test.cpp
  requiredBy: []
  timestamp: '2023-04-14 17:06:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Segment_Tree.test.cpp
layout: document
redirect_from:
- /verify/test/Segment_Tree.test.cpp
- /verify/test/Segment_Tree.test.cpp.html
title: test/Segment_Tree.test.cpp
---
