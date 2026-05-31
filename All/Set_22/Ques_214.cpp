// Topological Sort (DFS)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int u, const vector<vector<int>>& g, vector<int>& vis, vector<int>& order) {
    vis[u] = 1;
    for (int v : g[u]) if (!vis[v]) dfs(v, g, vis, order);
    order.push_back(u);
}

int main() {
    int n, m;
    if(!(cin >> n >> m)) return 0;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    vector<int> vis(n,0), order;
    for (int i = 0; i < n; ++i) if (!vis[i]) dfs(i, g, vis, order);
    reverse(order.begin(), order.end());
    for (int x : order) cout << x << " ";
    return 0;
}


