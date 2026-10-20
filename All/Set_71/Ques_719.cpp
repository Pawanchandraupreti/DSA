// Eventual Safe Nodes

#include <bits/stdc++.h>
using namespace std;

bool safe(int node, vector<vector<int>> &graph, vector<int> &state) {
    if (state[node] == 1) return false;
    if (state[node] == 2) return true;
    state[node] = 1;
    for (int next : graph[node]) if (!safe(next, graph, state)) return false;
    state[node] = 2;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }
    vector<int> state(n);
    for (int i = 0; i < n; i++) if (safe(i, graph, state)) cout << i << ' ';
    cout << '\n';
    return 0;
}
