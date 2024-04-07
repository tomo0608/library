#pragma once
#include<vector>
#include<queue>
#include<cstdlib>
#include<cassert>
#include<algorithm>
#include<numeric>
#include<random>
#include<chrono>

namespace tomo0608 {
#define ALL(x) x.begin(),x.end()
    template <class T = long long, class S> T SUM(const S& v) { return accumulate(ALL(v), T(0)); }
#define MIN(v) *min_element(ALL(v))
#define MAX(v) *max_element(ALL(v))
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define RSORT(v) sort(ALL(v)); reverse(ALL(v))
#define UNIQUE(x) SORT(x), x.erase(unique(ALL(x)), x.end())
#define lb(c, x) distance((c).begin(), lower_bound(ALL(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(ALL(c), (x)))
    template <typename T> void zip(std::vector<T>& x) { std::vector<T> y = x;UNIQUE(y);for (int i = 0; i < x.size(); ++i) { x[i] = lb(y, x[i]); } }
    template<class T> using priority_queue_rev = std::priority_queue<T, std::vector<T>, std::greater<T>>;
    template<class T, class U> inline bool chmax(T& a, const U& b) { if (a < b) { a = b; return 1; } return 0; }
    template<class T, class U> inline bool chmin(T& a, const U& b) { if (a > b) { a = b; return 1; } return 0; }
    template<class T> inline int count_between(std::vector<T>& a, T l, T r) { return lower_bound(ALL(a), r) - lower_bound(ALL(a), l); } // [l, r)
    template<typename T> int bittest(T n, int k) { return (n >> k) & 1; }
    int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
    int topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
    int lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
    int lowbit(long long a) { return a == 0 ? 64 : __builtin_ctzll(a); }
#define perm(v) for(bool permrepflag = true; (permrepflag ? exchange(permrepflag, false) : next_permutation(ALL(v)));)
    template <typename T, typename S> T ceil(T x, S y) {
        assert(y);
        return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y));
    }

    template <typename T, typename S> T floor(T x, S y) {
        assert(y);
        return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : x / y - (x % y == 0 ? 0 : 1)));
    }

    template <typename T> std::vector<int> id_sort(const std::vector<T>& v, bool greater = false) {
        int n = v.size();
        std::vector<int> ret(n);
        std::iota(ALL(ret), 0);
        std::sort(begin(ret), end(ret), [&](int i, int j) { return greater ? v[i] > v[j] : v[i] < v[j]; });
        return ret;
    }

    struct Random_Number_Generator {
        std::mt19937_64 mt;

        Random_Number_Generator() : mt(std::chrono::steady_clock::now().time_since_epoch().count()) {}

        // 区間 [l,r) の整数で乱数発生
        int64_t operator()(int64_t l, int64_t r) {
            std::uniform_int_distribution<int64_t> dist(l, r - 1);
            return dist(mt);
        }

        // 区間 [0,r) の整数で乱数発生
        int64_t operator()(int64_t r) { return (*this)(0, r); }
    } rng;

    struct Timer {
        std::chrono::system_clock::time_point start_time;

        Timer() { reset(); }

        void reset() { start_time = std::chrono::system_clock::now(); }

        int get_time() {
            std::chrono::system_clock::time_point now_time = std::chrono::system_clock::now();
            return std::chrono::duration_cast<std::chrono::milliseconds>(now_time - start_time).count();
        }
    } timer;
    
}