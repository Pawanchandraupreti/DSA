// Count inversions using merge sort

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll merge_count(vector<int> &a, int l, int m, int r) {
    vector<int> left(a.begin() + l, a.begin() + m + 1);
    vector<int> right(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0, k = l;
    ll inv = 0;

    while (i < (int)left.size() && j < (int)right.size()) {
        if (left[i] <= right[j]) a[k++] = left[i++];
        else {
            a[k++] = right[j++];
            inv += (int)left.size() - i;
        }
    }

    while (i < (int)left.size()) a[k++] = left[i++];
    while (j < (int)right.size()) a[k++] = right[j++];
    return inv;
}

ll solve(vector<int> &a, int l, int r) {
    if (l >= r) return 0;
    int m = l + (r - l) / 2;
    ll inv = solve(a, l, m) + solve(a, m + 1, r);
    inv += merge_count(a, l, m, r);
    return inv;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << solve(a, 0, n - 1);
    return 0;
}

