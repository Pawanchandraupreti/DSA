// Count connected components in an undirected graph

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<int>& visited) {
    visited[node] = 1;

    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next, graph, visited);
        }
    }
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visited(n + 1, 0);
    int components = 0;

    for (int node = 1; node <= n; ++node) {
        if (!visited[node]) {
            ++components;
            dfs(node, graph, visited);
        }
    }

    cout << components;
    return 0;
}