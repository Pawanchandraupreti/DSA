// LCA and distance queries using binary lifting

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int LOG = 1;
    while ((1 << LOG) <= n) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n + 1, 0));
    vector<int> depth(n + 1, 0);
    queue<int> qu;
    qu.push(1);
    vector<int> vis(n + 1, 0);
    vis[1] = 1;
    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        for (int v : g[u]) if (!vis[v]) {
            vis[v] = 1;
            depth[v] = depth[u] + 1;
            up[0][v] = u;
            for (int j = 1; j < LOG; ++j) up[j][v] = up[j - 1][up[j - 1][v]];
            qu.push(v);
        }
    }

    auto lift = [&](int u, int k) {
        for (int j = 0; j < LOG; ++j) if (k & (1 << j)) u = up[j][u];
        return u;
    };
    auto lca = [&](int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        a = lift(a, depth[a] - depth[b]);
        if (a == b) return a;
        for (int j = LOG - 1; j >= 0; --j) {
            if (up[j][a] != up[j][b]) {
                a = up[j][a];
                b = up[j][b];
            }
        }
        return up[0][a];
    };

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            cout << lca(a, b) << '\n';
        } else {
            int c = lca(a, b);
            cout << depth[a] + depth[b] - 2 * depth[c] << '\n';
        }
    }
    return 0;
}

