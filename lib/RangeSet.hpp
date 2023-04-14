#include<set>
#include<vector>
#include<limits>

namespace tomo0608 {

    template<class T = long long>
    struct RangeSet {
    public:
        const T inf = std::numeric_limits<T>::max() / 2;
        std::set<std::pair<T, T>> st;

        RangeSet() {
            st.emplace(-inf - 1, -inf);
            st.emplace(inf, inf + 1);
        }

        int size() const { return st.size() - 2; }

        std::vector<std::pair<T, T>> get_all_sections() const {
            auto l = std::next(st.begin()), r = std::prev(st.end());
            std::vector<std::pair<T, T>> ret;
            while (l != r) {
                ret.emplace_back(*l);
                l = std::next(l);
            }
            return ret;
        }

        bool is_covered(const T l, const T r) const {
            auto it = std::prev(st.upper_bound({ l, inf }));
            return (it->first <= l && r <= it->second);
        }

        bool is_covered(const T x) const { return is_covered(x, x + 1); }

        std::pair<T, T> is_covered_by(const T l, const T r) const {
            auto it = std::prev(st.upper_bound({ l, inf }));
            if (it->first <= l && r <= it->second)return *it;
            return { -inf, -inf };
        }

        std::pair<T, T> is_covered_by(const T x) const { return is_covered_by(x, x + 1); }

        T insert_section(T l, T r) {
            auto it = std::prev(st.upper_bound({ l, -inf }));
            T len = 0;
            if (it->first <= l && r <= it->second)return len;

            T nxtleft = l;
            if (it->first <= l && l <= it->second) {
                l = it->first;
                nxtleft = it->second;
                it = st.erase(it);
            }
            else {
                it = next(it);
            }

            while (r > it->second) {
                len += it->first - nxtleft;
                nxtleft = it->second;
                it = st.erase(it);
            }

            if (it->first <= r) {
                len += it->first - nxtleft;
                r = it->second;
                st.erase(it);
            }
            else {
                len += r - nxtleft;
            }
            st.emplace(l, r);
            return len;
        }

        T insert(T x) { return insert_section(x, x + 1); }

        T insert_length(T l, T d) {
            auto it = std::prev(st.upper_bound({ l, -inf }));

            T nxtleft = l;
            if (it->first <= l and l <= it->second) {
                l = it->first;
                nxtleft = it->second;
                it = st.erase(it);
            }
            else {
                it = std::next(it);
            }

            T r = l, lastr = l;
            while (d >= it->first - nxtleft) {
                d -= it->first - nxtleft;
                lastr = it->first;
                nxtleft = it->second;
                it = st.erase(it);
            }
            r = nxtleft + d;
            if (d > 0) lastr = nxtleft + d;

            st.emplace(l, r);
            return lastr;
        }

        T erase_section(const T l, const T r) {
            auto it = std::prev(st.upper_bound({ l, -inf }));

            if (it->first <= l && r <= it->second) {
                if (it->first < l)st.emplace(it->first, l);
                if (r < it->second)st.emplace(r, it->second);
                st.erase(it);
                return r - l;
            }

            T len = 0;

            if (it->first <= l && l < it->second) {
                len += it->second - l;
                if (it->first < l)st.emplace(it->first, l);
                it = st.erase(it);
            }
            else {
                it = std::next(it);
            }

            while (it->second <= r) {
                len += it->second - it->first;
                it = st.erase(it);
            }
            if (it->first < r) {
                len += r - it->first;
                st.emplace(r, it->second);
                st.erase(it);
            }
            return len;
        }

        T erase(const T x) { return erase_section(x, x + 1); }

        T mex(const T x = 0) const {
            auto it = std::prev(st.upper_bound({ x, -inf }));
            if (it->first <= x && x < it->second)return it->second;
            return x;
        }

        T sum(T l = -std::numeric_limits<T>::max() / 2, T r = std::numeric_limits<T>::max() / 2) {
            auto it = std::prev(st.upper_bound({ l, -inf }));
            if (it->first <= l && r <= it->second)return r - l;

            T len = 0;
            if (it->first <= l && l < it->second)len += it->second - l;
            it = std::next(it);
            while (it->second <= r) {
                len += it->second - it->first;
                it = std::next(it);
            }
            if (it->first < r)len += r - it->first;
            return len;
        }
    };
}