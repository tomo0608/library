#include<iostream>
#include<set>
#include<vector>
#include<map>
#include <atcoder/modint>

namespace tomo0608 {
    template<class... T>void input(T&... a) { (std::cin >> ... >> a); };

#define INT(...) int __VA_ARGS__; input(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; input(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; input(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__; input(__VA_ARGS__)

    template<class T1, class T2> std::istream& operator>>(std::istream& is, std::pair<T1, T2>& p) { is >> p.first >> p.second; return is; }
    template<class T1, class T2> std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
    template<class T> std::istream& operator>>(std::istream& is, std::vector<T>& v) { for (auto& e : v) is >> e; return is; }
    template<class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) { for (auto& e : v) os << e << ' '; return os; }
    template<typename T> std::ostream& operator << (std::ostream& os, std::set<T>& set_var) { os << "{"; for (auto itr = set_var.begin(); itr != set_var.end(); itr++) { os << *itr;++itr;if (itr != set_var.end()) os << ", ";itr--; }os << "}";return os; }
    template <typename T, typename U> std::ostream& operator<<(std::ostream& os, std::map<T, U>& map_var) { os << "{";for (auto itr = map_var.begin(); itr != map_var.end(); itr++) { os << *itr;itr++;if (itr != map_var.end()) os << ", ";itr--; }os << "}";return os; }


    std::istream& operator>>(std::istream& is, atcoder::modint998244353& a) { long long v; is >> v; a = v; return is; }
    std::ostream& operator<<(std::ostream& os, const atcoder::modint998244353& a) { return os << a.val(); }
    std::istream& operator>>(std::istream& is, atcoder::modint1000000007& a) { long long v; is >> v; a = v; return is; }
    std::ostream& operator<<(std::ostream& os, const atcoder::modint1000000007& a) { return os << a.val(); }
    template<int m> std::istream& operator>>(std::istream& is, atcoder::static_modint<m>& a) { long long v; is >> v; a = v; return is; }
    template<int m> std::ostream& operator<<(std::ostream& os, const atcoder::static_modint<m>& a) { return os << a.val(); }
    template<int m> std::istream& operator>>(std::istream& is, atcoder::dynamic_modint<m>& a) { long long v; is >> v; a = v; return is; }
    template<int m> std::ostream& operator<<(std::ostream& os, const atcoder::dynamic_modint<m>& a) { return os << a.val(); }

    void print() { std::cout << '\n'; }
    template<class T, class... Ts>void print(const T& a, const Ts&... b) { std::cout << a; (std::cout << ... << (std::cout << ' ', b)); std::cout << '\n'; }
    void drop() { std::cout << '\n';exit(0); }
    template<class T, class... Ts>void drop(const T& a, const Ts&... b) { std::cout << a; (std::cout << ... << (std::cout << ' ', b)); std::cout << '\n';exit(0); }
#ifdef __LOCAL
    void debug_out() { std::cerr << std::endl; }
    template < class Head, class... Tail> void debug_out(Head H, Tail... T) { std::cerr << ' ' << H; debug_out(T...); }
#define debug(...) std::cerr << 'L' << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) std::cerr << 'L' << __LINE__ << " " << #x << " = " << (x) << std::endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif
} // namespace tomo0608