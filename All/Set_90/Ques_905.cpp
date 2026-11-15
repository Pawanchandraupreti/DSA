// Check Whether an Undirected Graph is Bipartite

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> col(n, -1);
    bool ok = true;
    for (int s = 0; s < n; s++) if (col[s] == -1) {
        queue<int> q;
        q.push(s);
        col[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (col[v] == -1) {
                    col[v] = col[u] ^ 1;
                    q.push(v);
                } else if (col[v] == col[u]) {
                    ok = false;
                }
            }
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
    return 0;
}
