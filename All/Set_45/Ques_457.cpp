// Kth Smallest Pair Distance

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    int lo = 0, hi = a.back() - a.front();
    while (lo < hi) {
        int mid = (lo + hi) / 2, count = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && a[j] - a[i] <= mid) j++;
            count += j - i - 1;
        }
        if (count >= k) hi = mid;
        else lo = mid + 1;
    }
    cout << lo;
    return 0;
}


