// Segment tree with lazy propagation for range add and range sum query

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int n;
    vector<ll> st, lazy;
    SegTree(const vector<ll>& a) {
        n = (int)a.size();
        st.assign(4 * n + 4, 0);
        lazy.assign(4 * n + 4, 0);
        build(1, 0, n - 1, a);
    }
    void build(int p, int l, int r, const vector<ll>& a) {
        if (l == r) { st[p] = a[l]; return; }
        int m = (l + r) / 2;
        build(p * 2, l, m, a);
        build(p * 2 + 1, m + 1, r, a);
        st[p] = st[p * 2] + st[p * 2 + 1];
    }
    void push(int p, int l, int r) {
        if (lazy[p] == 0 || l == r) return;
        int m = (l + r) / 2;
        ll v = lazy[p];
        st[p * 2] += v * (m - l + 1);
        st[p * 2 + 1] += v * (r - m);
        lazy[p * 2] += v;
        lazy[p * 2 + 1] += v;
        lazy[p] = 0;
    }
    void add(int p, int l, int r, int ql, int qr, ll val) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            st[p] += val * (r - l + 1);
            lazy[p] += val;
            return;
        }
        push(p, l, r);
        int m = (l + r) / 2;
        add(p * 2, l, m, ql, qr, val);
        add(p * 2 + 1, m + 1, r, ql, qr, val);
        st[p] = st[p * 2] + st[p * 2 + 1];
    }
    ll sum(int p, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return st[p];
        push(p, l, r);
        int m = (l + r) / 2;
        return sum(p * 2, l, m, ql, qr) + sum(p * 2 + 1, m + 1, r, ql, qr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    SegTree st(a);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r; ll val;
            cin >> l >> r >> val;
            --l; --r;
            st.add(1, 0, n - 1, l, r, val);
        } else {
            int l, r;
            cin >> l >> r;
            --l; --r;
            cout << st.sum(1, 0, n - 1, l, r) << '\n';
        }
    }
    return 0;
}

