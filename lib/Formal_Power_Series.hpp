#include <vector>
#include <assert.h>
#include <atcoder/modint>
#include <atcoder/convolution>

namespace tomo0608 {
    template<typename mint>
    struct formal_power_series : public std::vector<mint> {
        using FPS = formal_power_series;
        using std::vector<mint>::vector;
        using std::vector<mint>::operator=;

        void shrink() {
            while (this->size() && this->back() == mint(0))this->pop_back();
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

        friend FPS operator/(const FPS& lhs, const mint& rhs) {
            return FPS(lhs) /= rhs;
        }

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
} // namespace tomo0608