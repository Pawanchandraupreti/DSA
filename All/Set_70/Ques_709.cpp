// Prim Minimum Spanning Tree

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    vector<int> used(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({0, 0});
    int answer = 0;
    while (!heap.empty()) {
        auto [weight, node] = heap.top();
        heap.pop();
        if (used[node]) continue;
        used[node] = 1;
        answer += weight;
        for (auto [next, edgeWeight] : graph[node]) if (!used[next]) heap.push({edgeWeight, next});
    }
    cout << answer << '\n';
    return 0;
}
