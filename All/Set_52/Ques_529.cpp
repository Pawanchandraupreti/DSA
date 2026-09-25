// Find Eventual Safe States

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n), reverseGraph(n);
    vector<int> outdegree(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        reverseGraph[v].push_back(u);
        outdegree[u]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) if (outdegree[i] == 0) q.push(i);
    vector<bool> safe(n, false);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        safe[node] = true;
        for (int previous : reverseGraph[node]) {
            if (--outdegree[previous] == 0) q.push(previous);
        }
    }

    for (int i = 0; i < n; i++) if (safe[i]) cout << i << ' ';
    cout << '\n';
    return 0;
}
