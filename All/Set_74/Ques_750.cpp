// Burst Balloons Maximum Coins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 2, 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));
    for (int length = 1; length <= n; length++) {
        for (int left = 1; left + length - 1 <= n; left++) {
            int right = left + length - 1;
            for (int last = left; last <= right; last++) {
                dp[left][right] = max(dp[left][right], dp[left][last - 1] + a[left - 1] * a[last] * a[right + 1] + dp[last + 1][right]);
            }
        }
    }
    cout << dp[1][n] << '\n';
    return 0;
}
