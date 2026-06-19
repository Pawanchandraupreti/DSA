// Range add and range minimum query with lazy segment tree

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (1LL << 60);

struct SegTree {
    int n;
    vector<ll> tree, lazy;

    SegTree(const vector<ll>& a) { build(a); }

    void build(const vector<ll>& a) {
        n = (int)a.size() - 1;
        tree.assign(4 * (n + 5), 0);
        lazy.assign(4 * (n + 5), 0);
        build(1, 1, n, a);
    }

    void build(int node, int l, int r, const vector<ll>& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(node << 1, l, m, a);
        build(node << 1 | 1, m + 1, r, a);
        tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
    }

    void apply(int node, ll val) {
        tree[node] += val;
        lazy[node] += val;
    }

    void push(int node) {
        if (lazy[node] != 0) {
            apply(node << 1, lazy[node]);
            apply(node << 1 | 1, lazy[node]);
            lazy[node] = 0;
        }
    }

    void add(int l, int r, ll val) { add(1, 1, n, l, r, val); }

    void add(int node, int l, int r, int ql, int qr, ll val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, val);
            return;
        }
        push(node);
        int m = (l + r) >> 1;
        add(node << 1, l, m, ql, qr, val);
        add(node << 1 | 1, m + 1, r, ql, qr, val);
        tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
    }

    ll query(int l, int r) { return query(1, 1, n, l, r); }

    ll query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return INF;
        if (ql <= l && r <= qr) return tree[node];
        push(node);
        int m = (l + r) >> 1;
        return min(query(node << 1, l, m, ql, qr), query(node << 1 | 1, m + 1, r, ql, qr));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    SegTree seg(a);
    while (q--) {
        int type, l, r;
        ll x;
        cin >> type >> l >> r;
        if (type == 1) {
            cin >> x;
            seg.add(l, r, x);
        } else {
            cout << seg.query(l, r) << '\n';
        }
    }
    return 0;
}
