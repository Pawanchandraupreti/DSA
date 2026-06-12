// Kosaraju's algorithm: count SCCs and print component id of each node

#include <bits/stdc++.h>
using namespace std;

void dfs1(int u, vector<vector<int>>& g, vector<int>& vis, vector<int>& order) {
    vis[u] = 1;
    for (int v : g[u]) if (!vis[v]) dfs1(v, g, vis, order);
    order.push_back(u);
}

void dfs2(int u, vector<vector<int>>& rg, vector<int>& comp, int cid) {
    comp[u] = cid;
    for (int v : rg[u]) if (comp[v] == -1) dfs2(v, rg, comp, cid);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> g(n + 1), rg(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    vector<int> vis(n + 1, 0), order;
    for (int i = 1; i <= n; ++i) if (!vis[i]) dfs1(i, g, vis, order);
    reverse(order.begin(), order.end());

    vector<int> comp(n + 1, -1);
    int cid = 0;
    for (int u : order) {
        if (comp[u] == -1) dfs2(u, rg, comp, cid++);
    }

    cout << cid << '\n';
    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        cout << comp[i];
    }
    return 0;
}
