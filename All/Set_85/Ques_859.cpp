// Minimum Starting Vertices to Reach All Nodes

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> indegree(n);
    for (int i = 0; i < m; i++) { int u, v; cin >> u >> v; graph[u].push_back(v); indegree[v]++; }
    for (int i = 0; i < n; i++) if (!indegree[i]) cout << i << ' ';
    cout << '\n';
    return 0;
}
