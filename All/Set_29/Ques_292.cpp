// Strongly connected components count using Kosaraju's algorithm

#include <bits/stdc++.h>
using namespace std;

void dfs1(int u, vector<vector<int>> &graph, vector<int> &visited, vector<int> &order) {
    visited[u] = 1;
    for (int v : graph[u]) {
        if (!visited[v]) dfs1(v, graph, visited, order);
    }
    order.push_back(u);
}

void dfs2(int u, vector<vector<int>> &reverseGraph, vector<int> &component) {
    component[u] = 1;
    for (int v : reverseGraph[u]) {
        if (!component[v]) dfs2(v, reverseGraph, component);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> graph(n + 1), reverseGraph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        reverseGraph[v].push_back(u);
    }

    vector<int> visited(n + 1, 0), order;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) dfs1(i, graph, visited, order);
    }

    vector<int> component(n + 1, 0);
    int countComponents = 0;

    for (int i = (int)order.size() - 1; i >= 0; --i) {
        int node = order[i];
        if (!component[node]) {
            dfs2(node, reverseGraph, component);
            ++countComponents;
        }
    }

    cout << countComponents;
    return 0;
}