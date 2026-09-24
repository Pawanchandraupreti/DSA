// Union Find Connected Components

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) : parent(n, -1) {}

    int find(int x) {
        return parent[x] < 0 ? x : parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (parent[a] > parent[b]) swap(a, b);
        parent[a] += parent[b];
        parent[b] = a;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
    }

    int components = 0;
    for (int x : dsu.parent) if (x < 0) components++;
    cout << components << '\n';
    return 0;
}
