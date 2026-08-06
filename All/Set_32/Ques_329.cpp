// Maximum sum subarray of fixed size k

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long window = 0;
    for (int i = 0; i < k && i < n; ++i) window += a[i];

    long long best = window;
    for (int i = k; i < n; ++i) {
        window += a[i] - a[i - k];
        best = max(best, window);
    }

    cout << best;
    return 0;
}
