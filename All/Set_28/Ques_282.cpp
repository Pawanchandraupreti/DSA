// Persistent segment tree for k-th smallest in subarray

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int left = 0, right = 0, sum = 0;
};

vector<Node> seg;
vector<int> roots, values;

int update(int prev, int l, int r, int pos) {
    int cur = (int)seg.size();
    seg.push_back(seg[prev]);
    seg[cur].sum++;
    if (l != r) {
        int m = (l + r) >> 1;
        if (pos <= m) seg[cur].left = update(seg[prev].left, l, m, pos);
        else seg[cur].right = update(seg[prev].right, m + 1, r, pos);
    }
    return cur;
}

int kth(int leftRoot, int rightRoot, int l, int r, int k) {
    if (l == r) return l;
    int leftCount = seg[seg[rightRoot].left].sum - seg[seg[leftRoot].left].sum;
    int m = (l + r) >> 1;
    if (k <= leftCount) return kth(seg[leftRoot].left, seg[rightRoot].left, l, m, k);
    return kth(seg[leftRoot].right, seg[rightRoot].right, m + 1, r, k - leftCount);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<int> a(n + 1);
    values.reserve(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        values.push_back(a[i]);
    }
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    int m = values.size();
    seg.reserve((n + q + 5) * 20);
    seg.push_back(Node());
    roots.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int pos = lower_bound(values.begin(), values.end(), a[i]) - values.begin() + 1;
        roots[i] = update(roots[i - 1], 1, m, pos);
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        int idx = kth(roots[l - 1], roots[r], 1, m, k);
        cout << values[idx - 1] << '\n';
    }
    return 0;
}
