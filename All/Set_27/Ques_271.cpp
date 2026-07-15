// Longest path in a DAG from 1 to n with reconstruction

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<pair<int, long long>>> g(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v; long long w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        ++indeg[v];
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) if (!indeg[i]) q.push(i);
    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (auto [v, w] : g[u]) if (--indeg[v] == 0) q.push(v);
    }

    const long long NEG = -(1LL << 60);
    vector<long long> dist(n + 1, NEG);
    vector<int> parent(n + 1, -1);
    dist[1] = 0;
    for (int u : topo) {
        if (dist[u] == NEG) continue;
        for (auto [v, w] : g[u]) {
            if (dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    if (dist[n] == NEG) {
        cout << -1;
        return 0;
    }
    cout << dist[n] << '\n';
    vector<int> path;
    for (int cur = n; cur != -1; cur = parent[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());
    for (size_t i = 0; i < path.size(); ++i) {
        if (i) cout << ' ';
        cout << path[i];
    }
    return 0;
}
