// Heavy-light decomposition with path sum updates and queries

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int n;
    vector<ll> tree, lazy;
    SegTree() : n(0) {}
    SegTree(const vector<ll>& base) { build(base); }
    void build(const vector<ll>& base) {
        n = (int)base.size() - 1;
        tree.assign(4 * (n + 5), 0);
        lazy.assign(4 * (n + 5), 0);
        build(1, 1, n, base);
    }
    void build(int node, int l, int r, const vector<ll>& base) {
        if (l == r) {
            tree[node] = base[l];
            return;
        }
        int m = (l + r) >> 1;
        build(node << 1, l, m, base);
        build(node << 1 | 1, m + 1, r, base);
        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }
    void push(int node, int l, int r) {
        if (lazy[node] == 0 || l == r) return;
        int m = (l + r) >> 1;
        apply(node << 1, l, m, lazy[node]);
        apply(node << 1 | 1, m + 1, r, lazy[node]);
        lazy[node] = 0;
    }
    void apply(int node, int l, int r, ll val) {
        tree[node] += val * (r - l + 1);
        lazy[node] += val;
    }
    void rangeAdd(int ql, int qr, ll val) { rangeAdd(1, 1, n, ql, qr, val); }
    void rangeAdd(int node, int l, int r, int ql, int qr, ll val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int m = (l + r) >> 1;
        rangeAdd(node << 1, l, m, ql, qr, val);
        rangeAdd(node << 1 | 1, m + 1, r, ql, qr, val);
        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }
    ll rangeSum(int ql, int qr) { return rangeSum(1, 1, n, ql, qr); }
    ll rangeSum(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node];
        push(node, l, r);
        int m = (l + r) >> 1;
        return rangeSum(node << 1, l, m, ql, qr) + rangeSum(node << 1 | 1, m + 1, r, ql, qr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> val(n + 1);
    for (int i = 1; i <= n; ++i) cin >> val[i];

    vector<int> parent(n + 1, 0), depth(n + 1, 0), heavy(n + 1, -1), size(n + 1, 0);
    vector<int> order = {1};
    for (size_t i = 0; i < order.size(); ++i) {
        int u = order[i];
        for (int v : g[u]) if (v != parent[u]) {
            parent[v] = u;
            depth[v] = depth[u] + 1;
            order.push_back(v);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        size[u] = 1;
        for (int v : g[u]) if (v != parent[u]) {
            size[u] += size[v];
            if (heavy[u] == -1 || size[v] > size[heavy[u]]) heavy[u] = v;
        }
    }

    vector<int> head(n + 1), pos(n + 1);
    int timer = 0;
    function<void(int,int)> decompose = [&](int u, int h) {
        head[u] = h;
        pos[u] = ++timer;
        if (heavy[u] != -1) decompose(heavy[u], h);
        for (int v : g[u]) if (v != parent[u] && v != heavy[u]) decompose(v, v);
    };
    decompose(1, 1);

    vector<ll> base(n + 1);
    for (int i = 1; i <= n; ++i) base[pos[i]] = val[i];
    SegTree seg(base);
    auto addPath = [&](int u, int v, ll delta) {
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            seg.rangeAdd(pos[head[u]], pos[u], delta);
            u = parent[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        seg.rangeAdd(pos[u], pos[v], delta);
    };
    auto pathSum = [&](int u, int v) {
        ll ans = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            int h = head[u];
            ans += seg.rangeSum(pos[h], pos[u]);
            u = parent[h];
        }
        if (depth[u] > depth[v]) swap(u, v);
        ans += seg.rangeSum(pos[u], pos[v]);
        return ans;
    };

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            ll d;
            cin >> u >> v >> d;
            addPath(u, v, d);
        } else {
            int u, v;
            cin >> u >> v;
            cout << pathSum(u, v) << '\n';
        }
    }
    return 0;
}
