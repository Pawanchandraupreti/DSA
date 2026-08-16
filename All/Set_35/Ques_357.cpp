// Topological sort using Kahn's algorithm

#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);

    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int next : graph[node]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    return order;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<int> order = topologicalSort(n, edges);
    for (int x : order) {
        cout << x << ' ';
    }
    return 0;
}
