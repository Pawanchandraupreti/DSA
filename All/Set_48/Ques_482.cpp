// Product of Array Except Self

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), ans(n, 1);
    for (long long &x : a) cin >> x;

    long long left = 1;
    for (int i = 0; i < n; i++) {
        ans[i] = left;
        left *= a[i];
    }

    long long right = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= right;
        right *= a[i];
    }

    for (long long x : ans) cout << x << ' ';
    cout << '\n';
    return 0;
}
