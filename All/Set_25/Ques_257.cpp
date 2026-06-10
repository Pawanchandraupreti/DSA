// Maximum subarray sum with at most one deletion

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long noDel = a[0], oneDel = 0, ans = a[0];
    for (int i = 1; i < n; ++i) {
        long long prevNoDel = noDel;
        noDel = max(a[i], noDel + a[i]);
        oneDel = max(prevNoDel, oneDel + a[i]);
        ans = max(ans, max(noDel, oneDel));
    }
    cout << ans;
    return 0;
}
