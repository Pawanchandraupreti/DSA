// All Paths from Source to Target

#include <bits/stdc++.h>
using namespace std;

void visit(int node, int target, vector<vector<int>> &graph, vector<int> &path) {
    if (node == target) {
        for (int x : path) cout << x << ' ';
        cout << '\n';
        return;
    }
    for (int next : graph[node]) {
        path.push_back(next);
        visit(next, target, graph, path);
        path.pop_back();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) { int u, v; cin >> u >> v; graph[u].push_back(v); }
    vector<int> path = {0};
    visit(0, n - 1, graph, path);
    return 0;
}
