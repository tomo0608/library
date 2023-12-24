#pragma once
#include<vector>
#include<cstddef>
#include<cassert>

namespace tomo0608 {
    template<typename mint>
    struct Set_Power_Series : public std::vector<mint> {
        using SPS = Set_Power_Series;
        using SPS_with_rank = std::vector<std::vector<mint>>;
        using std::vector<mint>::vector;
        using std::vector<mint>::operator=;

        SPS& operator+=(const SPS& rhs) {
            assert(this->size() == rhs.size());
            for (unsigned i = 0; i < this->size();i++)(*this)[i] += rhs[i];
            return *this;
        }

        SPS& operator-=(const SPS& rhs) {
            assert(this->size() == rhs.size());
            for (unsigned i = 0; i < this->size();i++)(*this)[i] -= rhs[i];
            return *this;
        }

        SPS& operator*=(const mint& rhs) {
            for (auto& e : *this)e *= rhs;
            return *this;
        }

        SPS& operator/=(const mint& rhs) {
            assert(rhs != mint(0));
            *this *= rhs.inv();
            return *this;
        }

        friend SPS operator+(const SPS& lhs, const SPS& rhs) {
            return SPS(lhs) += rhs;
        }

        friend SPS operator-(const SPS& lhs, const SPS& rhs) {
            return SPS(lhs) -= rhs;
        }

        friend SPS operator*(const SPS& lhs, const mint& rhs) {
            return SPS(lhs) *= rhs;
        }

        friend SPS operator/(const SPS& lhs, const mint& rhs) {
            return SPS(lhs) /= rhs;
        }

        SPS operator-() const {
            SPS res(*this);
            for (auto& e : res) e = -e;
            return res;
        }

        static void ranked_zeta(SPS_with_rank& f) {
            unsigned N = f.size();
            for (unsigned i = 1; i < N; i *= 2) {
                for (unsigned j = 0; j < N; j += i * 2) {
                    for (unsigned k = 0; k < i; k++) {
                        for (unsigned r = 0; r < __builtin_popcount(i + j + k); r++) {
                            f[i + j + k][r] += f[j + k][r];
                        }
                    }
                }
            }
        }

        static void ranked_mebius(SPS_with_rank& f) {
            unsigned N = f.size(), n = f[0].size();
            for (unsigned i = N >> 1; i > 0; i >>= 1) {
                for (unsigned j = 0; j < N; j += i * 2) {
                    for (unsigned k = 0; k < i; k++) {
                        for (unsigned r = __builtin_popcount(i + j + k); r < n; r++) {
                            f[i + j + k][r] -= f[j + k][r];
                        }
                    }
                }
            }
        }

        static SPS_with_rank lift(const SPS& f) {
            SPS_with_rank F(f.size(), std::vector<mint>(__builtin_ctz(f.size()) + 1));
            for (unsigned i = 0; i < f.size(); i++) {
                F[i][__builtin_popcount(i)] = f[i];
            }
            return F;
        }

        static SPS unlift(const SPS_with_rank& F) {
            SPS f(F.size());
            for (unsigned i = 0; i < F.size(); i++) {
                f[i] = F[i][__builtin_popcount(i)];
            }
            return f;
        }

        static SPS subset_convolution(const SPS& f, const SPS& g) {
            SPS_with_rank F = lift(f), G = lift(g);
            unsigned N = F.size(), n = F[0].size();
            ranked_zeta(F), ranked_zeta(G);
            for (int i = 0; i < N; i++) {
                std::vector<mint> tmp(n);
                for (int j = 0; j < n; j++) {
                    for (int k = 0; j + k < n; k++) {
                        tmp[j + k] += F[i][j] * G[i][k];
                    }
                }
                F[i].swap(tmp);
            }
            ranked_mebius(F);
            return unlift(F);
        }

        SPS& operator*=(const SPS& rhs) {
            *this = subset_convolution((*this), rhs);
            return *this;
        }

        friend SPS operator*(const SPS& lhs, const SPS& rhs) {
            return SPS(lhs) *= rhs;
        }

