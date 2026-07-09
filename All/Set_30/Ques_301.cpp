// Maximum subarray sum using Kadane's algorithm

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    long long best = LLONG_MIN, current = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        current = max(x, current + x);
        best = max(best, current);
    }

    cout << best;
    return 0;
}