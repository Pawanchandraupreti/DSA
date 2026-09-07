// Maximum Product Subarray

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;

    long long high = a[0], low = a[0], ans = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < 0) swap(high, low);
        high = max(a[i], high * a[i]);
        low = min(a[i], low * a[i]);
        ans = max(ans, high);
    }

    cout << ans;
    return 0;
}
