// Topological Sort

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> degree(n);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        degree[to]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) if (degree[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);
        for (int next : graph[node]) if (--degree[next] == 0) q.push(next);
    }
    if ((int)order.size() != n) cout << "CYCLE\n";
    else for (int node : order) cout << node << ' ';
    return 0;
}
