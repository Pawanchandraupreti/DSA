// Rotate array to the right by k positions

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; long long k;
    if (!(cin >> n >> k)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (n == 0) return 0;
    k %= n;
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << a[(i - k + n) % n];
    }
    return 0;
}

