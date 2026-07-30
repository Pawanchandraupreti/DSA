// 2-SAT solver with one valid assignment

#include <bits/stdc++.h>
using namespace std;

struct TwoSAT {
    int n;
    vector<vector<int>> g, rg;
    vector<int> comp, order, vis, assignment;
    TwoSAT(int n) : n(n), g(2 * n), rg(2 * n), comp(2 * n, -1), vis(2 * n, 0), assignment(n, 0) {}

    int var(int x, bool val) { return 2 * x ^ (val ? 0 : 1); }
    void addImp(int a, int b) { g[a].push_back(b); rg[b].push_back(a); }
    void addOr(int x, bool xv, int y, bool yv) {
        int a = var(x, xv), na = var(x, !xv), b = var(y, yv), nb = var(y, !yv);
        addImp(na, b);
        addImp(nb, a);
    }

    void dfs1(int u) {
        vis[u] = 1;
        for (int v : g[u]) if (!vis[v]) dfs1(v);
        order.push_back(u);
    }
    void dfs2(int u, int c) {
        comp[u] = c;
        for (int v : rg[u]) if (comp[v] == -1) dfs2(v, c);
    }

    bool solve() {
        for (int i = 0; i < 2 * n; ++i) if (!vis[i]) dfs1(i);
        reverse(order.begin(), order.end());
        int c = 0;
        for (int u : order) if (comp[u] == -1) dfs2(u, c++);
        for (int i = 0; i < n; ++i) {
            if (comp[2 * i] == comp[2 * i + 1]) return false;
            assignment[i] = comp[2 * i] > comp[2 * i + 1];
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    TwoSAT sat(n);
    for (int i = 0; i < m; ++i) {
        int x, xv, y, yv;
        cin >> x >> xv >> y >> yv;
        --x; --y;
        sat.addOr(x, xv, y, yv);
    }

    if (!sat.solve()) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << sat.assignment[i];
    }
    return 0;
}
