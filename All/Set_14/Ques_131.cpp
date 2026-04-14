// Segment Tree with Lazy Propagation (Range Add + Range Sum)
// Time Complexity: update/query O(log n), build O(n)

#include <iostream>
#include <vector>
using namespace std;

void build(int idx, int l, int r, vector<int>& arr, vector<long long>& seg) {
    if(l == r) {
        seg[idx] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * idx + 1, l, mid, arr, seg);
    build(2 * idx + 2, mid + 1, r, arr, seg);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

void push(int idx, int l, int r, vector<long long>& seg, vector<long long>& lazy) {
    if(lazy[idx] != 0) {
        seg[idx] += (r - l + 1) * lazy[idx];
        if(l != r) {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void update(int idx, int l, int r, int ql, int qr, int val,
            vector<long long>& seg, vector<long long>& lazy) {
    push(idx, l, r, seg, lazy);

    if(r < ql || l > qr) return;

    if(ql <= l && r <= qr) {
        lazy[idx] += val;
        push(idx, l, r, seg, lazy);
        return;
    }

    int mid = (l + r) / 2;
    update(2 * idx + 1, l, mid, ql, qr, val, seg, lazy);
    update(2 * idx + 2, mid + 1, r, ql, qr, val, seg, lazy);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

long long query(int idx, int l, int r, int ql, int qr,
                vector<long long>& seg, vector<long long>& lazy) {
    push(idx, l, r, seg, lazy);

    if(r < ql || l > qr) return 0;

    if(ql <= l && r <= qr) return seg[idx];

    int mid = (l + r) / 2;
    return query(2 * idx + 1, l, mid, ql, qr, seg, lazy) +
           query(2 * idx + 2, mid + 1, r, ql, qr, seg, lazy);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    vector<long long> seg(4 * n, 0), lazy(4 * n, 0);
    build(0, 0, n - 1, arr, seg);

    cout << query(0, 0, n - 1, 1, 3, seg, lazy) << "\n";

    update(0, 0, n - 1, 1, 4, 2, seg, lazy);
    cout << query(0, 0, n - 1, 1, 3, seg, lazy);
}
