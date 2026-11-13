// Strongly Connected Components

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n), reverseGraph(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        reverseGraph[v].push_back(u);
    }
    vector<int> used(n), order, component(n, -1);
    function<void(int)> first = [&](int vertex) {
        used[vertex] = 1;
        for (int next : graph[vertex]) if (!used[next]) first(next);
        order.push_back(vertex);
    };
    for (int i = 0; i < n; i++) if (!used[i]) first(i);
    reverse(order.begin(), order.end());
    int components = 0;
    function<void(int)> second = [&](int vertex) {
        component[vertex] = components;
        for (int next : reverseGraph[vertex]) if (component[next] == -1) second(next);
    };
    for (int vertex : order) if (component[vertex] == -1) {
        second(vertex);
        components++;
    }
    vector<bool> source(components, true);
    for (int u = 0; u < n; u++) for (int v : graph[u])
        if (component[u] != component[v]) source[component[v]] = false;
    int count = 0;
    for (bool value : source) count += value;
    cout << components << ' ' << count << '\n';
    return 0;
}
