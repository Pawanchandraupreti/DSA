// Shortest path from source using Dijkstra's algorithm

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, source;
    if (!(cin >> n >> m >> source)) return 0;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    const long long INF = (1LL << 60);
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        if (d != dist[node]) continue;
        for (auto [next, weight] : adj[node]) {
            if (dist[next] > d + weight) {
                dist[next] = d + weight;
                pq.push({dist[next], next});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        if (dist[i] == INF) cout << -1;
        else cout << dist[i];
    }
    return 0;
}
