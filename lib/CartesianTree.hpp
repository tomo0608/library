#pragma once

#include<vector>

namespace tomo0608 {
    template<class T>
    std::pair<std::vector<std::vector<int>>, int> CartesianTree(std::vector<T>& v) {
        int n = v.size();
        std::vector<std::vector<int>> G(n);
        std::vector<int> par(n, -1), st;
        st.reserve(n);
        for (int i = 0; i < n; i++) {
            int prv = -1;
            while (!st.empty() && v[i] < v[st.back()]) {
                prv = st.back();
                st.pop_back();
            }
            if (prv != -1)par[prv] = i;
            if (!st.empty())par[i] = st.back();
            st.push_back(i);
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (par[i] == -1)root = i;
            else G[par[i]].push_back(i);
        }
        return { G, root };
    };
} // namespace tomo0608