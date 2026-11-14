// Lowest Common Ancestor in a Tree

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int lg = 1;
    while ((1 << lg) <= n) lg++;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<int>> up(lg, vector<int>(n));
    vector<int> dep(n);
    function<void(int, int)> dfs = [&](int u, int p) {
        up[0][u] = p;
        for (int v : g[u]) if (v != p) {
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    };
    dfs(0, 0);
    for (int j = 1; j < lg; j++)
        for (int u = 0; u < n; u++)
            up[j][u] = up[j - 1][up[j - 1][u]];

    while (q--) {
        int u, v;
        cin >> u >> v;
        if (dep[u] < dep[v]) swap(u, v);
        int dif = dep[u] - dep[v];
        for (int j = 0; j < lg; j++) if (dif >> j & 1) u = up[j][u];
        if (u != v) {
            for (int j = lg - 1; j >= 0; j--)
                if (up[j][u] != up[j][v]) u = up[j][u], v = up[j][v];
            u = up[0][u];
        }
        cout << u << '\n';
    }
    return 0;
}
