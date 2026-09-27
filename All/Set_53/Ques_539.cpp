// Shortest Path in an Unweighted Graph

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, source, target;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin >> source >> target;

    vector<int> distance(n, -1);
    queue<int> q;
    q.push(source);
    distance[source] = 0;
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

    cout << distance[target] << '\n';
    return 0;
}
