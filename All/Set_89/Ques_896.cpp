// Course Order with Topological Sorting

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        deg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) if (deg[i] == 0) q.push(i);
    vector<int> ans;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v : g[u]) if (--deg[v] == 0) q.push(v);
    }

    if ((int)ans.size() != n) {
        cout << "-1\n";
    } else {
        for (int v : ans) cout << v << ' ';
        cout << '\n';
    }
    return 0;
}
