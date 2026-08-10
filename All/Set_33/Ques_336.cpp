// K-th smallest element (1-based k)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (k < 1 || k > n) { cout << -1; return 0; }
    nth_element(a.begin(), a.begin() + (k-1), a.end());
    cout << a[k-1];
    return 0;
}
