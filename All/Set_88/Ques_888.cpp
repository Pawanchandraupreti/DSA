// Eulerian Circuit in a Directed Graph

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    vector<int> inDegree(n), outDegree(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v, i});
        outDegree[u]++;
        inDegree[v]++;
    }
    for (int i = 0; i < n; i++) if (inDegree[i] != outDegree[i]) {
        cout << "NO\n";
        return 0;
    }
    vector<int> used(m), circuit;
    function<void(int)> visit = [&](int vertex) {
        while (!graph[vertex].empty()) {
            auto [next, id] = graph[vertex].back();
            graph[vertex].pop_back();
            if (!used[id]) { used[id] = 1; visit(next); }
        }
        circuit.push_back(vertex);
    };
    int start = 0;
    while (start < n && graph[start].empty()) start++;
    if (m) visit(start);
    if ((int)circuit.size() != m + 1) {
        cout << "NO\n";
        return 0;
    }
    reverse(circuit.begin(), circuit.end());
    cout << "YES\n";
    for (int vertex : circuit) cout << vertex << ' ';
    cout << '\n';
    return 0;
}
