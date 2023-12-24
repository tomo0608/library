#pragma once

#include<vector>
#include<atcoder/modint>

namespace tomo0608 {
    // Binomial Coefficient of modint
    template<class mint> struct BiCoef {
        std::vector<mint> fact_, inv_, finv_;
        constexpr BiCoef() {}
        constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
            init(n);
        }
        constexpr void init(int n) noexcept {
            fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
            int MOD = fact_[0].mod();
            for (int i = 2; i < n; i++) {
                fact_[i] = fact_[i - 1] * i;
                inv_[i] = -inv_[MOD % i] * (MOD / i);
                finv_[i] = finv_[i - 1] * inv_[i];
            }
        }
        constexpr mint com(int n, int k) const noexcept {
            if (n < k || n < 0 || k < 0)return 0;
            return fact_[n] * finv_[k] * finv_[n - k];
        }
        constexpr mint perm(int n, int k) const noexcept {
            if (n < k || n < 0 || k < 0)return 0;
            return fact_[n] * finv_[n - k];
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
        inline mint operator()(int n, int k) { return com(n, k); }

        constexpr mint com_naive(int n, int k) {
            if (n < k || n < 0 || k < 0)return 0;
            mint res = 1;
            k = std::min(k, n - k);
            for (int i = 1; i <= k; i++)res *= inv(i) * (n--);
            return res;
        }

        constexpr mint homo(int n, int r) {
            if (n < 0 || r < 0)return 0;
            return r == 0 ? 1 : com(n + r - 1, r);
        }
    };
} // namespace tomo0608
