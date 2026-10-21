// Partition Array for Maximum Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), dp(n + 1);
    for (int &x : a) cin >> x;
    for (int i = 1; i <= n; i++) {
        int currentMax = 0;
        for (int length = 1; length <= k && i - length >= 0; length++) {
            currentMax = max(currentMax, a[i - length]);
            dp[i] = max(dp[i], dp[i - length] + currentMax * length);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
