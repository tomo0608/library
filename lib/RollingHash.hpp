#pragma once
#include "utility.hpp"
#include <atcoder/modint>
namespace tomo0608 {
namespace hash_impl {
static constexpr unsigned long mod = (1ULL << 61) - 1;
struct modint {
    modint() = default;
    modint(unsigned long long x) {
        x = (x >> 61) + (x & mod);
        if(x >= mod)
            x -= mod;
        _x = x;
    }
    unsigned long long val() const { return _x; }
    modint &operator+=(const modint &rhs) {
        _x += rhs._x;
        if(_x >= mod)
            _x -= mod;
        return *this;
    }
    modint &operator-=(const modint &rhs) {
        _x += mod - rhs._x;
        if(_x >= mod)
            _x -= mod;
        return *this;
    }
    modint &operator*=(const modint &rhs) {
        __uint128_t x = __uint128_t(_x) * rhs._x;
        _x = (x >> 61) + (x & mod);
        if(_x >= mod)
            _x -= mod;
        return *this;
    }
    modint &operator/=(const modint &rhs) { return *this *= rhs.inv(); }
    modint operator-() const { return modint() - *this; }
    modint pow(unsigned long long n) const {
        modint ret(1), mul(*this);
        while(n) {
            if(n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    modint inv() const { return pow(mod - 2); }

    friend modint operator+(const modint &lhs, const modint &rhs) {
        return modint(lhs) += rhs;
    }
    friend modint operator-(const modint &lhs, const modint &rhs) {
        return modint(lhs) -= rhs;
    }
    friend modint operator*(const modint &lhs, const modint &rhs) {
        return modint(lhs) *= rhs;
    }
    friend modint operator/(const modint &lhs, const modint &rhs) {
        return modint(lhs) /= rhs;
    }
    friend bool operator==(const modint &lhs, const modint &rhs) {
        return lhs._x == rhs._x;
    }
    friend bool operator!=(const modint &lhs, const modint &rhs) {
        return lhs._x != rhs._x;
    }
    friend std::ostream &operator<<(std::ostream &os, const modint &m) {
        return os << m._x;
    }

  private:
    unsigned long long _x;
};
modint base(rng(2, mod - 1));
std::vector<modint> basepow = {1};

modint get_pow(int n) {
    while(basepow.size() <= n) {
        basepow.push_back(basepow.back() * base);
    }
    return basepow[n];
}
} // namespace hash_impl
struct ReversibleRollingHash {
    using mint = hash_impl::modint;
    mint x, rx;
    int sz;

    ReversibleRollingHash() : x(0), rx(0), sz(0) {}
    ReversibleRollingHash(mint x) : x(x), rx(x), sz(1) {} // charにも対応する
    ReversibleRollingHash(mint x, mint rx, int sz) : x(x), rx(rx), sz(sz) {}

    ReversibleRollingHash operator+=(const ReversibleRollingHash &rhs) {
        return ReversibleRollingHash(
            x * hash_impl::get_pow(rhs.sz) + rhs.x,
            rx + hash_impl::get_pow(sz) * rhs.rx, sz + rhs.sz);
    }
    ReversibleRollingHash operator+(const ReversibleRollingHash &rhs) {
        return *this += rhs;
    }
    bool operator==(const ReversibleRollingHash &rhs) {
        return x == rhs.x and rx == rhs.rx and sz == rhs.sz;
    }
};
} // namespace tomo0608