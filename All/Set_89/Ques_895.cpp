// Dijkstra Shortest Paths

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    const long long inf = 1LL << 60;
    vector<long long> d(n, inf);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>> pq;
    d[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if (du != d[u]) continue;
        for (auto [v, w] : g[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }

    for (long long v : d) cout << (v == inf ? -1 : v) << ' ';
    cout << '\n';
    return 0;
}
