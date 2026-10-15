// Check Bipartite Graph

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

    vector<int> color(n, -1);
    bool possible = true;
    for (int start = 0; start < n; start++) {
        if (color[start] != -1) continue;
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int next : graph[node]) {
                if (color[next] == -1) {
                    color[next] = color[node] ^ 1;
                    q.push(next);
                } else if (color[next] == color[node]) possible = false;
            }
        }
    }
    cout << (possible ? "YES" : "NO") << '\n';
    return 0;
}


