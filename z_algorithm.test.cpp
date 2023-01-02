#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <bits/stdc++.h>

template <class T> std::vector<int> z_algorithm(std::vector<T> S) {
    size_t n = S.size();
    std::vector<int> Z(n);
    Z[0] = n;
    int i = 1, j = 0;
    while (i < n) {
        while (i + j < n && S[j] == S[i + j])
            j++;
        Z[i] = j;

        if (!j) {
            i++;
            continue;
        }
        int k = 1;
        while (k < j && k + Z[k] < j) {
            Z[i + k] = Z[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return Z;
};

std::vector<int> z_algorithm(std::string S) {
    size_t n = S.size();
    std::vector<int> Z(n);
    Z[0] = n;
    int i = 1, j = 0;
    while (i < n) {
        while (i + j < n && S[j] == S[i + j])
            j++;
        Z[i] = j;

        if (!j) {
            i++;
            continue;
        }
        int k = 1;
        while (k < j && k + Z[k] < j) {
            Z[i + k] = Z[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return Z;
};

using namespace std;
int main() {
    string s;cin >> s;
    vector<int> a = z_algorithm(s);
    for (int i = 0; i < a.size() - 1; i++)cout << a[i] << ' ';
    cout << a.back() << endl;
    return 0;
}