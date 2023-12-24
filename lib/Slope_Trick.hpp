#pragma once
#include<vector>
#include<queue>
#include<cstddef>
#include<limits>

namespace tomo0608 {

    template<typename T>
    struct SlopeTrick {
        const T INF = std::numeric_limits<T>::max() / 3;

        T min_f; // fの最小値
        std::priority_queue<T, std::vector<T>, std::less<> > L; // 傾きが0以下の部分について傾きの変化点全体の多重集合
        std::priority_queue<T, std::vector<T>, std::greater<> > R; // 傾きが0以上の部分について傾きの変化点全体の多重集合
        T add_l, add_r;// l,rへの一律加算

    private:
        void push_R(const T& a) {
            R.push(a - add_r);
        }

        void push_L(const T& a) {
            L.push(a - add_l);
        }

        T top_R() const {
            if (R.empty())return INF;
            return R.top() + add_r;
        }

        T top_L() const {
            if (L.empty())return -INF;
            return L.top() + add_l;
        }

        T pop_R() {
            T v = top_R();
            if (!R.empty())R.pop();
            return v;
        }

        T pop_L() {
            T v = top_L();
            if (!L.empty())L.pop();
            return v;
        }

        size_t size() {
            return L.size() + R.size();
        }

    public:
        SlopeTrick() : min_f(0), add_l(0), add_r(0) {}

        struct Query {
            T lx, rx, min_f;
        };

        Query query() const { // return min f(x)
            return (Query) { top_L(), top_R(), min_f };
        }

        T get_min() const { return min_f; }

        std::pair<T, T> min_range() const { return std::pair<T, T>{L.top() + add_l, R.top() + add_r}; }

        void add_all(const T& a) { // f(x) += a
            min_f += a;
        }

        void add_a_minus_x(const T& a) { // f(x) += max(a-x, 0) \_
            min_f += std::max(T(0), a - top_R());
            push_R(a);
            push_L(pop_R());
        }

        void add_x_minus_a(const T& a) { // f(x) += max(x-a, 0) _/
            min_f += std::max(T(0), top_L() - a);
            push_L(a);
            push_R(pop_L());
        }

        void add_abs(const T& a) { // f(x) += abs(x-a) \/
            add_a_minus_x(a);
            add_x_minus_a(a);
        }

        void clear_right() { // f_{new}(x) = min_(y <= x)f(y), \/ -> \_
            while (!R.empty())R.pop();
        }

        void clear_left() { // f_{new}(x) = min_(y >= x)f(y), \/ -> _/
            while (!L.empty())L.pop();
        }

        void shift(const T& a, const T& b) { // f_{new}(x) = min_{x-b <= y <= x-a}f(y)
            assert(a <= b);
            add_l += a;
            add_r += b;
        }

        void shift(const T& a) { // f_{new}(x) = f(x - a)
            shift(a, a);
        }

        void get(const T& x) { // f(x)を求めるが, 全てが破壊される
            T ret = min_f;
            while (!L.empty()) {
                ret += max(T(0), pop_L() - x);
            }
            while (!R.empty()) {
                ret += max(T(0), x - pop_R());
            }
            return ret;
        }

        void merge(SlopeTrick& other_st) { //mergeを行うが, stは破壊される
            if (other_st.size() > size()) {
                std::swap(other_st.L, L);
                std::swap(other_st.R, R);
                std::swap(other_st.add_l, add_l);
                std::swap(other_st.add_r, add_r);
                std::swap(other_st.min_f, min_f);
            }
            while (!other_st.R.empty())add_x_minus_a(other_st.pop_R());
            while (!other_st.L.empty())add_a_minus_x(other_st.pop_L());
            min_f += other_st.min_f;
        }
    };
} // namespace tomo0608