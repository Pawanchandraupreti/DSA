// Bellman-Ford: shortest paths and negative cycle detection

#include <bits/stdc++.h>
using namespace std;

const long long INF = (1LL << 60);

struct Edge {
    int u, v;
    long long w;
};

int main() {
    int n, m, source;
    if (!(cin >> n >> m >> source)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    vector<long long> dist(n + 1, INF);
    dist[source] = 0;
    
    for (int i = 1; i <= n - 1; ++i) {
        for (auto &e : edges) {
            if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    bool negCycle = false;
    for (auto &e : edges) {
        if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w) {
            negCycle = true;
            break;
        }
    }

    if (negCycle) {
        cout << "Negative Cycle";
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        cout << (dist[i] == INF ? -1 : dist[i]);
    }

    return 0;
}
