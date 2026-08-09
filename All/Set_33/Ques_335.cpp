// Longest path in a DAG from node 1 to node n (weights can be negative)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; if (!(cin >> n >> m)) return 0;
    vector<vector<pair<int,long long>>> adj(n+1);
    vector<int> indeg(n+1,0);
    for (int i = 0; i < m; ++i) {
        int u,v; long long w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        indeg[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) if (indeg[i]==0) q.push(i);
    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop(); topo.push_back(u);
        for (auto [v,w] : adj[u]) if (--indeg[v]==0) q.push(v);
    }

    // If not all nodes in topo, graph has a cycle; longest path undefined - print -1
    if ((int)topo.size() != n) { cout << -1; return 0; }

    const long long NEG_INF = LLONG_MIN/4;
    vector<long long> dist(n+1, NEG_INF);
    dist[1] = 0;
    for (int u : topo) {
        if (dist[u] == NEG_INF) continue;
        for (auto [v,w] : adj[u]) dist[v] = max(dist[v], dist[u] + w);
    }

    if (dist[n] == NEG_INF) cout << -1;
    else cout << dist[n];
    return 0;
}

