---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/Polynomial/Exp.test.cpp
    title: test/Polynomial/Exp.test.cpp
  - icon: ':x:'
    path: test/Polynomial/Inv.test.cpp
    title: test/Polynomial/Inv.test.cpp
  - icon: ':x:'
    path: test/Polynomial/Log.test.cpp
    title: test/Polynomial/Log.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://arxiv.org/pdf/1301.5804.pdf
  bundledCode: "#line 1 \"lib/Formal_Power_Series.hpp\"\n#include <vector>\n#include\
    \ <assert.h>\n#include <atcoder/modint>\n#include <atcoder/convolution>\n\nnamespace\
    \ tomo0608 {\n    template<typename mint>\n    struct formal_power_series : public\
    \ std::vector<mint> {\n        using FPS = formal_power_series;\n        using\
    \ std::vector<mint>::vector;\n        using std::vector<mint>::operator=;\n\n\
    \        void shrink() {\n            while (this->size() && this->back() == mint(0))this->pop_back();\n\
    \        }\n\n        FPS& operator+=(const FPS& rhs) {\n            if (rhs.size()\
    \ > this->size())this->resize(rhs.size());\n            for (int i = 0; i < (int)rhs.size();i++)(*this)[i]\
    \ += rhs[i];\n            return *this;\n        }\n\n        FPS& operator-=(const\
    \ FPS& rhs) {\n            if (rhs.size() > this->size())this->resize(rhs.size());\n\
    \            for (int i = 0; i < (int)rhs.size();i++)(*this)[i] -= rhs[i];\n \
    \           return *this;\n        }\n\n        FPS& operator+=(const mint& rhs)\
    \ {\n            if (this->empty())this->resize(1);\n            (*this)[0] +=\
    \ rhs;\n            return *this;\n        }\n\n        FPS& operator-=(const\
    \ mint& rhs) {\n            if (this->empty())this->resize(1);\n            (*this)[0]\
    \ -= rhs;\n            return *this;\n        }\n\n        FPS& operator*=(const\
    \ mint& rhs) {\n            for (auto& e : *this)e *= rhs;\n            return\
    \ *this;\n        }\n\n        FPS& operator*=(const FPS& rhs) {\n           \
    \ *this = atcoder::convolution((*this), rhs);\n            return *this;\n   \
    \     }\n\n        FPS& operator/=(const mint& c) {\n            assert(c != mint(0));\n\
    \            *this *= c.inv();\n            return *this;\n        }\n\n     \
    \   FPS& operator/=(const FPS& rhs) {\n            *this *= rhs.inv();\n     \
    \       this->resize(rhs.size());\n            return *this;\n        }\n\n  \
    \      friend FPS operator+(const FPS& lhs, const FPS& rhs) {\n            return\
    \ FPS(lhs) += rhs;\n        }\n        friend FPS operator+(const FPS& lhs, const\
    \ mint& rhs) {\n            return FPS(lhs) += rhs;\n        }\n\n        friend\
    \ FPS operator-(const FPS& lhs, const FPS& rhs) {\n            return FPS(lhs)\
    \ -= rhs;\n        }\n\n        friend FPS operator-(const FPS& lhs, const mint&\
    \ rhs) {\n            return FPS(lhs) -= rhs;\n        }\n\n        friend FPS\
    \ operator*(const FPS& lhs, const FPS& rhs) {\n            return FPS(lhs) *=\
    \ rhs;\n        }\n\n        friend FPS operator*(const FPS& lhs, const mint&\
    \ rhs) {\n            return FPS(lhs) *= rhs;\n        }\n\n        friend FPS\
    \ operator/(const FPS& lhs, const mint& rhs) {\n            return FPS(lhs) /=\
    \ rhs;\n        }\n\n        FPS inv(int deg = -1) const {\n            assert(this->front()\
    \ != mint(0));\n            if (deg == -1)deg = this->size();\n            FPS\
    \ res = { this->front().inv() };\n            for (int d = 1; d < deg; d <<= 1)\
    \ {\n                FPS f(2 * d), g(2 * d);\n                for (int j = 0;\
    \ j < std::min((int)this->size(), 2 * d); j++)f[j] = (*this)[j];\n           \
    \     for (int j = 0; j < d; j++)g[j] = res[j];\n\n                atcoder::internal::butterfly(f);\n\
    \                atcoder::internal::butterfly(g);\n\n                for (int\
    \ j = 0; j < 2 * d; j++)f[j] *= g[j];\n\n                atcoder::internal::butterfly_inv(f);\n\
    \                f /= 2 * d;\n\n                for (int j = 0; j < d; j++) {\n\
    \                    f[j] = f[j + d];\n                    f[j + d] = 0;\n   \
    \             }\n\n                atcoder::internal::butterfly(f);\n\n      \
    \          for (int j = 0; j < 2 * d; j++)f[j] *= -g[j];\n\n                atcoder::internal::butterfly_inv(f);\n\
    \                f /= 2 * d;\n\n                for (int j = 0; j < d; j++)res.emplace_back(f[j]);\n\
    \            }\n            res.resize(deg);\n            return res;\n      \
    \  }\n\n        FPS operator-() const {\n            FPS res(*this);\n       \
    \     for (auto& e : res) e = -e;\n            return res;\n        }\n\n    \
    \    FPS derivative() const {\n            FPS res(this->begin() + 1, this->end());\n\
    \            res.emplace_back(0);\n            for (int j = 0; j < res.size();\
    \ j++)res[j] *= (j + 1);\n            return res;\n        }\n\n        FPS integral(bool\
    \ truncate = true) const {\n            FPS res(this->size() + 1 - truncate, 0);\n\
    \            for (int j = 0; j < this->size() - truncate; j++)res[j + 1] = (*this)[j]\
    \ / (j + 1);\n            return res;\n        }\n\n        FPS log() const {\n\
    \            FPS f = this->derivative();\n            f /= (*this);\n        \
    \    return f.integral();\n        }\n        // https://arxiv.org/pdf/1301.5804.pdf\n\
    \        FPS exp(int deg = -1) const {\n            assert(this->front() == mint(0));\n\
    \            if (deg == -1)deg = this->size();\n            FPS f = { 1 }, g =\
    \ { 1 };\n            for (int d = 1; d < deg; d <<= 1) {\n                FPS\
    \ f_next(f);\n                f_next.resize(2 * d, 0);\n                atcoder::internal::butterfly(f_next);\n\
    \n                g.resize(2 * d, 0);\n                atcoder::internal::butterfly(g);\n\
    \                for (int j = 0; j < 2 * d; j++)g[j] = 2 * g[j] - f_next[j] *\
    \ g[j] * g[j];\n                atcoder::internal::butterfly_inv(g);\n       \
    \         g /= 2 * d;\n                g.resize(d);\n\n                FPS q(2\
    \ * d);\n                for (int j = 0; j < d && j < this->size() - 1; j++)q[j]\
    \ = (*this)[j + 1] * (j + 1);\n\n                FPS w(2 * d);\n             \
    \   FPS G(g);\n                G.resize(2 * d, 0);\n                atcoder::internal::butterfly(G);\n\
    \                for (int j = 0; j < 2 * d; j++)w[j] = f_next[j] * G[j];\n   \
    \             atcoder::internal::butterfly_inv(w);\n                w /= 2 * d;\n\
    \n                for (int j = 0; j < d; j++) {\n                    w[j] = w[j\
    \ + d];\n                    w[j + d] = 0;\n                }\n\n            \
    \    atcoder::internal::butterfly(w);\n                atcoder::internal::butterfly(q);\n\
    \                for (int j = 0; j < 2 * d; j++)w[j] *= q[j];\n              \
    \  atcoder::internal::butterfly_inv(w);\n                w /= 2 * d;\n\n     \
    \           FPS df(f.derivative());\n                df.resize(2 * d, 0);\n  \
    \              atcoder::internal::butterfly(df);\n                for (int j =\
    \ 0;j < 2 * d;j++)df[j] *= G[j];\n                atcoder::internal::butterfly_inv(df);\n\
    \                df /= 2 * d;\n\n                for (int j = 0; j < d;j++) {\n\
    \                    w[j + d] = w[j];\n                    w[j] = 0;\n       \
    \         }\n                w -= df;\n\n                w = w.integral();\n\n\
    \                for (int j = 0; j < 2 * d && j < this->size(); j++)w[j] += (*this)[j];\n\
    \                for (int j = 0; j < d;j++) {\n                    w[j] = w[j\
    \ + d];\n                    w[j + d] = 0;\n                }\n              \
    \  atcoder::internal::butterfly(w);\n                for (int j = 0; j < 2 * d;\
    \ j++)f_next[j] *= w[j];\n                atcoder::internal::butterfly_inv(f_next);\n\
    \                f_next /= 2 * d;\n                f.resize(2 * d, 0);\n     \
    \           for (int j = 0; j < d; j++)f[j + d] = f_next[j];\n            }\n\
    \            f.resize(deg);\n            return f;\n        }\n\n        FPS pow(long\
    \ long m) const {\n            int n = this->size();\n            if (m == 0)\
    \ {\n                auto res = FPS(n, 0);\n                res[0] = 1;\n    \
    \            return res;\n            }\n            int l = std::find_if(this->begin(),\
    \ this->end(), [](mint x) {return x != mint(0);}) - this->begin();\n         \
    \   if (l == this->size() || (l && m >= (n + l - 1) / l))return FPS(n, 0);\n\n\
    \            FPS res(this->begin() + l, this->end());\n            mint c = (*this)[l];\n\
    \            res /= c;\n            res.resize(n, 0);\n            res = (res.log()\
    \ * mint(m)).exp();\n            res.erase(res.begin() + (n - m * l), res.end());\n\
    \            res *= c.pow(m);\n            std::reverse(res.begin(), res.end());\n\
    \            res.resize(n, 0);\n            std::reverse(res.begin(), res.end());\n\
    \            return res;\n        }\n\n    };\n} // namespace tomo0608\n"
  code: "#include <vector>\n#include <assert.h>\n#include <atcoder/modint>\n#include\
    \ <atcoder/convolution>\n\nnamespace tomo0608 {\n    template<typename mint>\n\
    \    struct formal_power_series : public std::vector<mint> {\n        using FPS\
    \ = formal_power_series;\n        using std::vector<mint>::vector;\n        using\
    \ std::vector<mint>::operator=;\n\n        void shrink() {\n            while\
    \ (this->size() && this->back() == mint(0))this->pop_back();\n        }\n\n  \
    \      FPS& operator+=(const FPS& rhs) {\n            if (rhs.size() > this->size())this->resize(rhs.size());\n\
    \            for (int i = 0; i < (int)rhs.size();i++)(*this)[i] += rhs[i];\n \
    \           return *this;\n        }\n\n        FPS& operator-=(const FPS& rhs)\
    \ {\n            if (rhs.size() > this->size())this->resize(rhs.size());\n   \
    \         for (int i = 0; i < (int)rhs.size();i++)(*this)[i] -= rhs[i];\n    \
    \        return *this;\n        }\n\n        FPS& operator+=(const mint& rhs)\
    \ {\n            if (this->empty())this->resize(1);\n            (*this)[0] +=\
    \ rhs;\n            return *this;\n        }\n\n        FPS& operator-=(const\
    \ mint& rhs) {\n            if (this->empty())this->resize(1);\n            (*this)[0]\
    \ -= rhs;\n            return *this;\n        }\n\n        FPS& operator*=(const\
    \ mint& rhs) {\n            for (auto& e : *this)e *= rhs;\n            return\
    \ *this;\n        }\n\n        FPS& operator*=(const FPS& rhs) {\n           \
    \ *this = atcoder::convolution((*this), rhs);\n            return *this;\n   \
    \     }\n\n        FPS& operator/=(const mint& c) {\n            assert(c != mint(0));\n\
    \            *this *= c.inv();\n            return *this;\n        }\n\n     \
    \   FPS& operator/=(const FPS& rhs) {\n            *this *= rhs.inv();\n     \
    \       this->resize(rhs.size());\n            return *this;\n        }\n\n  \
    \      friend FPS operator+(const FPS& lhs, const FPS& rhs) {\n            return\
    \ FPS(lhs) += rhs;\n        }\n        friend FPS operator+(const FPS& lhs, const\
    \ mint& rhs) {\n            return FPS(lhs) += rhs;\n        }\n\n        friend\
    \ FPS operator-(const FPS& lhs, const FPS& rhs) {\n            return FPS(lhs)\
    \ -= rhs;\n        }\n\n        friend FPS operator-(const FPS& lhs, const mint&\
    \ rhs) {\n            return FPS(lhs) -= rhs;\n        }\n\n        friend FPS\
    \ operator*(const FPS& lhs, const FPS& rhs) {\n            return FPS(lhs) *=\
    \ rhs;\n        }\n\n        friend FPS operator*(const FPS& lhs, const mint&\
    \ rhs) {\n            return FPS(lhs) *= rhs;\n        }\n\n        friend FPS\
    \ operator/(const FPS& lhs, const mint& rhs) {\n            return FPS(lhs) /=\
    \ rhs;\n        }\n\n        FPS inv(int deg = -1) const {\n            assert(this->front()\
    \ != mint(0));\n            if (deg == -1)deg = this->size();\n            FPS\
    \ res = { this->front().inv() };\n            for (int d = 1; d < deg; d <<= 1)\
    \ {\n                FPS f(2 * d), g(2 * d);\n                for (int j = 0;\
    \ j < std::min((int)this->size(), 2 * d); j++)f[j] = (*this)[j];\n           \
    \     for (int j = 0; j < d; j++)g[j] = res[j];\n\n                atcoder::internal::butterfly(f);\n\
    \                atcoder::internal::butterfly(g);\n\n                for (int\
    \ j = 0; j < 2 * d; j++)f[j] *= g[j];\n\n                atcoder::internal::butterfly_inv(f);\n\
    \                f /= 2 * d;\n\n                for (int j = 0; j < d; j++) {\n\
    \                    f[j] = f[j + d];\n                    f[j + d] = 0;\n   \
    \             }\n\n                atcoder::internal::butterfly(f);\n\n      \
    \          for (int j = 0; j < 2 * d; j++)f[j] *= -g[j];\n\n                atcoder::internal::butterfly_inv(f);\n\
    \                f /= 2 * d;\n\n                for (int j = 0; j < d; j++)res.emplace_back(f[j]);\n\
    \            }\n            res.resize(deg);\n            return res;\n      \
    \  }\n\n        FPS operator-() const {\n            FPS res(*this);\n       \
    \     for (auto& e : res) e = -e;\n            return res;\n        }\n\n    \
    \    FPS derivative() const {\n            FPS res(this->begin() + 1, this->end());\n\
    \            res.emplace_back(0);\n            for (int j = 0; j < res.size();\
    \ j++)res[j] *= (j + 1);\n            return res;\n        }\n\n        FPS integral(bool\
    \ truncate = true) const {\n            FPS res(this->size() + 1 - truncate, 0);\n\
    \            for (int j = 0; j < this->size() - truncate; j++)res[j + 1] = (*this)[j]\
    \ / (j + 1);\n            return res;\n        }\n\n        FPS log() const {\n\
    \            FPS f = this->derivative();\n            f /= (*this);\n        \
    \    return f.integral();\n        }\n        // https://arxiv.org/pdf/1301.5804.pdf\n\
    \        FPS exp(int deg = -1) const {\n            assert(this->front() == mint(0));\n\
    \            if (deg == -1)deg = this->size();\n            FPS f = { 1 }, g =\
    \ { 1 };\n            for (int d = 1; d < deg; d <<= 1) {\n                FPS\
    \ f_next(f);\n                f_next.resize(2 * d, 0);\n                atcoder::internal::butterfly(f_next);\n\
    \n                g.resize(2 * d, 0);\n                atcoder::internal::butterfly(g);\n\
    \                for (int j = 0; j < 2 * d; j++)g[j] = 2 * g[j] - f_next[j] *\
    \ g[j] * g[j];\n                atcoder::internal::butterfly_inv(g);\n       \
    \         g /= 2 * d;\n                g.resize(d);\n\n                FPS q(2\
    \ * d);\n                for (int j = 0; j < d && j < this->size() - 1; j++)q[j]\
    \ = (*this)[j + 1] * (j + 1);\n\n                FPS w(2 * d);\n             \
    \   FPS G(g);\n                G.resize(2 * d, 0);\n                atcoder::internal::butterfly(G);\n\
    \                for (int j = 0; j < 2 * d; j++)w[j] = f_next[j] * G[j];\n   \
    \             atcoder::internal::butterfly_inv(w);\n                w /= 2 * d;\n\
    \n                for (int j = 0; j < d; j++) {\n                    w[j] = w[j\
    \ + d];\n                    w[j + d] = 0;\n                }\n\n            \
    \    atcoder::internal::butterfly(w);\n                atcoder::internal::butterfly(q);\n\
    \                for (int j = 0; j < 2 * d; j++)w[j] *= q[j];\n              \
    \  atcoder::internal::butterfly_inv(w);\n                w /= 2 * d;\n\n     \
    \           FPS df(f.derivative());\n                df.resize(2 * d, 0);\n  \
    \              atcoder::internal::butterfly(df);\n                for (int j =\
    \ 0;j < 2 * d;j++)df[j] *= G[j];\n                atcoder::internal::butterfly_inv(df);\n\
    \                df /= 2 * d;\n\n                for (int j = 0; j < d;j++) {\n\
    \                    w[j + d] = w[j];\n                    w[j] = 0;\n       \
    \         }\n                w -= df;\n\n                w = w.integral();\n\n\
    \                for (int j = 0; j < 2 * d && j < this->size(); j++)w[j] += (*this)[j];\n\
    \                for (int j = 0; j < d;j++) {\n                    w[j] = w[j\
    \ + d];\n                    w[j + d] = 0;\n                }\n              \
    \  atcoder::internal::butterfly(w);\n                for (int j = 0; j < 2 * d;\
    \ j++)f_next[j] *= w[j];\n                atcoder::internal::butterfly_inv(f_next);\n\
    \                f_next /= 2 * d;\n                f.resize(2 * d, 0);\n     \
    \           for (int j = 0; j < d; j++)f[j + d] = f_next[j];\n            }\n\
    \            f.resize(deg);\n            return f;\n        }\n\n        FPS pow(long\
    \ long m) const {\n            int n = this->size();\n            if (m == 0)\
    \ {\n                auto res = FPS(n, 0);\n                res[0] = 1;\n    \
    \            return res;\n            }\n            int l = std::find_if(this->begin(),\
    \ this->end(), [](mint x) {return x != mint(0);}) - this->begin();\n         \
    \   if (l == this->size() || (l && m >= (n + l - 1) / l))return FPS(n, 0);\n\n\
    \            FPS res(this->begin() + l, this->end());\n            mint c = (*this)[l];\n\
    \            res /= c;\n            res.resize(n, 0);\n            res = (res.log()\
    \ * mint(m)).exp();\n            res.erase(res.begin() + (n - m * l), res.end());\n\
    \            res *= c.pow(m);\n            std::reverse(res.begin(), res.end());\n\
    \            res.resize(n, 0);\n            std::reverse(res.begin(), res.end());\n\
    \            return res;\n        }\n\n    };\n} // namespace tomo0608"
  dependsOn: []
  isVerificationFile: false
  path: lib/Formal_Power_Series.hpp
  requiredBy: []
  timestamp: '2023-04-15 20:13:18+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/Polynomial/Log.test.cpp
  - test/Polynomial/Exp.test.cpp
  - test/Polynomial/Inv.test.cpp
documentation_of: lib/Formal_Power_Series.hpp
layout: document
redirect_from:
- /library/lib/Formal_Power_Series.hpp
- /library/lib/Formal_Power_Series.hpp.html
title: lib/Formal_Power_Series.hpp
---
