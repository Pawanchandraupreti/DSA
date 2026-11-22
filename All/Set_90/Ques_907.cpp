// Connectivity Queries with Disjoint Set Union

#include <bits/stdc++.h>
using namespace std;

struct Dsu {
    vector<int> p, sz;

    Dsu(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    Dsu dsu(n);
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            dsu.join(u, v);
        } else {
            cout << (dsu.find(u) == dsu.find(v) ? "YES\n" : "NO\n");
        }
    }
    return 0;
}


