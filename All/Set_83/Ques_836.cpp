// Minimum Height Trees

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> degree(n);
    for (int i = 0; i < m; i++) { int u, v; cin >> u >> v; graph[u].push_back(v); graph[v].push_back(u); degree[u]++; degree[v]++; }
    queue<int> q;
    for (int i = 0; i < n; i++) if (degree[i] <= 1) q.push(i);
    while (n > 2) {
        int size = q.size(); n -= size;
        while (size--) { int node = q.front(); q.pop(); for (int next : graph[node]) if (!--degree[next]) q.push(next); }
    }
    while (!q.empty()) { cout << q.front() << ' '; q.pop(); }
    cout << '\n';
    return 0;
}
