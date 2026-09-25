// Maximum Product Subarray

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (long long &x : a) cin >> x;

    long long currentMax = a[0], currentMin = a[0], answer = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < 0) swap(currentMax, currentMin);
        currentMax = max(a[i], currentMax * a[i]);
        currentMin = min(a[i], currentMin * a[i]);
        answer = max(answer, currentMax);
    }

    cout << answer << '\n';
    return 0;
}
