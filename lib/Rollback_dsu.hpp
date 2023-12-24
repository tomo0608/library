#pragma once
#include<vector>
#include<utility>

namespace tomo0608 {

    struct Rollback_dsu {
    public:
        Rollback_dsu() : _n(0) {}
        Rollback_dsu(int n) : _n(n), _inner_snap(0), parent_or_size(n, -1) {}

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
            history.emplace_back(x, parent_or_size[x]);
            history.emplace_back(y, parent_or_size[y]);
            if (x == y)return true;
            if (-parent_or_size[x] < -parent_or_size[y])std::swap(x, y);
            parent_or_size[x] += parent_or_size[y];
            parent_or_size[y] = x;
            return false;
        }

        int size(int a) {
            assert(0 <= a && a < _n);
            return -parent_or_size[find(a)];
        }

        void undo() {
            parent_or_size[history.back().first] = history.back().second;
            history.pop_back();
            parent_or_size[history.back().first] = history.back().second;
            history.pop_back();
        }
        void snapshot() { _inner_snap = int(history.size() >> 1); }

        int get_state() { return int(history.size() >> 1); }

        void rollback(int state = -1) {
            if (state == -1) state = _inner_snap;
            state <<= 1;
            assert(state <= (int)history.size());
            while (state < (int)history.size()) undo();
        }

    private:
        int _n;
        std::vector<int> parent_or_size;
        std::vector<std::pair<int, int>> history;
        int _inner_snap;
    };
}