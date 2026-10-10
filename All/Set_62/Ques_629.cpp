// Product of Array Except Self

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), ans(n);
    for (int &x : a) cin >> x;

    int prefix = 1;
    for (int i = 0; i < n; i++) {
        ans[i] = prefix;
        prefix *= a[i];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= suffix;
        suffix *= a[i];
    }

    for (int x : ans) cout << x << ' ';
    cout << '\n';
    return 0;
}
