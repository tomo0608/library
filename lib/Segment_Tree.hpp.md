---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Segment_Tree.test.cpp
    title: test/Segment_Tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/Segment_Tree.hpp\"\n#include<vector>\n#include<assert.h>\n\
    \nnamespace tomo0608 {\n    template<class S, S(*op)(S, S), S(*e)()> struct segment_tree\
    \ {\n        int _n, size, log;\n        std::vector<S> d;\n        void update(int\
    \ k) { d[k] = op(d[k * 2], d[k * 2 + 1]); }\n        segment_tree(): segment_tree(0)\
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
    \       }\n    };\n} // namespace tomo0608\n"
  code: "#include<vector>\n#include<assert.h>\n\nnamespace tomo0608 {\n    template<class\
    \ S, S(*op)(S, S), S(*e)()> struct segment_tree {\n        int _n, size, log;\n\
    \        std::vector<S> d;\n        void update(int k) { d[k] = op(d[k * 2], d[k\
    \ * 2 + 1]); }\n        segment_tree(): segment_tree(0) {}\n        explicit segment_tree(int\
    \ n): segment_tree(std::vector<S>(n, e())) {}\n        explicit segment_tree(std::vector<S>\
    \ a): _n((int)a.size()) {\n            log = 0;\n            while ((1U << log)\
    \ < (unsigned int)(_n)) log++;\n            size = 1 << log;\n            d =\
    \ std::vector<S>(size * 2, e());\n            for (int i = 0; i < _n; i++)d[size\
    \ + i] = a[i];\n            for (int i = size - 1; i >= 1; i--)update(i);\n  \
    \      }\n\n        void update(int p, const S& x) {\n            assert(0 <=\
    \ p && p < _n);\n            p += size;\n            d[p] = x;\n            for\
    \ (int i = 1; i <= log; i++)update(p >> i);\n        }\n\n        S get(int p)\
    \ const {\n            assert(0 <= p && p < _n);\n            return d[p + size];\n\
    \        }\n\n        S prod(int l, int r) const {\n            assert(0 <= l\
    \ && l <= r && r <= _n);\n            S sml = e(), smr = e();\n            l +=\
    \ size;\n            r += size;\n\n            while (l < r) {\n             \
    \   if (l & 1) sml = op(sml, d[l++]);\n                if (r & 1) smr = op(d[--r],\
    \ smr);\n                l >>= 1;\n                r >>= 1;\n            }\n \
    \           return op(sml, smr);\n        }\n    };\n} // namespace tomo0608"
  dependsOn: []
  isVerificationFile: false
  path: lib/Segment_Tree.hpp
  requiredBy: []
  timestamp: '2023-04-14 17:06:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Segment_Tree.test.cpp
documentation_of: lib/Segment_Tree.hpp
layout: document
redirect_from:
- /library/lib/Segment_Tree.hpp
- /library/lib/Segment_Tree.hpp.html
title: lib/Segment_Tree.hpp
---
