// Find the number of connected components in an undirected graph

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);
    int components = 0;

    for (int start = 1; start <= n; ++start) {
        if (vis[start]) continue;
        ++components;
        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int next : adj[node]) {
                if (!vis[next]) {
                    vis[next] = 1;
                    q.push(next);
                }
            }
        }
    }

    cout << components;
    return 0;
}