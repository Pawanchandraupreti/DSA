// Network Delay Time

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, src;
    cin >> n >> m >> src;
    vector<vector<pair<int, int>>> g(n + 1);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    const int inf = 1e9;
    vector<int> dist(n + 1, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : g[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = *max_element(dist.begin() + 1, dist.end());
    cout << (ans == inf ? -1 : ans);
    return 0;
}
