#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
#include<tuple>

std::vector<int> restore_path(std::vector<int> par, int goal) {
    std::vector<int> path = { goal };
    while (par[path.back()] != -1)path.emplace_back(par[path.back()]);
    std::reverse(path.begin(), path.end());
    return path;
}

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, long long>>> wt(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        wt[a].emplace_back(b, c);
        wt[b].emplace_back(a, c);
    }
    auto get_dist = [&](int st)->tuple<vector<long long>, vector<int>, int> {
        vector<long long> dist(n, -1);
        vector<int> par(n, -1);
        dist[st] = 0;
        queue<int> que;
        que.emplace(st);
        int farthest_point = st;
        long long max_dist = 0;
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            for (auto& [to, cost] : wt[now]) {
                if (dist[to] == -1) {
                    dist[to] = dist[now] + cost;
                    if (max_dist < dist[to]) {
                        max_dist = dist[to];
                        farthest_point = to;
                    }
                    que.emplace(to);
                    par[to] = now;
                }
            }
        }
        return make_tuple(dist, par, farthest_point);
    };

    auto [_, __, s] = get_dist(0);
    auto [dist, par, t] = get_dist(s);

    auto path = restore_path(par, t);
    cout << dist[t] << ' ' << path.size() << endl;
    for (int i = 0; i < path.size(); i++)cout << path[i] << ' ';
    cout << endl;
    return 0;
}