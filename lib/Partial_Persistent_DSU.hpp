#include<vector>
#include<cassert>


namespace tomo0608 {
    struct pp_dsu {
    public:
        pp_dsu() : _n(0) {}
        pp_dsu(int n) : _n(n), parent_or_size(n, -1), num(n), time(n, 1e9) {
            for (int i = 0; i < _n; ++i)num[i].emplace_back(-1, -1);
        }
        // return parent of x in t
        int find(int a, int t) {
            assert(0 <= a && a < _n);
            assert(0 <= t && t < 1e9);
            if (time[a] == -1 || t < time[a])return a;
            return find(parent_or_size[a], t);
        }

        bool same(int a, int b, int t) {
            assert(0 <= a && a < _n && 0 <= b && b < _n);
            return find(a, t) == find(b, t);
        }

        bool merge(int a, int b, int t) {
            assert(0 <= a && a < _n && 0 <= b && b < _n);
            assert(0 <= t && t < 1e9);
            int x = find(a, t), y = find(b, t);
            if (x == y)return true;
            if (-parent_or_size[x] < -parent_or_size[y])std::swap(x, y);
            parent_or_size[x] += parent_or_size[y];
            parent_or_size[y] = x;
            time[y] = t;
            num[x].emplace_back(t, parent_or_size[x]);
            return false;
        }

        int size(int a, int t) {
            a = find(a, t);
            return -std::prev(std::lower_bound(num[a].begin(), num[a].end(), std::make_pair(t, 0)))->second;
        }
    private:
        int _n; // number of nodes
        std::vector<int> parent_or_size; // return parent if nonnegative, otherwise return -size
        std::vector<int> time; //time[x]: time x is no longer root
        std::vector<std::vector<std::pair<int, int>>> num; // vector (t, nodes)
    };
}