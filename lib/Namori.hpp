#pragma once
#include<vector>
#include<queue>
namespace tomo0608 {

    struct Namori {
    public:
        std::vector<std::vector<int>> G, graph;
        std::vector<int> loop;

        Namori(int n) : _n(n), G(n), deg(n, 0), flag(n, false) {}

        void add_edge(int u, int v, bool minus_one = true) {
            if (minus_one)u--, v--;
            G[u].emplace_back(v), G[v].emplace_back(u);
            deg[u]++, deg[v]++;
        }

        void build() {
            graph.resize(_n);
            std::queue<int> que;

            for (int i = 0; i < _n; i++) {
                if (deg[i] == 1) { // leaf
                    que.emplace(i);
                    flag[i] = true;
                }
            }

            while (!que.empty()) {
                int now = que.front();
                que.pop();
                for (int to : G[now]) {
                    if (flag[to])continue;
                    deg[to]--;
                    graph[to].emplace_back(now);
                    graph[now].emplace_back(to);
                    if (deg[to] > 1)continue;
                    que.emplace(to);
                    flag[to] = true;
                }
            }

            for (int i = 0; i < _n; i++) {
                if (flag[i])continue;
                flag[i] = true;
                dfs(i);
                break;
            }
        }
    private:
        int _n;
        std::vector<int> deg;
        std::vector<bool> flag;

        void dfs(int u) {
            loop.emplace_back(u);
            for (int v : G[u]) {
                if (flag[v])continue;
                flag[v] = true;
                dfs(v);
            }
        }
    };
}// namespace tomo0608