---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/utility.hpp\"\n#include<vector>\n#include<queue>\n\n\
    namespace tomo0608 {\n#define all(x) x.begin(),x.end()\n    template <class T\
    \ = long long, class S> T SUM(const S& v) { return accumulate(all(v), T(0)); }\n\
    #define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n#define\
    \ lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define ub(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end())\n    template <typename T> void zip(std::vector<T>& x) { std::vector<T>\
    \ y = x;UNIQUE(y);for (int i = 0; i < x.size(); ++i) { x[i] = lb(y, x[i]); } }\n\
    \    template<class T> using priority_queue_rev = std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>>;\n    template<class T, class U> inline bool chmax(T& a, const\
    \ U& b) { if (a < b) { a = b; return 1; } return 0; }\n    template<class T, class\
    \ U> inline bool chmin(T& a, const U& b) { if (a > b) { a = b; return 1; } return\
    \ 0; }\n    template<class T> inline int count_between(std::vector<T>& a, T l,\
    \ T r) { return lower_bound(all(a), r) - lower_bound(all(a), l); } // [l, r)\n\
    #define bit(n, k) ((n >> k) & 1) /*n\u306Ek bit\u76EE*/\n    int topbit(signed\
    \ t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }\n    int topbit(long long\
    \ t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\n    int lowbit(signed\
    \ a) { return a == 0 ? 32 : __builtin_ctz(a); }\n    int lowbit(long long a) {\
    \ return a == 0 ? 64 : __builtin_ctzll(a); }\n    template <typename T>T mypow(T\
    \ x, long long n) { T ret = 1;while (n > 0) { if (n & 1)(ret *= x);(x *= x);n\
    \ >>= 1; }return ret; }\n}\n"
  code: "#include<vector>\n#include<queue>\n\nnamespace tomo0608 {\n#define all(x)\
    \ x.begin(),x.end()\n    template <class T = long long, class S> T SUM(const S&\
    \ v) { return accumulate(all(v), T(0)); }\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define lb(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n    template <typename\
    \ T> void zip(std::vector<T>& x) { std::vector<T> y = x;UNIQUE(y);for (int i =\
    \ 0; i < x.size(); ++i) { x[i] = lb(y, x[i]); } }\n    template<class T> using\
    \ priority_queue_rev = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\
    \    template<class T, class U> inline bool chmax(T& a, const U& b) { if (a <\
    \ b) { a = b; return 1; } return 0; }\n    template<class T, class U> inline bool\
    \ chmin(T& a, const U& b) { if (a > b) { a = b; return 1; } return 0; }\n    template<class\
    \ T> inline int count_between(std::vector<T>& a, T l, T r) { return lower_bound(all(a),\
    \ r) - lower_bound(all(a), l); } // [l, r)\n#define bit(n, k) ((n >> k) & 1) /*n\u306E\
    k bit\u76EE*/\n    int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t);\
    \ }\n    int topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t);\
    \ }\n    int lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }\n   \
    \ int lowbit(long long a) { return a == 0 ? 64 : __builtin_ctzll(a); }\n    template\
    \ <typename T>T mypow(T x, long long n) { T ret = 1;while (n > 0) { if (n & 1)(ret\
    \ *= x);(x *= x);n >>= 1; }return ret; }\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/utility.hpp
  requiredBy: []
  timestamp: '2023-04-14 17:06:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/utility.hpp
layout: document
redirect_from:
- /library/lib/utility.hpp
- /library/lib/utility.hpp.html
title: lib/utility.hpp
---
