// Reverse an array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = n - 1; i >= 0; --i) {
        if (i < n - 1) cout << ' ';
        cout << a[i];
    }
    return 0;
}

