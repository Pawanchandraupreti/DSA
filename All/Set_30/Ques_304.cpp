// Shortest path in an unweighted graph using BFS

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, source;
    if (!(cin >> n >> m >> source)) return 0;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> distance(n + 1, -1);
    queue<int> q;
    distance[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int next : graph[node]) {
            if (distance[next] == -1) {
                distance[next] = distance[node] + 1;
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        cout << distance[i];
    }
    return 0;
}


