// Strongly Connected Components count (Kosaraju)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> g(n+1), gr(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    vector<int> used(n+1, 0);
    vector<int> order;
    function<void(int)> dfs1 = [&](int u){ used[u]=1; for(int v:g[u]) if(!used[v]) dfs1(v); order.push_back(u); };
    for (int i = 1; i <= n; ++i) if (!used[i]) dfs1(i);

    fill(used.begin(), used.end(), 0);
    int scc = 0;
    function<void(int)> dfs2 = [&](int u){ used[u]=1; for(int v:gr[u]) if(!used[v]) dfs2(v); };
    for (int i = (int)order.size()-1; i>=0; --i) {
        int v = order[i];
        if (!used[v]) { ++scc; dfs2(v); }
    }

    cout << scc;
    return 0;
}


