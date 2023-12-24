#pragma once
#include <vector>
#include <algorithm>
#include <assert.h>
#include <atcoder/modint>
#include <iostream>
#include <atcoder/convolution>

namespace tomo0608 {
    template<typename mint>
    struct Formal_Power_Series : public std::vector<mint> {
        using FPS = Formal_Power_Series;
        using std::vector<mint>::vector;
        using std::vector<mint>::operator=;

        void shrink() {
            while (this->size() && this->back() == mint(0))this->pop_back();
        }
        FPS rev()const {
            auto res = *this;
            std::reverse(res.begin(), res.end());
            return res;
        }

        FPS& operator+=(const FPS& rhs) {
            if (rhs.size() > this->size())this->resize(rhs.size());
            for (int i = 0; i < (int)rhs.size();i++)(*this)[i] += rhs[i];
            return *this;
        }

        FPS& operator-=(const FPS& rhs) {
            if (rhs.size() > this->size())this->resize(rhs.size());
            for (int i = 0; i < (int)rhs.size();i++)(*this)[i] -= rhs[i];
            return *this;
        }

        FPS& operator+=(const mint& rhs) {
            if (this->empty())this->resize(1);
            (*this)[0] += rhs;
            return *this;
        }

        FPS& operator-=(const mint& rhs) {
            if (this->empty())this->resize(1);
            (*this)[0] -= rhs;
            return *this;
        }

        FPS& operator*=(const mint& rhs) {
            for (auto& e : *this)e *= rhs;
            return *this;
        }

        FPS& operator*=(const FPS& rhs) {
            *this = atcoder::convolution((*this), rhs);
            return *this;
        }

        FPS& operator/=(const mint& c) {
            assert(c != mint(0));
            *this *= c.inv();
            return *this;
        }

        FPS& operator/=(const FPS& rhs) {
            *this *= rhs.inv();
            this->resize(rhs.size());
            return *this;
        }

        friend FPS operator+(const FPS& lhs, const FPS& rhs) {
            return FPS(lhs) += rhs;
        }

        friend FPS operator+(const FPS& lhs, const mint& rhs) {
            return FPS(lhs) += rhs;
        }

        friend FPS operator-(const FPS& lhs, const FPS& rhs) {
            return FPS(lhs) -= rhs;
        }

        friend FPS operator-(const FPS& lhs, const mint& rhs) {
            return FPS(lhs) -= rhs;
        }

        friend FPS operator*(const FPS& lhs, const FPS& rhs) {
            return FPS(lhs) *= rhs;
        }

        friend FPS operator*(const FPS& lhs, const mint& rhs) {
            return FPS(lhs) *= rhs;
        }

        friend FPS operator/(const FPS& lhs, const FPS& rhs) {
            return FPS(lhs) /= rhs;
        }

        friend FPS operator/(const FPS& lhs, const mint& rhs) {
            return FPS(lhs) /= rhs;
        }
        // friend std::ostream& operator<<(std::ostream& os, FPS& f) {
        //     for (int i = 0; i < f.size(); i++) {
        //         os << f[i] << (i + 1 == f.size() ? "\n" : " ");
        //     }
        //     return (os);
        // }

        FPS inv(int deg = -1) const {
            assert(this->front() != mint(0));
            if (deg == -1)deg = this->size();
            FPS res = { this->front().inv() };
            for (int d = 1; d < deg; d <<= 1) {
                FPS f(2 * d), g(2 * d);
                for (int j = 0; j < std::min((int)this->size(), 2 * d); j++)f[j] = (*this)[j];
                for (int j = 0; j < d; j++)g[j] = res[j];

                atcoder::internal::butterfly(f);
                atcoder::internal::butterfly(g);

                for (int j = 0; j < 2 * d; j++)f[j] *= g[j];

                atcoder::internal::butterfly_inv(f);
                f /= 2 * d;

                for (int j = 0; j < d; j++) {
                    f[j] = f[j + d];
                    f[j + d] = 0;
                }

                atcoder::internal::butterfly(f);

                for (int j = 0; j < 2 * d; j++)f[j] *= -g[j];

                atcoder::internal::butterfly_inv(f);
                f /= 2 * d;

                for (int j = 0; j < d; j++)res.emplace_back(f[j]);
            }
            res.resize(deg);
            return res;
        }

        FPS operator-() const {
            FPS res(*this);
            for (auto& e : res) e = -e;
            return res;
        }

        FPS derivative() const {
            FPS res(this->begin() + 1, this->end());
            res.emplace_back(0);
            for (int j = 0; j < res.size(); j++)res[j] *= (j + 1);
            return res;
        }

        FPS integral(bool truncate = true) const {
            FPS res(this->size() + 1 - truncate, 0);
            for (int j = 0; j < this->size() - truncate; j++)res[j + 1] = (*this)[j] / (j + 1);
            return res;
        }

