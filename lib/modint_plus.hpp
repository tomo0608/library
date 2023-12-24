#pragma once
#include<vector>
#include<atcoder/modint>
#include<iostream>

namespace tomo0608 {
    std::istream& operator>>(std::istream& is, atcoder::modint998244353& a) { long long v; is >> v; a = v; return is; }
    std::ostream& operator<<(std::ostream& os, const atcoder::modint998244353& a) { return os << a.val(); }
    std::istream& operator>>(std::istream& is, atcoder::modint1000000007& a) { long long v; is >> v; a = v; return is; }
    std::ostream& operator<<(std::ostream& os, const atcoder::modint1000000007& a) { return os << a.val(); }
    template<int m> std::istream& operator>>(std::istream& is, atcoder::static_modint<m>& a) { long long v; is >> v; a = v; return is; }
    template<int m> std::ostream& operator<<(std::ostream& os, const atcoder::static_modint<m>& a) { return os << a.val(); }
    template<int m> std::istream& operator>>(std::istream& is, atcoder::dynamic_modint<m>& a) { long long v; is >> v; a = v; return is; }
    template<int m> std::ostream& operator<<(std::ostream& os, const atcoder::dynamic_modint<m>& a) { return os << a.val(); }

    // Binomial Coefficient of modint
    template<class mint> struct BiCoef {
        std::vector<mint> fact_, inv_, finv_;
        int MAX_SIZE;
        constexpr BiCoef() {}
        constexpr BiCoef(int n) noexcept : MAX_SIZE(n+1), fact_(n+1, 1), inv_(n+1, 1), finv_(n+1, 1) {
            init(n+1);
        }
        constexpr void init(int n) noexcept {
            assert(n >= 1 && n < (int)1e8);
            fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
            int MOD = fact_[0].mod();
            for (int i = 2; i < n; i++) {
                fact_[i] = fact_[i - 1] * i;
                inv_[i] = -inv_[MOD % i] * (MOD / i);
                finv_[i] = finv_[i - 1] * inv_[i];
            }
        }
        constexpr mint com(long long n, long long k) const noexcept {
            if (n < k || n < 0 || k < 0)return 0;
            //if(n >= MAX_SIZE)return com_naive(n, k);
            return fact_[n] * finv_[k] * finv_[n - k];
        }
        constexpr mint perm(int n, int k) const noexcept {
            if (n < k || n < 0 || k < 0)return 0;
            return fact_[n] * finv_[n - k];
        }
        constexpr mint homo(int n, int r) { // The number of cases where k indistinguishable balls are put into n distinct boxes
            if (n < 0 || r < 0)return 0;
            return r == 0 ? 1 : com(n + r - 1, r);
        }
        constexpr mint second_stirling_number(int n, int r) { // The number of cases where n distinct balls are put into k indistinguishable boxes, with at least one ball in each box
            mint ret = 0;
            for (int i = 0; i <= r; i++) {
                mint tmp = com(r, i) * mint(i).pow(n);
                ret += ((r - i) & 1) ? -tmp : tmp;
            }
            return ret * finv_[r];
        }
        constexpr mint bell_number(int n, int r) { // The number of cases where n distinct balls are put into k indistinguishable boxes
            if (n == 0) return 1;
            r = std::min(r, n);
            std::vector<mint> pref(r + 1);
            pref[0] = 1;
            for (int i = 1; i <= r; i++) {
                if (i & 1) {
                    pref[i] = pref[i - 1] - finv_[i];
                }
                else {
                    pref[i] = pref[i - 1] + finv_[i];
                }
            }
            mint ret = 0;
            for (int i = 1; i <= r; i++) ret += mint(i).pow(n) * fact_[i] * pref[r - i];
            return ret;
        }

        constexpr mint fact(int n) const noexcept {
            if (n < 0)return 0;
            return fact_[n];
        }
        constexpr mint inv(int n) const noexcept {
            if (n < 0)return 0;
            return inv_[n];
        }
        constexpr mint finv(int n) const noexcept {
            if (n < 0)return 0;
            return finv_[n];
        }
        inline mint operator()(long long n, long long k) { return com(n, k); }

        constexpr mint com_naive(long long n, long long k) {
            if (n < k || n < 0 || k < 0)return 0;
            mint res = 1;
            k = std::min(k, n - k);
            for (int i = 1; i <= k; i++)res *= inv(i) * (n--);
            return res;
        }
    };

} // namespace tomo0608
