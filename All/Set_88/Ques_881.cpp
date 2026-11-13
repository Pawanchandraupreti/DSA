// Second Best Minimum Spanning Tree

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from, to, weight, id;
};

struct Dsu {
    vector<int> parent, size;
    Dsu(int n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a; size[a] += size[b];
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
        edges[i].id = i;
    }
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.weight < b.weight;
    });
    Dsu dsu(n);
    vector<vector<pair<int, int>>> tree(n);
    vector<bool> chosen(m);
    long long mst = 0;
    for (const Edge &edge : edges) if (dsu.unite(edge.from, edge.to)) {
        chosen[edge.id] = true;
        mst += edge.weight;
        tree[edge.from].push_back({edge.to, edge.weight});
        tree[edge.to].push_back({edge.from, edge.weight});
    }
    if (count(chosen.begin(), chosen.end(), true) != n - 1) {
        cout << "-1\n";
        return 0;
    }
    long long answer = LLONG_MAX;
    for (const Edge &edge : edges) if (!chosen[edge.id]) {
        int largest = 0;
        function<bool(int, int)> findLargest = [&](int vertex, int parent) {
            if (vertex == edge.to) return true;
            for (auto [next, weight] : tree[vertex]) if (next != parent) {
                if (findLargest(next, vertex)) {
                    largest = max(largest, weight);
                    return true;
                }
            }
            return false;
        };
        findLargest(edge.from, -1);
        answer = min(answer, mst + edge.weight - largest);
    }
    cout << answer << '\n';
    return 0;
}
