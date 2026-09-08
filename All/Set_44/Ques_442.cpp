// Course Schedule Topological Sort

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> in(n);

    while (m--) {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
        in[a]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) if (!in[i]) q.push(i);
    vector<int> order;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g[u]) if (--in[v] == 0) q.push(v);
    }

    if ((int)order.size() != n) cout << -1;
    else for (int x : order) cout << x << ' ';
    return 0;
}


