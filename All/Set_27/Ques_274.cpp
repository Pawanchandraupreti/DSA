// Number of paths in a DAG from 1 to n modulo 1e9+7

#include <bits/stdc++.h>
using namespace std;
static const long long MOD = 1000000007LL;

int main() {
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        ++indeg[v];
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) if (!indeg[i]) q.push(i);
    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : g[u]) if (--indeg[v] == 0) q.push(v);
    }

    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    for (int u : topo) {
        for (int v : g[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;
        }
    }
    cout << dp[n];
    return 0;
}

