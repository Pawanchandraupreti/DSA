// Shortest path in an unweighted graph using BFS

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestDistances(int start, const vector<vector<int>>& graph) {
    int n = graph.size() - 1;
    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int next : graph[node]) {
            if (dist[next] == -1) {
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }

    return dist;
}

int main() {
    int n, m, source;
    if (!(cin >> n >> m >> source)) return 0;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> dist = shortestDistances(source, graph);
    for (int node = 1; node <= n; ++node) {
        if (node > 1) cout << ' ';
        cout << dist[node];
    }

    return 0;
}