        FPS log() const {
            FPS f = this->derivative();
            f /= (*this);
            return f.integral();
        }
        // https://arxiv.org/pdf/1301.5804.pdf
        FPS exp(int deg = -1) const {
            assert(this->front() == mint(0));
            if (deg == -1)deg = this->size();
            FPS f = { 1 }, g = { 1 };
            for (int d = 1; d < deg; d <<= 1) {
                FPS f_next(f);
                f_next.resize(2 * d, 0);
                atcoder::internal::butterfly(f_next);

                g.resize(2 * d, 0);
                atcoder::internal::butterfly(g);
                for (int j = 0; j < 2 * d; j++)g[j] = 2 * g[j] - f_next[j] * g[j] * g[j];
                atcoder::internal::butterfly_inv(g);
                g /= 2 * d;
                g.resize(d);

                FPS q(2 * d);
                for (int j = 0; j < d && j < this->size() - 1; j++)q[j] = (*this)[j + 1] * (j + 1);

                FPS w(2 * d);
                FPS G(g);
                G.resize(2 * d, 0);
                atcoder::internal::butterfly(G);
                for (int j = 0; j < 2 * d; j++)w[j] = f_next[j] * G[j];
                atcoder::internal::butterfly_inv(w);
                w /= 2 * d;

                for (int j = 0; j < d; j++) {
                    w[j] = w[j + d];
                    w[j + d] = 0;
                }

                atcoder::internal::butterfly(w);
                atcoder::internal::butterfly(q);
                for (int j = 0; j < 2 * d; j++)w[j] *= q[j];
                atcoder::internal::butterfly_inv(w);
                w /= 2 * d;

                FPS df(f.derivative());
                df.resize(2 * d, 0);
                atcoder::internal::butterfly(df);
                for (int j = 0;j < 2 * d;j++)df[j] *= G[j];
                atcoder::internal::butterfly_inv(df);
                df /= 2 * d;

                for (int j = 0; j < d;j++) {
                    w[j + d] = w[j];
                    w[j] = 0;
                }
                w -= df;

                w = w.integral();

                for (int j = 0; j < 2 * d && j < this->size(); j++)w[j] += (*this)[j];
                for (int j = 0; j < d;j++) {
                    w[j] = w[j + d];
                    w[j + d] = 0;
                }
                atcoder::internal::butterfly(w);
                for (int j = 0; j < 2 * d; j++)f_next[j] *= w[j];
                atcoder::internal::butterfly_inv(f_next);
                f_next /= 2 * d;
                f.resize(2 * d, 0);
                for (int j = 0; j < d; j++)f[j + d] = f_next[j];
            }
            f.resize(deg);
            return f;
        }

        FPS pow(long long m) const {
            int n = this->size();
            if (m == 0) {
                auto res = FPS(n, 0);
                res[0] = 1;
                return res;
            }
            int l = std::find_if(this->begin(), this->end(), [](mint x) {return x != mint(0);}) - this->begin();
            if (l == this->size() || (l && m >= (n + l - 1) / l))return FPS(n, 0);

            FPS res(this->begin() + l, this->end());
            mint c = (*this)[l];
            res /= c;
            res.resize(n, 0);
            res = (res.log() * mint(m)).exp();
            res.erase(res.begin() + (n - m * l), res.end());
            res *= c.pow(m);
            std::reverse(res.begin(), res.end());
            res.resize(n, 0);
            std::reverse(res.begin(), res.end());
            return res;
        }

    };


    // for sparse fps
    template <typename mint>
    Formal_Power_Series<mint> positive_unit_fractions(int n) { // res[i] = 1 / i, res[0] = 0 length: n+1
        static const int mod = mint::mod();
        static Formal_Power_Series<mint> res = { 0, 1 };
        assert(0 < n);
        if (n >= mod) n -= mod;
        while (int(res.size()) <= n) {
            int num = res.size();
            int q = (mod + num - 1) / num;
            res.emplace_back(res[num * q - mod] * mint(q));
        }
        return res;
    }

    template<typename mint>
    std::vector<std::pair<int, mint>> compress_fps(const Formal_Power_Series<mint>& f) {
        int n = f.size();
        std::vector<std::pair<int, mint>> cf;
        for (int i = 0; i < n; i++) {
            if (f[i] != 0)cf.emplace_back(i, f[i]);
        }
        return cf;
    }

    template<typename mint>
    Formal_Power_Series<mint> mul_sparse(const Formal_Power_Series<mint>& f, const Formal_Power_Series<mint>& g) {
        int n = f.size(), m = g.size();
        auto cf = compress_fps<mint>(f), cg = compress_fps<mint>(g);
        Formal_Power_Series<mint> h(n + m - 1);
        for (auto [i, p] : cf)for (auto [j, q] : cg)h[i + j] += p * q;
        return h;
    }
    

