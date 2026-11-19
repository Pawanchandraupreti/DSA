// Count Inversions

#include <bits/stdc++.h>
using namespace std;

long long mergeSort(vector<int> &a, int l, int r) {
    if (r - l <= 1) return 0;
    int mid = (l + r) / 2;
    long long ans = mergeSort(a, l, mid) + mergeSort(a, mid, r);
    vector<int> b;
    int i = l, j = mid;
    while (i < mid || j < r) {
        if (j == r || (i < mid && a[i] <= a[j])) {
            b.push_back(a[i++]);
        } else {
            ans += mid - i;
            b.push_back(a[j++]);
        }
    }
    copy(b.begin(), b.end(), a.begin() + l);
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    cout << mergeSort(a, 0, n) << '\n';
    return 0;
}


