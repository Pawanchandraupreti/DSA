// MST (Prim's Algorithm)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        for (auto [v, wt] : graph[u]) {
            if (!inMST[v] && wt < key[v]) {
                key[v] = wt;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    int ans = 0;
    for (int x : key) ans += x;
    cout << ans << '\n';
    return 0;
}


