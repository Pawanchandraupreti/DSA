// Number of Connected Components

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }
    int find(int node) { return parent[node] == node ? node : parent[node] = find(parent[node]); }
    bool join(int first, int second) {
        first = find(first);
        second = find(second);
        if (first == second) return false;
        if (size[first] < size[second]) swap(first, second);
        parent[second] = first;
        size[first] += size[second];
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    int components = n;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (dsu.join(u, v)) components--;
    }
    cout << components << '\n';
    return 0;
}
