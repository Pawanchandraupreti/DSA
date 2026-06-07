// Maximum subarray sum with at most one deletion

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
    int n; if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (n == 0) { cout << 0; return 0; }
    vector<long long> f(n), g(n);
    f[0] = a[0];
    for (int i = 1; i < n; ++i) f[i] = max(a[i], f[i-1] + a[i]);
    g[n-1] = a[n-1];
    for (int i = n-2; i >= 0; --i) g[i] = max(a[i], g[i+1] + a[i]);
    long long ans = f[0];
    for (int i = 0; i < n; ++i) ans = max(ans, f[i]);
    for (int i = 1; i < n-1; ++i) ans = max(ans, f[i-1] + g[i+1]);
    if (n >= 2) ans = max(ans, g[1]);
    cout << ans;
    return 0;
}
