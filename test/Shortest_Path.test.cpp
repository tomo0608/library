#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include<cassert>
#include<vector>
#include<limits>
#include<queue>
#include<algorithm>
#include<iostream>

namespace tomo0608 {

    class Weighted_Digraph {
    public:
        std::vector<std::vector<std::pair<long long, int>>> Adjacency_List, Transpose;
        unsigned number_of_nodes;
        Weighted_Digraph(unsigned n): number_of_nodes(n), Adjacency_List(n), Transpose(n) {};

        void add_edge(int from, int to, unsigned long long weight) {
            assert(0 <= from && from < number_of_nodes);
            assert(0 <= to && to < number_of_nodes);
            Adjacency_List[from].emplace_back(weight, to);
            Transpose[to].emplace_back(weight, from);
        }

        std::pair<std::vector<long long>, std::vector<int>> Dijkstra(int start) { // startを始点とした最短距離をダイクストラ法で求める, (最短距離のリスト, 最短経路木の親の情報)
            std::vector<long long> Dist(number_of_nodes, -1);
            std::vector<int> par(number_of_nodes, -1);
            using P = std::pair<long long, int>;
            std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
            Dist[start] = 0;
            pq.emplace(0, start);
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if (Dist[u] < d)continue;
                for (auto& [w, v] : Adjacency_List[u]) {
                    if (Dist[v] == -1 || Dist[v] > Dist[u] + w) {
                        Dist[v] = Dist[u] + w;
                        pq.emplace(Dist[v], v);
                        par[v] = u;
                    }
                }
            }
            return std::make_pair(Dist, par);
        }
    };
} // namespace tomo0608

namespace tomo0608 {
    std::vector<int> restore_path(std::vector<int> par, int goal) {
        std::vector<int> path = { goal };
        while (par[path.back()] != -1)path.emplace_back(par[path.back()]);
        std::reverse(path.begin(), path.end());
        return path;
    }
} // namespace tomo0608

using namespace std;

int main() {
    unsigned n, m, s, t;cin >> n >> m >> s >> t;
    tomo0608::Weighted_Digraph g(n);
    for (int i = 0; i < m; i++) {
        unsigned a, b;cin >> a >> b;
        long long c;cin >> c;
        g.add_edge(a, b, c);
    }

    auto [dist, par] = g.Dijkstra(s);
    if (dist[t] == -1) {
        cout << -1 << endl;
        return 0;
    }
    auto path = tomo0608::restore_path(par, t);
    cout << dist[t] << ' ' << path.size() - 1 << endl;
    for (int i = 0; i < path.size() - 1; i++)cout << path[i] << ' ' << path[i + 1] << endl;
    return 0;
}