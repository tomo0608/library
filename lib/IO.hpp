#pragma once

#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<tuple>
#include <iomanip>

namespace tomo0608 {
    typedef long long ll;
    typedef long double ld;
    template <class T> using V = std::vector<T>;
    template <class T> using VV = V<V<T>>;
    template <class T> using VVV = V<VV<T>>;
    typedef std::pair<int, int> pii;
    typedef std::pair<long long, long long> pll;
    template<class... T>void input(T&... a) { (std::cin >> ... >> a); };

#define INT(...) int __VA_ARGS__; IN(__VA_ARGS__)
#define LL(...) long long __VA_ARGS__; IN(__VA_ARGS__)
#define CHAR(...) char __VA_ARGS__; IN(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; IN(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__; IN(__VA_ARGS__)
#define VEC(type, name, size) std::vector<type> name(size);IN(name)
#define VECVEC(type, name, h, w) std::vector<std::vector<type>> name(h, std::vector<type>(w));IN(name)
    template<class T1, class T2> std::istream& operator>>(std::istream& is, std::pair<T1, T2>& p) { is >> p.first >> p.second; return is; }
    template<class T1, class T2> std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
    template<class T> std::istream& operator>>(std::istream& is, std::vector<T>& v) { for (auto& e : v) is >> e; return is; }
    template<class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) { for (auto& e : v) os << e << ' '; return os; }
    template<typename T> std::ostream& operator << (std::ostream& os, std::set<T>& set_var) { os << "{"; for (auto itr = set_var.begin(); itr != set_var.end(); itr++) { os << *itr;++itr;if (itr != set_var.end()) os << ", ";itr--; }os << "}";return os; }
    template <typename T, typename U> std::ostream& operator<<(std::ostream& os, std::map<T, U>& map_var) { os << "{";for (auto itr = map_var.begin(); itr != map_var.end(); itr++) { os << *itr;itr++;if (itr != map_var.end()) os << ", ";itr--; }os << "}";return os; }
    template<int i, class T> void print_tuple(std::ostream&, const T&) {}
    template<int i, class T, class H, class ...Args> void print_tuple(std::ostream& os, const T& t) {
        if (i){os << ", ";} os << std::get<i>(t); print_tuple<i + 1, T, Args...>(os, t);
    }
    template<class ...Args> std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& t) {
        os << "{"; print_tuple<0, std::tuple<Args...>, Args...>(os, t); return os << "}";
    }

    void IN() {}
    template <class Head, class... Tail> void IN(Head& head, Tail &...tail) {
        std::cin >> head;
        IN(tail...);
    }
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


#define rep1(a)          for(long long i = 0; i < (a); i++)
#define rep2(i, a)       for(long long i = 0; i < (a); i++)
#define rep3(i, a, b)    for(long long i = (a); i < (b); i++)
#define rep4(i, a, b, c) for(long long i = (a); i < (b); i += (c))
#define drep1(a)          for(long long i = (a)-1; i >= 0; i--)
#define drep2(i, a)       for(long long i = (a)-1; i >= 0; i--)
#define drep3(i, a, b)    for(long long i = (a)-1; i >= (b); i--)
#define drep4(i, a, b, c) for(long long i = (a)-1; i >= (b); i -= (c))
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define drep(...) overload4(__VA_ARGS__, drep4, drep3, drep2, drep1)(__VA_ARGS__)
#define endl '\n'

    struct io_setup {
        io_setup() {
            std::cin.tie(0);
            std::ios_base::sync_with_stdio(false);
            std::cout << std::setprecision(20);
        }
    }io_setup;
} // namespace tomo0608