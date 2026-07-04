// Find articulation points in an undirected graph

#include <bits/stdc++.h>
using namespace std;

int timer = 0;

void dfs(int u, int parent, vector<vector<int>> &graph, vector<int> &tin, vector<int> &low, vector<bool> &visited, vector<bool> &isCut) {
    visited[u] = true;
    tin[u] = low[u] = ++timer;
    int children = 0;

    for (int v : graph[u]) {
        if (v == parent) continue;
        if (visited[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u, graph, tin, low, visited, isCut);
            low[u] = min(low[u], low[v]);
            if (parent != -1 && low[v] >= tin[u]) isCut[u] = true;
            ++children;
        }
    }

    if (parent == -1 && children > 1) isCut[u] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> tin(n + 1, 0), low(n + 1, 0);
    vector<bool> visited(n + 1, false), isCut(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) dfs(i, -1, graph, tin, low, visited, isCut);
    }

    vector<int> answer;
    for (int i = 1; i <= n; ++i) {
        if (isCut[i]) answer.push_back(i);
    }

    if (answer.empty()) {
        cout << -1;
    } else {
        for (int x : answer) cout << x << ' ';
    }

    return 0;
}