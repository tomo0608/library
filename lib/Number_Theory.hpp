#pragma once
#include<vector>
#include<map>
#include<assert.h>
#include<cmath>
#include<set>
#include<atcoder/math>

namespace tomo0608 {
#define is_prime(n) atcoder::internal::is_prime_constexpr(n)

    std::map<long long, long long> prime_factorization(long long n) {
        std::map<long long, long long> res;
        n = abs(n);
        assert(n > 1);
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int num = 0;
                while (n % i == 0) {
                    num++;
                    n /= i;
                }
                res[i] = num;
            }
        }
        if (n != 1)res[n] = 1;
        return res;
    }

    class Osa_k {
    public:
        const int MAX_N;
        std::vector<int> min_prime;
        Osa_k(int size) : MAX_N(size), min_prime(size + 1) {
            if (MAX_N < 2)return;
            std::vector<int> primes{ 2, 3 };
            for (int i = 2; i <= MAX_N; i += 2)min_prime[i] = 2;
            for (int i = 3; i <= MAX_N; i += 6)min_prime[i] = 3;
            for (int i = 5, d = 4; i <= MAX_N; i += d = 6 - d) {
                if (!min_prime[i]) {
                    min_prime[i] = i;
                    primes.emplace_back(i);
                }
                for (int j = 2; j < (int)primes.size() && i * primes[j] <= MAX_N; j++) {
                    min_prime[i * primes[j]] = primes[j];
                    if (primes[j] == min_prime[i])break;
                }
            }
        }
        std::vector<std::pair<int, int>> factorization(int n) {
            assert(0 < n && n <= MAX_N);
            std::vector<std::pair<int, int>> res;
            while (n > 1) {
                int p = min_prime[n];
                int num = 0;
                while (min_prime[n] == p) {
                    num++;
                    n /= p;
                }
                res.emplace_back(p, num);
            }
            return res;
        }
    };


    std::vector<int> prime_enumerate(int N) {
        std::vector<bool> sieve(N / 3 + 1, 1);
        for (int p = 5, d = 4, i = 1, sqn = std::sqrt(N); p <= sqn; p += d = 6 - d, i++) {
            if (!sieve[i]) continue;
            for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p, qe = sieve.size();q < qe; q += r = s - r)sieve[q] = 0;
        }
        std::vector<int> ret{ 2, 3 };
        for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)
            if (sieve[i]) ret.push_back(p);
        while (!ret.empty() && ret.back() > N) ret.pop_back();
        return ret;
    }

    template<class T>
    void div_zeta(std::vector<T>& a) {
        std::vector<int> sieve = prime_enumerate((int)a.size() - 1);
        for (auto& p : sieve)for (int i = 1; i * p < a.size(); i++)a[i * p] += a[i];
    }
    template<class T>
    void div_mobius(std::vector<T>& a) {
        std::vector<int> sieve = prime_enumerate((int)a.size() - 1);
        for (auto& p : sieve)for (int i = ((int)a.size() - 1) / p; i > 0; i--)a[i * p] -= a[i];
    }
    template<class T>
    void mul_zeta(std::vector<T>& a) {
        std::vector<int> sieve = prime_enumerate((int)a.size() - 1);
        for (auto& p : sieve)for (int i = ((int)a.size() - 1) / p; i > 0; i--)a[i] += a[i * p];
    }
    template<class T>
    void mul_mobius(std::vector<T>& a) {
        std::vector<int> sieve = prime_enumerate((int)a.size() - 1);
        for (auto& p : sieve)for (int i = 1; i * p < a.size(); i++)a[i] -= a[i * p];
    }

    template<class T>
    std::vector<T> gcd_convolution(std::vector<T> a, std::vector<T> b) {
        mul_zeta(a);
        mul_zeta(b);
        for (int i = 0; i < a.size(); i++)a[i] *= b[i];
        mul_mobius(a);
        return a;
    }
    template<class T>
    std::vector<T> lcm_convolution(std::vector<T> a, std::vector<T> b) {
        div_zeta(a);
        div_zeta(b);
        for (int i = 0; i < a.size(); i++)a[i] *= b[i];
        div_mobius(a);
        return a;
    }

    long long euler_phi(long long n) {
        long long res = n;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                res -= res / i;
                while (n % i == 0)n /= i;
            }
        }
        if (n > 1)res -= res / n;
        return res;
    }

#if __cplusplus >= 201703L
    template<class Set,
        class Monoid,
        auto action,
        auto composition,
        auto id>
    long long discrete_logarithm(Monoid f, Set s, Set t, long long MAX_N) {// return the smallest integer n lower than MAX_N such that f^n s = t if exists, otherwise -1
        static_assert(std::is_convertible_v<decltype(action),
            std::function<Set(Monoid, Set)>>, "action must work as Set(Monoid, Set)");
        static_assert(std::is_convertible_v<decltype(composition),
            std::function<Monoid(Monoid, Monoid)>>, "composition must work as Monoid(Monoid, Monoid)");
        static_assert(std::is_convertible_v<decltype(id),
            std::function<Monoid()>>, "id must work as Monoid()");

#else
    template<class Set,
        class Monoid,
        Set(*action)(Monoid, Set),
        Monoid(*composition)(Monoid, Monoid),
        Monoid(*id)()>
    long long discrete_logarithm(Monoid f, Set s, Set t, long long MAX_N) {

#endif
        if (s == t)return 0;
        long long SQRT_N = sqrt(MAX_N) + 1;
        std::set<Set> T;
        Set f_t = t;
        for (int i = 1; i <= SQRT_N; i++) {
            f_t = action(f, f_t);
            T.emplace(f_t);
        }
        Monoid f_m = id();

        {
            long long n = SQRT_N;
            Monoid _f = f;
            while (n > 0) {
                if (n & 1)f_m = composition(f_m, _f);
                _f = composition(_f, _f);
                n >>= 1;
            }
        }

        int num_of_failures = 0;
        Set pre_s = s;
        for (int k = 1; k <= SQRT_N; k++) {
            Set now_s = action(f_m, pre_s);
            if (T.count(now_s)) {
                Set lhs = pre_s;
                for (int i = 0; i < SQRT_N; i++, lhs = action(f, lhs)) {
                    if (lhs == t)return SQRT_N * (k - 1) + i;
                }
                num_of_failures++;
                if (num_of_failures == 2)return -1;
            }
            std::swap(pre_s, now_s);
        }
        return -1;
    };
} // namespace tomo0608
