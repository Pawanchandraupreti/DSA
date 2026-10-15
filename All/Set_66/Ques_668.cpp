// Dijkstra Shortest Paths

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, source;
    cin >> n >> m >> source;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
    }

    const int inf = 1e9;
    vector<int> distance(n, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[source] = 0;
    pq.push({0, source});
    while (!pq.empty()) {
        auto [currentDistance, node] = pq.top();
        pq.pop();
        if (currentDistance != distance[node]) continue;
        for (auto [next, weight] : graph[node]) {
            if (distance[next] > currentDistance + weight) {
                distance[next] = currentDistance + weight;
                pq.push({distance[next], next});
            }
        }
    }
    for (int value : distance) cout << (value == inf ? -1 : value) << ' ';
    cout << '\n';
    return 0;
}
