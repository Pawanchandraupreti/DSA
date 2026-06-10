// Range GCD queries with point updates using segment tree

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int n;
    vector<ll> st;
    SegTree(const vector<ll>& a) {
        n = (int)a.size();
        st.assign(4 * n + 4, 0);
        build(1, 0, n - 1, a);
    }
    static ll merge(ll x, ll y) { return std::gcd(x, y); }
    void build(int p, int l, int r, const vector<ll>& a) {
        if (l == r) { st[p] = a[l]; return; }
        int m = (l + r) / 2;
        build(p * 2, l, m, a);
        build(p * 2 + 1, m + 1, r, a);
        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }
    void update(int p, int l, int r, int idx, ll val) {
        if (l == r) { st[p] = val; return; }
        int m = (l + r) / 2;
        if (idx <= m) update(p * 2, l, m, idx, val);
        else update(p * 2 + 1, m + 1, r, idx, val);
        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }
    ll query(int p, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return st[p];
        int m = (l + r) / 2;
        return merge(query(p * 2, l, m, ql, qr), query(p * 2 + 1, m + 1, r, ql, qr));
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
            int idx; ll val;
            cin >> idx >> val;
            --idx;
            st.update(1, 0, n - 1, idx, val);
        } else {
            int l, r;
            cin >> l >> r;
            --l; --r;
            cout << st.query(1, 0, n - 1, l, r) << '\n';
        }
    }
    return 0;
}
