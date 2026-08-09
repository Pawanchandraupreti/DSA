// Count inversions in an array (merge sort)

#include <bits/stdc++.h>
using namespace std;

long long merge_count(vector<long long>& a, int l, int r) {
    if (r - l <= 1) return 0;
    int m = (l + r) >> 1;
    long long cnt = merge_count(a, l, m) + merge_count(a, m, r);
    vector<long long> temp;
    int i = l, j = m;
    while (i < m || j < r) {
        if (j == r || (i < m && a[i] <= a[j])) temp.push_back(a[i++]);
        else { temp.push_back(a[j++]); cnt += (m - i); }
    }
    for (int k = l; k < r; ++k) a[k] = temp[k - l];
    return cnt;
}

int main() {
    int n; if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << merge_count(a, 0, n);
    return 0;
}

