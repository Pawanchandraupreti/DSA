// Segment tree for range sum query and point update

#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<long long> tree;

    SegTree(const vector<long long> &a) {
        n = (int)a.size();
        tree.assign(4 * n + 4, 0);
        build(1, 0, n - 1, a);
    }

    void build(int node, int l, int r, const vector<long long> &a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update(int node, int l, int r, int idx, long long val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid) update(node * 2, l, mid, idx, val);
        else update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];

        int mid = (l + r) / 2;
        return query(node * 2, l, mid, ql, qr) + query(node * 2 + 1, mid + 1, r, ql, qr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    SegTree st(a);
    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int idx;
            long long val;
            cin >> idx >> val;
            --idx;
            st.update(1, 0, n - 1, idx, val);
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            cout << st.query(1, 0, n - 1, l, r) << '\n';
        }
    }

    return 0;
}
