// Redundant Connection Using DSU

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    int n;
    cin >> n;
    DSU dsu(n + 1);

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (!dsu.join(u, v)) cout << u << ' ' << v;
    }
    return 0;
}
