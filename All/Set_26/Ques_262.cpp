// Count shortest paths from 1 to n in a weighted graph

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const ll MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<pair<int, ll>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; ll w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    const ll INF = (1LL << 62);
    vector<ll> dist(n + 1, INF), ways(n + 1, 0);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[1] = 0;
    ways[1] = 1;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : g[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                ways[v] = ways[u];
                pq.push({dist[v], v});
            } else if (dist[v] == d + w) {
                ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
    }

    cout << (dist[n] == INF ? 0 : ways[n]);
    return 0;
}
