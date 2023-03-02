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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068
  bundledCode: "#line 1 \"2D_Segment_Tree.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068\"\
    \n#include<bits/stdc++.h>\n\nnamespace tomo0608 {\n    template<class S, S(*op)(S,\
    \ S), S(*e)()> struct segment_tree_2d {\n        int _H, _W, size_H, size_W, size,\
    \ log_H, log_W;\n        std::vector<S> d;\n        int id(int h, int w) const\
    \ { return h * 2 * size_W + w; }\n        segment_tree_2d(): segment_tree_2d(0)\
    \ {}\n        explicit segment_tree_2d(int h, int w): segment_tree_2d(std::vector<std::vector<S>>(h,\
    \ std::vector<S>(w, e()))) {}\n        explicit segment_tree_2d(std::vector<std::vector<S>>\
    \ a): _H((int)a.size()), _W((int)a[0].size()) {\n            log_H = 0;\n    \
    \        while ((1U << log_H) < (unsigned int)(_H)) log_H++;\n            log_W\
    \ = 0;\n            while ((1U << log_W) < (unsigned int)(_W)) log_W++;\n    \
    \        size_H = 1 << log_H;\n            size_W = 1 << log_W;\n            d\
    \ = std::vector<S>(size_H * size_W * 4, e());\n            for (int h = 0; h <\
    \ _H; h++)for (int w = 0; w < _W; w++)d[id(size_H + h, size_W + w)] = a[h][w];\n\
    \            for (int w = size_W; w < 2 * size_W; w++)for (int h = size_H - 1;\
    \ h >= 1; h--)d[id(h, w)] = op(d[id(2 * h, w)], d[id(2 * h + 1, w)]);\n      \
    \      for (int h = 0; h < 2 * size_H; h++)for (int w = size_W - 1; w >= 1; w--)d[id(h,\
    \ w)] = op(d[id(h, 2 * w)], d[id(h, 2 * w + 1)]);\n        }\n\n        void update(int\
    \ h, int w, const S& x) {\n            assert(0 <= h && h < _H && 0 <= w && w\
    \ < _W);\n            h += size_H;\n            w += size_W;\n            d[id(h,\
    \ w)] = x;\n            for (int i = h >> 1; i; i >>= 1) {\n                d[id(i,\
    \ w)] = op(d[id(2 * i + 0, w)], d[id(2 * i + 1, w)]);\n            }\n       \
    \     for (; h; h >>= 1) {\n                for (int j = w >> 1; j; j >>= 1) {\n\
    \                    d[id(h, j)] = op(d[id(h, 2 * j + 0)], d[id(h, 2 * j + 1)]);\n\
    \                }\n            }\n        }\n\n        S get(int h, int w)const\
    \ {\n            assert(0 <= h && h < _H && 0 <= w && w < _W);\n            return\
    \ d[id(h + size_H, w + size_W)];\n        }\n\n        S inner_prod(int h, int\
    \ w_l, int w_r) const {\n            S sml = e(), smr = e();\n\n            while\
    \ (w_l < w_r) {\n                if (w_l & 1)sml = op(sml, d[id(h, w_l++)]);\n\
    \                if (w_r & 1)smr = op(d[id(h, --w_r)], smr);\n               \
    \ w_l >>= 1;\n                w_r >>= 1;\n            }\n            return op(sml,\
    \ smr);\n        }\n\n        S prod(int h_l, int h_r, int w_l, int w_r) const\
    \ {\n            assert(0 <= h_l && h_l <= h_r && h_r <= _H);\n            assert(0\
    \ <= w_l && w_l <= w_r && w_r <= _W);\n            S sml = e(), smr = e();\n \
    \           h_l += size_H;\n            h_r += size_H;\n            w_l += size_W;\n\
    \            w_r += size_W;\n\n            while (h_l < h_r) {\n             \
    \   if (h_l & 1) sml = op(sml, inner_prod(h_l++, w_l, w_r));\n               \
    \ if (h_r & 1) smr = op(inner_prod(--h_r, w_l, w_r), smr);\n                h_l\
    \ >>= 1;\n                h_r >>= 1;\n            }\n            return op(sml,\
    \ smr);\n        }\n    };\n} // namespace tomo0608\n\nusing namespace std;\n\n\
    \n\nusing S = int;\nS op(S x, S y) { return min(x, y); }\nS e() { return int((1LL\
    \ << 31) - 1); }\n\nvoid solve() {\n    S r, c, q;cin >> r >> c >> q;\n    if\
    \ (r == 0)exit(0);\n    //vector a(r, vector<S>(c));\n    //for (int i = 0; i\
    \ < r; i++)for (int j = 0;j < c;j++)cin >> a[i][j];\n    tomo0608::segment_tree_2d<S,\
    \ op, e> seg(r, c);\n    for (int i = 0; i < r; i++)for (int j = 0;j < c;j++)\
    \ {\n        int x;cin >> x;\n        seg.update(i, j, x);\n    }\n    while (q--)\
    \ {\n        S r1, c1, r2, c2;cin >> r1 >> c1 >> r2 >> c2;\n        cout << seg.prod(r1,\
    \ r2 + 1, c1, c2 + 1) << '\\n';\n    }\n}\nint main() {\n    while (1)solve();\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068\"\
    \n#include<bits/stdc++.h>\n\nnamespace tomo0608 {\n    template<class S, S(*op)(S,\
    \ S), S(*e)()> struct segment_tree_2d {\n        int _H, _W, size_H, size_W, size,\
    \ log_H, log_W;\n        std::vector<S> d;\n        int id(int h, int w) const\
    \ { return h * 2 * size_W + w; }\n        segment_tree_2d(): segment_tree_2d(0)\
    \ {}\n        explicit segment_tree_2d(int h, int w): segment_tree_2d(std::vector<std::vector<S>>(h,\
    \ std::vector<S>(w, e()))) {}\n        explicit segment_tree_2d(std::vector<std::vector<S>>\
    \ a): _H((int)a.size()), _W((int)a[0].size()) {\n            log_H = 0;\n    \
    \        while ((1U << log_H) < (unsigned int)(_H)) log_H++;\n            log_W\
    \ = 0;\n            while ((1U << log_W) < (unsigned int)(_W)) log_W++;\n    \
    \        size_H = 1 << log_H;\n            size_W = 1 << log_W;\n            d\
    \ = std::vector<S>(size_H * size_W * 4, e());\n            for (int h = 0; h <\
    \ _H; h++)for (int w = 0; w < _W; w++)d[id(size_H + h, size_W + w)] = a[h][w];\n\
    \            for (int w = size_W; w < 2 * size_W; w++)for (int h = size_H - 1;\
    \ h >= 1; h--)d[id(h, w)] = op(d[id(2 * h, w)], d[id(2 * h + 1, w)]);\n      \
    \      for (int h = 0; h < 2 * size_H; h++)for (int w = size_W - 1; w >= 1; w--)d[id(h,\
    \ w)] = op(d[id(h, 2 * w)], d[id(h, 2 * w + 1)]);\n        }\n\n        void update(int\
    \ h, int w, const S& x) {\n            assert(0 <= h && h < _H && 0 <= w && w\
    \ < _W);\n            h += size_H;\n            w += size_W;\n            d[id(h,\
    \ w)] = x;\n            for (int i = h >> 1; i; i >>= 1) {\n                d[id(i,\
    \ w)] = op(d[id(2 * i + 0, w)], d[id(2 * i + 1, w)]);\n            }\n       \
    \     for (; h; h >>= 1) {\n                for (int j = w >> 1; j; j >>= 1) {\n\
    \                    d[id(h, j)] = op(d[id(h, 2 * j + 0)], d[id(h, 2 * j + 1)]);\n\
    \                }\n            }\n        }\n\n        S get(int h, int w)const\
    \ {\n            assert(0 <= h && h < _H && 0 <= w && w < _W);\n            return\
    \ d[id(h + size_H, w + size_W)];\n        }\n\n        S inner_prod(int h, int\
    \ w_l, int w_r) const {\n            S sml = e(), smr = e();\n\n            while\
    \ (w_l < w_r) {\n                if (w_l & 1)sml = op(sml, d[id(h, w_l++)]);\n\
    \                if (w_r & 1)smr = op(d[id(h, --w_r)], smr);\n               \
    \ w_l >>= 1;\n                w_r >>= 1;\n            }\n            return op(sml,\
    \ smr);\n        }\n\n        S prod(int h_l, int h_r, int w_l, int w_r) const\
    \ {\n            assert(0 <= h_l && h_l <= h_r && h_r <= _H);\n            assert(0\
    \ <= w_l && w_l <= w_r && w_r <= _W);\n            S sml = e(), smr = e();\n \
    \           h_l += size_H;\n            h_r += size_H;\n            w_l += size_W;\n\
    \            w_r += size_W;\n\n            while (h_l < h_r) {\n             \
    \   if (h_l & 1) sml = op(sml, inner_prod(h_l++, w_l, w_r));\n               \
    \ if (h_r & 1) smr = op(inner_prod(--h_r, w_l, w_r), smr);\n                h_l\
    \ >>= 1;\n                h_r >>= 1;\n            }\n            return op(sml,\
    \ smr);\n        }\n    };\n} // namespace tomo0608\n\nusing namespace std;\n\n\
    \n\nusing S = int;\nS op(S x, S y) { return min(x, y); }\nS e() { return int((1LL\
    \ << 31) - 1); }\n\nvoid solve() {\n    S r, c, q;cin >> r >> c >> q;\n    if\
    \ (r == 0)exit(0);\n    //vector a(r, vector<S>(c));\n    //for (int i = 0; i\
    \ < r; i++)for (int j = 0;j < c;j++)cin >> a[i][j];\n    tomo0608::segment_tree_2d<S,\
    \ op, e> seg(r, c);\n    for (int i = 0; i < r; i++)for (int j = 0;j < c;j++)\
    \ {\n        int x;cin >> x;\n        seg.update(i, j, x);\n    }\n    while (q--)\
    \ {\n        S r1, c1, r2, c2;cin >> r1 >> c1 >> r2 >> c2;\n        cout << seg.prod(r1,\
    \ r2 + 1, c1, c2 + 1) << '\\n';\n    }\n}\nint main() {\n    while (1)solve();\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: 2D_Segment_Tree.test.cpp
  requiredBy: []
  timestamp: '2023-03-02 17:38:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: 2D_Segment_Tree.test.cpp
layout: document
redirect_from:
- /verify/2D_Segment_Tree.test.cpp
- /verify/2D_Segment_Tree.test.cpp.html
title: 2D_Segment_Tree.test.cpp
---
