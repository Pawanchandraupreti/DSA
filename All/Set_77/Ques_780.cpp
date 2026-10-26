// Critical Connections in Graph

#include <bits/stdc++.h>
using namespace std;

int timerValue = 0;
void dfs(int node, int parent, vector<vector<int>> &graph, vector<int> &tin, vector<int> &low, vector<pair<int, int>> &bridges) {
    tin[node] = low[node] = ++timerValue;
    for (int next : graph[node]) {
        if (next == parent) continue;
        if (tin[next]) low[node] = min(low[node], tin[next]);
        else {
            dfs(next, node, graph, tin, low, bridges);
            low[node] = min(low[node], low[next]);
            if (low[next] > tin[node]) bridges.push_back({min(node, next), max(node, next)});
        }
    }
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
    vector<int> tin(n), low(n);
    vector<pair<int, int>> bridges;
    for (int i = 0; i < n; i++) if (!tin[i]) dfs(i, -1, graph, tin, low, bridges);
    sort(bridges.begin(), bridges.end());
    for (auto [u, v] : bridges) cout << u << ' ' << v << '\n';
    return 0;
}
