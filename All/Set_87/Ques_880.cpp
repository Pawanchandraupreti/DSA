// Articulation Points in an Undirected Graph

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> discovery(n), low(n), articulation;
    int timer = 0;
    function<void(int, int)> dfs = [&](int vertex, int parent) {
        discovery[vertex] = low[vertex] = ++timer;
        int children = 0;
        bool cut = false;
        for (int next : graph[vertex]) {
            if (next == parent) continue;
            if (!discovery[next]) {
                children++;
                dfs(next, vertex);
                low[vertex] = min(low[vertex], low[next]);
                if (parent != -1 && low[next] >= discovery[vertex]) cut = true;
            } else low[vertex] = min(low[vertex], discovery[next]);
        }
        if ((parent == -1 && children > 1) || cut) articulation.push_back(vertex);
    };
    for (int i = 0; i < n; i++) if (!discovery[i]) dfs(i, -1);
    sort(articulation.begin(), articulation.end());
    cout << articulation.size() << '\n';
    for (int vertex : articulation) cout << vertex << ' ';
    cout << '\n';
    return 0;
}
