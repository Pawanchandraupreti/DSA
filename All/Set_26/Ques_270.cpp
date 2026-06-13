// Articulation points and bridges in an undirected graph

#include <bits/stdc++.h>
using namespace std;

struct Edge { int to, id; };

int timer = 0;
void dfs(int u, int pe, const vector<vector<Edge>>& g, vector<int>& tin, vector<int>& low,
         vector<int>& vis, vector<int>& isArt, vector<int>& bridges) {
    vis[u] = 1;
    tin[u] = low[u] = ++timer;
    int child = 0;
    for (auto e : g[u]) {
        if (e.id == pe) continue;
        int v = e.to;
        if (vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, e.id, g, tin, low, vis, isArt, bridges);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) bridges.push_back(e.id);
            if (pe != -1 && low[v] >= tin[u]) isArt[u] = 1;
            ++child;
        }
    }
    if (pe == -1 && child > 1) isArt[u] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<Edge>> g(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    vector<int> tin(n + 1, 0), low(n + 1, 0), vis(n + 1, 0), isArt(n + 1, 0), bridges;
    for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i, -1, g, tin, low, vis, isArt, bridges);

    vector<int> arts;
    for (int i = 1; i <= n; ++i) if (isArt[i]) arts.push_back(i);
    sort(arts.begin(), arts.end());
    sort(bridges.begin(), bridges.end());

    cout << arts.size() << '\n';
    for (size_t i = 0; i < arts.size(); ++i) {
        if (i) cout << ' ';
        cout << arts[i];
    }
    cout << '\n' << bridges.size() << '\n';
    for (size_t i = 0; i < bridges.size(); ++i) {
        if (i) cout << ' ';
        cout << bridges[i];
    }
    return 0;
}