        SPS inv() const{
            int n = __builtin_ctz(this->size());
            assert((int)this->size() == (1 << n) && this->front() != mint(0));
            SPS dp(this->size());
            dp[0] = (this->front()).inv();
            for(int i = 0; i < n; i++){
                SPS a = {this->begin() + (1 << i), this->begin() + (2 << i)};
                SPS b = {dp.begin(), dp.begin() + dp.begin() + (1 << i)};
                a *= a;
                a *= b;
                std::copy(a.begin(), a.end(), dp.begin() + (1 << i));
            }
            return dp;
        }

        SPS composition_egf(std::vector<mint>& egf) {
            int N = this->size();
            int n = __builtin_ctz(N);
            assert(N == (1 << n) && this->front() == mint(0));
            if ((int)egf.size() > n)egf.resize(n + 1);
            int D = egf.size() - 1;

            std::vector<SPS_with_rank> zs(n);
            for (int i = 0; i < n; i++) {
                SPS tmp = { this->begin() + (1 << i), this->begin() + (2 << i) };
                zs[i] = lift(tmp);
                ranked_zeta(zs[i]);
            }

            SPS dp(1 << (n - D));
            dp[0] = egf[D];
            for (int d = D - 1; d >= 0; d--) {
                SPS ndp(1 << (n - d));
                ndp[0] = egf[d];
                SPS_with_rank zdp = lift(dp);
                ranked_zeta(zdp);
                for (int i = 0; i < n - d; i++) {
                    // zs[1<<i: 2<<i], zdp[0:1<<i]
                    SPS_with_rank znewdp(1 << i, std::vector<mint>(i + 1));
                    for (int k = 0; k < (1 << i); k++) {
                        for (int p = 0; p <= i; p++)for (int q = 0; q <= i - p; q++) {
                            znewdp[k][p + q] += zdp[k][p] * zs[i][k][q];
                        }
                    }
                    ranked_mebius(znewdp);
                    auto x = unlift(znewdp);
                    std::copy(x.begin(), x.end(), ndp.begin() + (1 << i));
                }
                swap(dp, ndp);
            }
            return dp;
        }

        SPS composition_poly(std::vector<mint>& poly){
            int N = this->size();
            int n = __builtin_ctz(N);
            assert(N == (1 << n));
            if(poly.empty())return SPS(N, mint(0));

            int D = std::min<int>((int)poly.size()-1, n);

            std::vector<mint> g(D+1);
            SPS res = *this;
            mint c = res[0];
            res[0] = 0;

            std::vector<mint> pw(D+1);
            pw[0] = 1;
            for(int i = 0; i < (int)poly.size(); i++){
                for(int j = 0; j <= D; j++)g[j] += poly[i] * pw[j];
                for(int j = D; j >= 0; j--)pw[j] = pw[j] * c + (j == 0 ? mint(0): pw[j-1]);
            }
            mint fct = 1;
            for(int j = 0; j <= D; j++)g[j] *= fct, fct *= mint(j+1);
            return res.composition_egf(g);
        }

        SPS exp() const {
            int n = __builtin_ctz(this->size());
            assert((int)this->size() == (1 << n) && this->front() == mint(0));
            SPS dp(this->size());
            dp[0] = mint(1);
            for (int i = 0; i < n; i++) {
                SPS a = { this->begin() + (1 << i), this->begin() + (2 << i) };
                SPS b = { dp.begin(), dp.begin() + (1 << i) };
                a *= b;
                std::copy(a.begin(), a.end(), dp.begin() + (1 << i));
            }
            return dp;
        }

        SPS log() const {
            int n = __builtin_ctz(this->size());
            assert((int)this->size() == (1 << n) && this->front() == mint(1));
            std::vector<mint> egf(n + 1);
            mint tmp = -1;
            for (int i = 1; i <= n; i++) {
                egf[i] = tmp;
                tmp *= i;
            }
            SPS s = -(*this);
            s[0] = 0;
            return s.composition_egf(egf);
        }

    };
}// namespace tomo0608
