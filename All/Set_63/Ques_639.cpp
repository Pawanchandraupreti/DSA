// Detect Cycle in Undirected Graph

#include <bits/stdc++.h>
using namespace std;

bool hasCycle(int node, int parent, vector<vector<int>> &graph, vector<int> &visited) {
    visited[node] = 1;
    for (int next : graph[node]) {
        if (!visited[next]) {
            if (hasCycle(next, node, graph, visited)) return true;
        } else if (next != parent) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visited(n);
    bool cycle = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && hasCycle(i, -1, graph, visited)) cycle = true;
    }
    cout << (cycle ? "YES" : "NO") << '\n';
    return 0;
}
