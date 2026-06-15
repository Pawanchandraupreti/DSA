// Minimum spanning tree total weight using Kruskal

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n + 1), r(n + 1, 0) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) ++r[a];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    struct E { int u, v; ll w; };
    vector<E> edges(m);
    for (int i = 0; i < m; ++i) cin >> edges[i].u >> edges[i].v >> edges[i].w;
    sort(edges.begin(), edges.end(), [](const E& a, const E& b) { return a.w < b.w; });

    DSU dsu(n);
    ll ans = 0;
    int used = 0;
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            ans += e.w;
            ++used;
        }
    }
    if (used != n - 1) cout << -1;
    else cout << ans;
    return 0;
}
