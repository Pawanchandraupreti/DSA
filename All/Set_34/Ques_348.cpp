// Find the second largest number in an array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    if (n < 2) {
        cout << -1;
        return 0;
    }

    cout << a[n - 2];
    return 0;
}
