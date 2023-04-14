#include<vector>
#include<queue>

namespace tomo0608 {
#define all(x) x.begin(),x.end()
    template <class T = long long, class S> T SUM(const S& v) { return accumulate(all(v), T(0)); }
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
    template <typename T> void zip(std::vector<T>& x) { std::vector<T> y = x;UNIQUE(y);for (int i = 0; i < x.size(); ++i) { x[i] = lb(y, x[i]); } }
    template<class T> using priority_queue_rev = std::priority_queue<T, std::vector<T>, std::greater<T>>;
    template<class T, class U> inline bool chmax(T& a, const U& b) { if (a < b) { a = b; return 1; } return 0; }
    template<class T, class U> inline bool chmin(T& a, const U& b) { if (a > b) { a = b; return 1; } return 0; }
    template<class T> inline int count_between(std::vector<T>& a, T l, T r) { return lower_bound(all(a), r) - lower_bound(all(a), l); } // [l, r)
#define bit(n, k) ((n >> k) & 1) /*nのk bit目*/
    int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
    int topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
    int lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
    int lowbit(long long a) { return a == 0 ? 64 : __builtin_ctzll(a); }
    template <typename T>T mypow(T x, long long n) { T ret = 1;while (n > 0) { if (n & 1)(ret *= x);(x *= x);n >>= 1; }return ret; }
}