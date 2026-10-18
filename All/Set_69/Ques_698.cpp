// Minimum Spanning Tree Weight

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) : parent(n) { iota(parent.begin(), parent.end(), 0); }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        parent[b] = a;
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges(m);
    for (auto &[weight, from, to] : edges) cin >> from >> to >> weight;
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int answer = 0;
    for (auto [weight, from, to] : edges) if (dsu.join(from, to)) answer += weight;
    cout << answer << '\n';
    return 0;
}
