#pragma once
#include<vector>

template<class mint>
mint interpolation(const std::vector<mint>& y, long long T) {
    // y = [f(0),\ldots, f(n)], find f(T)
    int n = y.size() - 1;
    if (T <= n)return y[T];
    mint ret = 0;
    std::vector<mint> L(n + 1, 1), R(n + 1, 1);
    for (int i = 0; i < n; i++)L[i + 1] = L[i] * (T - i);
    for (int i = n; i > 0; i--)R[i - 1] = R[i] * (T - i);
    std::vector<mint> fact(n + 1, 1), ifact(n + 1, 1);
    for (int i = 1; i <= n; i++)fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i > 0; i--)ifact[i - 1] = ifact[i] * i;
    for (int i = 0; i <= n; i++) {
        mint tmp = y[i] * L[i] * R[i] * ifact[i] * ifact[n - i];
        if ((n - i) & 1)ret -= tmp;
        else ret += tmp;
    }
    return ret;
}