// Maximum Product of Three Numbers

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (long long &x : a) cin >> x;
    sort(a.begin(), a.end());
    cout << max(a[n - 1] * a[n - 2] * a[n - 3], a[0] * a[1] * a[n - 1]) << '\n';
    return 0;
}
