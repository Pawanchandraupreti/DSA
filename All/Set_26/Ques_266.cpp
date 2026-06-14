// Tree diameter with path reconstruction

#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> farthest(int src, const vector<vector<int>>& g) {
    int n = (int)g.size() - 1;
    vector<int> dist(n + 1, -1), parent(n + 1, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    int best = src;
    for (int i = 1; i <= n; ++i) if (dist[i] > dist[best]) best = i;
    vector<int> path;
    for (int cur = best; cur != -1; cur = parent[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());
    return {best, path};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto [a, p1] = farthest(1, g);
    auto [b, path] = farthest(a, g);
    cout << (int)path.size() - 1 << '\n';
    for (size_t i = 0; i < path.size(); ++i) {
        if (i) cout << ' ';
        cout << path[i];
    }
    return 0;
}

