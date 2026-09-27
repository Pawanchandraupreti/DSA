// Kruskal's Minimum Spanning Tree

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) : parent(n, -1) {}

    int find(int x) {
        return parent[x] < 0 ? x : parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (parent[a] > parent[b]) swap(a, b);
        parent[a] += parent[b];
        parent[b] = a;
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (auto &edge : edges) cin >> edge[1] >> edge[2] >> edge[0];
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int answer = 0;
    for (auto [weight, u, v] : edges) {
        if (dsu.unite(u, v)) answer += weight;
    }

    cout << answer << '\n';
    return 0;
}
