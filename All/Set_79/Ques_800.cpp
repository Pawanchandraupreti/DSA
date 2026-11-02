// Minimum Cost to Merge Stones

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> stones(n), prefix(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
        prefix[i + 1] = prefix[i] + stones[i];
    }
    if ((n - 1) % (k - 1)) {
        cout << -1 << '\n';
        return 0;
    }
    vector<vector<int>> dp(n, vector<int>(n));
    for (int length = k; length <= n; length++) for (int left = 0; left + length <= n; left++) {
        int right = left + length - 1;
        dp[left][right] = INT_MAX;
        for (int middle = left; middle < right; middle += k - 1) dp[left][right] = min(dp[left][right], dp[left][middle] + dp[middle + 1][right]);
        if ((length - 1) % (k - 1) == 0) dp[left][right] += prefix[right + 1] - prefix[left];
    }
    cout << dp[0][n - 1] << '\n';
    return 0;
}
