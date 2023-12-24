#pragma once
#include<vector>
#include<cmath>
#include<numeric>
#include<algorithm>

namespace tomo0608 {
    struct Mo {
        int n;
        std::vector< std::pair< int, int > > lr;

        explicit Mo(int n) : n(n) {}

        void add(int l, int r) { /* [l, r) */
            lr.emplace_back(l, r);
        }

        template< typename AddLeftQueryType, typename AddRightQueryType, typename EraseLeftQueryType, typename EraseRightQueryType, typename OutpotQueryType >
        void build(const AddLeftQueryType& add_left, const AddRightQueryType& add_right, const EraseLeftQueryType& erase_left, const EraseRightQueryType& erase_right, const OutpotQueryType& out) {
            int q = (int)lr.size();
            int bs = n / std::min< int >(n, std::sqrt(q));
            std::vector< int > ord(q);
            std::iota(begin(ord), end(ord), 0);
            std::sort(begin(ord), end(ord), [&](int a, int b) {
                int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
                if (ablock != bblock) return ablock < bblock;
                return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;
                });
            int l = 0, r = 0;
            for (auto idx : ord) {
                while (l > lr[idx].first) add_left(--l);
                while (r < lr[idx].second) add_right(r++);
                while (l < lr[idx].first) erase_left(l++);
                while (r > lr[idx].second) erase_right(--r);
                out(idx);
            }
        }

        template< typename AddQueryType, typename EraseQueryType, typename OutpotQueryType >
        void build(const AddQueryType& add, const EraseQueryType& erase, const OutpotQueryType& out) {
            build(add, add, erase, erase, out);
        }
    };
}