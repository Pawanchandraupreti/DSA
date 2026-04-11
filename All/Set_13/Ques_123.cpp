// Segment Tree (Range Sum Query + Point Update)

#include <iostream>
#include <vector>
using namespace std;

void build(int idx, int l, int r, vector<int>& arr, vector<int>& seg) {
    if(l == r) {
        seg[idx] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * idx, l, mid, arr, seg);
    build(2 * idx + 1, mid + 1, r, arr, seg);
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

int query(int idx, int l, int r, int ql, int qr, vector<int>& seg) {
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) return seg[idx];

    int mid = (l + r) / 2;
    return query(2 * idx, l, mid, ql, qr, seg) +
           query(2 * idx + 1, mid + 1, r, ql, qr, seg);
}

void update(int idx, int l, int r, int pos, int val, vector<int>& seg) {
    if(l == r) {
        seg[idx] = val;
        return;
    }

    int mid = (l + r) / 2;
    if(pos <= mid)
        update(2 * idx, l, mid, pos, val, seg);
    else
        update(2 * idx + 1, mid + 1, r, pos, val, seg);

    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int n = arr.size();

    vector<int> seg(4 * n, 0);
    build(1, 0, n - 1, arr, seg);

    cout << query(1, 0, n - 1, 1, 3, seg) << "\n";

    update(1, 0, n - 1, 1, 10, seg);
    cout << query(1, 0, n - 1, 1, 3, seg);
}
