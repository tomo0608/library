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
  bundledCode: "#line 1 \"lib/IO.hpp\"\n#include<iostream>\n#include<set>\n#include<vector>\n\
    #include<map>\n#include <atcoder/modint>\n\nnamespace tomo0608 {\n    template<class...\
    \ T>void input(T&... a) { (std::cin >> ... >> a); };\n\n#define INT(...) int __VA_ARGS__;\
    \ input(__VA_ARGS__)\n#define LL(...) ll __VA_ARGS__; input(__VA_ARGS__)\n#define\
    \ STR(...) string __VA_ARGS__; input(__VA_ARGS__)\n#define DBL(...) double __VA_ARGS__;\
    \ input(__VA_ARGS__)\n\n    template<class T1, class T2> std::istream& operator>>(std::istream&\
    \ is, std::pair<T1, T2>& p) { is >> p.first >> p.second; return is; }\n    template<class\
    \ T1, class T2> std::ostream& operator<<(std::ostream& os, const std::pair<T1,\
    \ T2>& p) { os << '(' << p.first << \", \" << p.second << ')'; return os; }\n\
    \    template<class T> std::istream& operator>>(std::istream& is, std::vector<T>&\
    \ v) { for (auto& e : v) is >> e; return is; }\n    template<class T> std::ostream&\
    \ operator<<(std::ostream& os, const std::vector<T>& v) { for (auto& e : v) os\
    \ << e << ' '; return os; }\n    template<typename T> std::ostream& operator <<\
    \ (std::ostream& os, std::set<T>& set_var) { os << \"{\"; for (auto itr = set_var.begin();\
    \ itr != set_var.end(); itr++) { os << *itr;++itr;if (itr != set_var.end()) os\
    \ << \", \";itr--; }os << \"}\";return os; }\n    template <typename T, typename\
    \ U> std::ostream& operator<<(std::ostream& os, std::map<T, U>& map_var) { os\
    \ << \"{\";for (auto itr = map_var.begin(); itr != map_var.end(); itr++) { os\
    \ << *itr;itr++;if (itr != map_var.end()) os << \", \";itr--; }os << \"}\";return\
    \ os; }\n\n\n    std::istream& operator>>(std::istream& is, atcoder::modint998244353&\
    \ a) { long long v; is >> v; a = v; return is; }\n    std::ostream& operator<<(std::ostream&\
    \ os, const atcoder::modint998244353& a) { return os << a.val(); }\n    std::istream&\
    \ operator>>(std::istream& is, atcoder::modint1000000007& a) { long long v; is\
    \ >> v; a = v; return is; }\n    std::ostream& operator<<(std::ostream& os, const\
    \ atcoder::modint1000000007& a) { return os << a.val(); }\n    template<int m>\
    \ std::istream& operator>>(std::istream& is, atcoder::static_modint<m>& a) { long\
    \ long v; is >> v; a = v; return is; }\n    template<int m> std::ostream& operator<<(std::ostream&\
    \ os, const atcoder::static_modint<m>& a) { return os << a.val(); }\n    template<int\
    \ m> std::istream& operator>>(std::istream& is, atcoder::dynamic_modint<m>& a)\
    \ { long long v; is >> v; a = v; return is; }\n    template<int m> std::ostream&\
    \ operator<<(std::ostream& os, const atcoder::dynamic_modint<m>& a) { return os\
    \ << a.val(); }\n\n    void print() { std::cout << '\\n'; }\n    template<class\
    \ T, class... Ts>void print(const T& a, const Ts&... b) { std::cout << a; (std::cout\
    \ << ... << (std::cout << ' ', b)); std::cout << '\\n'; }\n    void drop() { std::cout\
    \ << '\\n';exit(0); }\n    template<class T, class... Ts>void drop(const T& a,\
    \ const Ts&... b) { std::cout << a; (std::cout << ... << (std::cout << ' ', b));\
    \ std::cout << '\\n';exit(0); }\n#ifdef __LOCAL\n    void debug_out() { std::cerr\
    \ << std::endl; }\n    template < class Head, class... Tail> void debug_out(Head\
    \ H, Tail... T) { std::cerr << ' ' << H; debug_out(T...); }\n#define debug(...)\
    \ std::cerr << 'L' << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) std::cerr << 'L' << __LINE__ << \" \" << #x << \" = \" << (x)\
    \ << std::endl\n#else\n#define debug(...) (void(0))\n#define dump(x) (void(0))\n\
    #endif\n} // namespace tomo0608\n"
  code: "#include<iostream>\n#include<set>\n#include<vector>\n#include<map>\n#include\
    \ <atcoder/modint>\n\nnamespace tomo0608 {\n    template<class... T>void input(T&...\
    \ a) { (std::cin >> ... >> a); };\n\n#define INT(...) int __VA_ARGS__; input(__VA_ARGS__)\n\
    #define LL(...) ll __VA_ARGS__; input(__VA_ARGS__)\n#define STR(...) string __VA_ARGS__;\
    \ input(__VA_ARGS__)\n#define DBL(...) double __VA_ARGS__; input(__VA_ARGS__)\n\
    \n    template<class T1, class T2> std::istream& operator>>(std::istream& is,\
    \ std::pair<T1, T2>& p) { is >> p.first >> p.second; return is; }\n    template<class\
    \ T1, class T2> std::ostream& operator<<(std::ostream& os, const std::pair<T1,\
    \ T2>& p) { os << '(' << p.first << \", \" << p.second << ')'; return os; }\n\
    \    template<class T> std::istream& operator>>(std::istream& is, std::vector<T>&\
    \ v) { for (auto& e : v) is >> e; return is; }\n    template<class T> std::ostream&\
    \ operator<<(std::ostream& os, const std::vector<T>& v) { for (auto& e : v) os\
    \ << e << ' '; return os; }\n    template<typename T> std::ostream& operator <<\
    \ (std::ostream& os, std::set<T>& set_var) { os << \"{\"; for (auto itr = set_var.begin();\
    \ itr != set_var.end(); itr++) { os << *itr;++itr;if (itr != set_var.end()) os\
    \ << \", \";itr--; }os << \"}\";return os; }\n    template <typename T, typename\
    \ U> std::ostream& operator<<(std::ostream& os, std::map<T, U>& map_var) { os\
    \ << \"{\";for (auto itr = map_var.begin(); itr != map_var.end(); itr++) { os\
    \ << *itr;itr++;if (itr != map_var.end()) os << \", \";itr--; }os << \"}\";return\
    \ os; }\n\n\n    std::istream& operator>>(std::istream& is, atcoder::modint998244353&\
    \ a) { long long v; is >> v; a = v; return is; }\n    std::ostream& operator<<(std::ostream&\
    \ os, const atcoder::modint998244353& a) { return os << a.val(); }\n    std::istream&\
    \ operator>>(std::istream& is, atcoder::modint1000000007& a) { long long v; is\
    \ >> v; a = v; return is; }\n    std::ostream& operator<<(std::ostream& os, const\
    \ atcoder::modint1000000007& a) { return os << a.val(); }\n    template<int m>\
    \ std::istream& operator>>(std::istream& is, atcoder::static_modint<m>& a) { long\
    \ long v; is >> v; a = v; return is; }\n    template<int m> std::ostream& operator<<(std::ostream&\
    \ os, const atcoder::static_modint<m>& a) { return os << a.val(); }\n    template<int\
    \ m> std::istream& operator>>(std::istream& is, atcoder::dynamic_modint<m>& a)\
    \ { long long v; is >> v; a = v; return is; }\n    template<int m> std::ostream&\
    \ operator<<(std::ostream& os, const atcoder::dynamic_modint<m>& a) { return os\
    \ << a.val(); }\n\n    void print() { std::cout << '\\n'; }\n    template<class\
    \ T, class... Ts>void print(const T& a, const Ts&... b) { std::cout << a; (std::cout\
    \ << ... << (std::cout << ' ', b)); std::cout << '\\n'; }\n    void drop() { std::cout\
    \ << '\\n';exit(0); }\n    template<class T, class... Ts>void drop(const T& a,\
    \ const Ts&... b) { std::cout << a; (std::cout << ... << (std::cout << ' ', b));\
    \ std::cout << '\\n';exit(0); }\n#ifdef __LOCAL\n    void debug_out() { std::cerr\
    \ << std::endl; }\n    template < class Head, class... Tail> void debug_out(Head\
    \ H, Tail... T) { std::cerr << ' ' << H; debug_out(T...); }\n#define debug(...)\
    \ std::cerr << 'L' << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) std::cerr << 'L' << __LINE__ << \" \" << #x << \" = \" << (x)\
    \ << std::endl\n#else\n#define debug(...) (void(0))\n#define dump(x) (void(0))\n\
    #endif\n} // namespace tomo0608"
  dependsOn: []
  isVerificationFile: false
  path: lib/IO.hpp
  requiredBy: []
  timestamp: '2023-04-14 17:06:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/IO.hpp
layout: document
redirect_from:
- /library/lib/IO.hpp
- /library/lib/IO.hpp.html
title: lib/IO.hpp
---
