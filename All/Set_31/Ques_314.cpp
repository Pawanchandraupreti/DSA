// Find the maximum element in a matrix

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    long long mx = LLONG_MIN;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long x;
            cin >> x;
            mx = max(mx, x);
        }
    }

    cout << mx;
    return 0;
}
