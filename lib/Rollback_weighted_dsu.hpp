#pragma once
#include<vector>
#include<utility>
#include<cassert>

namespace tomo0608 {
    template<class T>
    concept CommutativeGroup = requires(T a, T b) {
        {a + b}->std::convertible_to<T>;
        {a - b}->std::convertible_to<T>;
        T();
    };

    template<CommutativeGroup T = long long>
    struct Rollback_weighted_dsu {
    public:
        Rollback_weighted_dsu() : _n(0) {}
        Rollback_weighted_dsu(int n) : Rollback_weighted_dsu(std::vector<T>(n, {})) {}
        Rollback_weighted_dsu(std::vector<T> a) : _n(a.size()), _inner_snap(0), parent_or_size(_n, -1), weight(a) {}

        int find(int a) {
            assert(0 <= a && a < _n);
            if (parent_or_size[a] < 0)return a;
            return find(parent_or_size[a]); // without path compression
        }

        bool same(int a, int b) {
            assert(0 <= a && a < _n && 0 <= b && b < _n);
            return find(a) == find(b);
        }

        bool merge(int a, int b) {
            assert(0 <= a && a < _n && 0 <= b && b < _n);
            int x = find(a), y = find(b);
            if (-parent_or_size[x] < -parent_or_size[y])std::swap(x, y);
            history.emplace_back(x, parent_or_size[x]);
            history.emplace_back(y, parent_or_size[y]);
            if (x == y)return false;
            parent_or_size[x] += parent_or_size[y];
            parent_or_size[y] = x;
            weight[x] = weight[x] + weight[y];
            return true;
        }

        int size(int a) {
            assert(0 <= a && a < _n);
            return -parent_or_size[find(a)];
        }

        T get_leaders_weight(int a) {
            assert(0 <= a && a < _n);
            return weight[find(a)];
        }

        void add_weight(int a, T w){
            assert(0 <= a && a < _n);
            while(a >= 0){
                weight[a] = weight[a] + w;
                a = parent_or_size[a];
            }
        }

        void undo() {
            auto [y, py] = history.back();history.pop_back();
            auto [x, px] = history.back();history.pop_back();
            if(parent_or_size[x] != px)weight[x] = weight[x] - weight[y];
            parent_or_size[x] = px;
            parent_or_size[y] = py;
        }
        void snapshot() { _inner_snap = int(history.size() >> 1); }

        int get_state() { return int(history.size() >> 1); }

        void rollback(int state = -1) {
            if (state == -1) state = _inner_snap;
            state <<= 1;
            assert(state <= (int)history.size());
            while (state < (int)history.size()) undo();
        }

    //private:
        int _n;
        std::vector<int> parent_or_size;
        std::vector<T> weight;
        std::vector<std::pair<int,int>> history;
        int _inner_snap;
    };
} // namespace tomo0608
