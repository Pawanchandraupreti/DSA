// Shortest Path in a DAG

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, source;
    cin >> n >> m >> source;
    vector<vector<pair<int, int>>> graph(n);
    vector<int> degree(n);
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
        degree[to]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) if (!degree[i]) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int node = q.front(); q.pop(); order.push_back(node);
        for (auto [next, weight] : graph[node]) if (!--degree[next]) q.push(next);
    }
    const int inf = 1e9;
    vector<int> distance(n, inf);
    distance[source] = 0;
    for (int node : order) for (auto [next, weight] : graph[node]) if (distance[node] != inf) distance[next] = min(distance[next], distance[node] + weight);
    for (int value : distance) cout << (value == inf ? -1 : value) << ' ';
    cout << '\n';
    return 0;
}
