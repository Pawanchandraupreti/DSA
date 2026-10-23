// Shortest Path Visiting All Nodes

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int full = (1 << n) - 1;
    queue<pair<int, int>> q;
    vector<vector<bool>> used(n, vector<bool>(1 << n));
    for (int i = 0; i < n; i++) {
        q.push({i, 1 << i});
        used[i][1 << i] = true;
    }
    int steps = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [node, mask] = q.front();
            q.pop();
            if (mask == full) {
                cout << steps << '\n';
                return 0;
            }
            for (int next : graph[node]) {
                int nextMask = mask | (1 << next);
                if (!used[next][nextMask]) {
                    used[next][nextMask] = true;
                    q.push({next, nextMask});
                }
            }
        }
        steps++;
    }
    return 0;
}
