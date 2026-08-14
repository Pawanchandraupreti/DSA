// Maximum subarray sum using Kadane's algorithm

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long curr = a[0], best = a[0];
    for (int i = 1; i < n; ++i) {
        curr = max(a[i], curr + a[i]);
        best = max(best, curr);
    }

    cout << best;
    return 0;
}