    template<typename mint>
    Formal_Power_Series<mint> inv_sparse(const Formal_Power_Series<mint>& f, int deg = -1) {
        assert(f[0] != 0);
        if (deg == -1)deg = f.size();
        auto cf = compress_fps<mint>(f);
        Formal_Power_Series<mint> f_inv(deg);
        f_inv[0] = f[0].inv();
        for (int i = 1; i < deg; i++) {
            for (auto [k, p] : cf) {
                if (i - k < 0)break;
                f_inv[i] -= f_inv[i - k] * p;
            }
            f_inv[i] *= f_inv[0];
        }
        return f_inv;
    }

    template<typename mint>
    Formal_Power_Series<mint> exp_sparse(const Formal_Power_Series<mint>& f, int deg = -1) {
        assert(f[0] == 0);
        if (deg == -1)deg = f.size();
        auto cf = compress_fps<mint>(f);
        Formal_Power_Series<mint> f_exp(deg);
        Formal_Power_Series<mint> inv_num = positive_unit_fractions<mint>(deg);
        f_exp[0] = 1;
        for (int i = 1; i < deg; i++) {
            for (auto [k, p] : cf) {
                if (i - k < 0)break;
                f_exp[i] += f_exp[i - k] * p * k;
            }
            f_exp[i] *= inv_num[i];
        }
        return f_exp;
    }

    template<typename mint>
    Formal_Power_Series<mint> log_sparse(const Formal_Power_Series<mint>& f, int deg = -1) {
        assert(f[0] == 1);
        if (deg == -1)deg = f.size();
        Formal_Power_Series<mint> df = f.derivative();
        Formal_Power_Series<mint> df_log = mul_sparse<mint>(df, inv_sparse<mint>(f));
        Formal_Power_Series<mint> f_log = df_log.integral();
        f_log.resize(deg);
        return f_log;
    }

    template<typename mint>
    Formal_Power_Series<mint> __pow_sparse_const_1(const Formal_Power_Series<mint>& f, long long k, int deg) {
        int n = f.size();
        assert(n > 0 && f[0] == 1);
        auto cf = compress_fps<mint>(f);
        Formal_Power_Series<mint> f_pow_k(deg);
        Formal_Power_Series<mint> inv_num = positive_unit_fractions<mint>(deg);
        f_pow_k[0] = 1;
        for (int i = 1; i < deg; i++) {
            for (const auto& [j, coef] : cf) {
                if (i - j < 0) break;
                f_pow_k[i] += (mint(k) * mint(j) - mint(i - j)) * coef * f_pow_k[i - j];
            }
            f_pow_k[i] *= inv_num[i];
        }
        return f_pow_k;
    }

    template<typename mint>
    Formal_Power_Series<mint> pow_sparse(const Formal_Power_Series<mint>& f, long long k, int deg = -1) {
        int n = f.size();
        if (deg < 0)deg = n;
        assert(k >= 0);
        if (k == 0) {
            Formal_Power_Series<mint> res(deg, 0);
            if (deg)res[0] = 1;
            return res;
        }
        int l = std::find_if(f.begin(), f.end(), [](mint x) {return x != mint(0);}) - f.begin();
        if (l == f.size() || (l && k >= (deg + l - 1) / l))return Formal_Power_Series<mint>(deg, 0);

        Formal_Power_Series<mint> res(f.begin() + l, f.end());
        mint c = f[l];
        res /= c;
        res.resize(deg, 0);
        res = __pow_sparse_const_1<mint>(res, k, deg);
        res.erase(res.begin() + (deg - k * l), res.end());
        res *= c.pow(k);
        std::reverse(res.begin(), res.end());
        res.resize(deg, 0);
        std::reverse(res.begin(), res.end());
        return res;
    }

    template<typename mint>
    struct Bostan_Mori {
        std::vector<mint> p, q;
        Bostan_Mori(std::vector<mint>& _p, std::vector<mint>& _q) : p(_p), q(_q) {}
        void rev(std::vector<mint>& f) const {
            int d = f.size();
            for (int i = 0; i < d; ++i) if (i & 1) f[i] = -f[i];
        }
        void even(std::vector<mint>& f) const {
            int d = (f.size() + 1) >> 1;
            for (int i = 0; i < d; ++i) f[i] = f[i << 1];
            f.resize(d);
        }
        void odd(std::vector<mint>& f) const {
            int d = f.size() >> 1;
            for (int i = 0; i < d; ++i) f[i] = f[i << 1 | 1];
            f.resize(d);
        }

        mint operator[](long long n)const {
            std::vector<mint> _p(p), _q(q), _q_rev(q);
            rev(_q_rev);
            for (; n; n >>= 1) {
                _p = atcoder::convolution(move(_p), _q_rev);
                if (n & 1)odd(_p);
                else even(_p);
                _q = atcoder::convolution(move(_q), move(_q_rev));
                even(_q);
                _q_rev = _q;
                rev(_q_rev);
            }
            return _p[0] / _q[0];
        }
    };

} // namespace tomo0608