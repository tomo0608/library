#pragma once
#include<vector>
#include<stack>
#include<cassert>

namespace tomo0608 {
    template<class Monoid, Monoid(*op)(Monoid, Monoid), Monoid(*e)()> struct SWAG {
        SWAG() :l(0), r(0), last_i(0), last_j(0), front(e()), v(0), back() {}
        explicit SWAG(std::vector<Monoid>& _v) :l(0), r(0), last_i(0), last_j(0), front(e()), v(_v.size()), back() {
            std::copy(_v.begin(), _v.end(), v.begin());
        }
        void push_back(const Monoid& c) {
            v.push_back(c);
        }
        int size() {
            return v.size();
        }
        Monoid fold(int i, int j) { //[l, r)
            assert(i < j && j <= v.size());
            assert(last_i <= i && last_j <= j);
            last_i = i, last_j = j;
            while (r < j)front = op(front, v[r++]);
            while (l < i) {
                if (back.empty()) {
                    Monoid tmp = e();
                    for (int u = r; u-- > l; ) {
                        tmp = op(v[u], tmp);
                        back.emplace(tmp);
                    }
                    front = e();
                }
                back.pop();
                ++l;
            }
            if (back.empty())return front;
            return op(back.top(), front);
        }
    private:
        std::vector<Monoid> v;
        Monoid front;
        std::stack<Monoid> back;
        int l, r, last_i, last_j;
    };
}// namespace tomo0608