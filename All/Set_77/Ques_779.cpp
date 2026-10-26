// Minimum Cost to Cut a Stick

#include <bits/stdc++.h>
using namespace std;

int main() {
    int length, n;
    cin >> length >> n;
    vector<int> cuts(n + 2);
    cuts[0] = 0;
    cuts[n + 1] = length;
    for (int i = 1; i <= n; i++) cin >> cuts[i];
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));
    for (int size = 2; size <= n + 1; size++) for (int left = 0; left + size <= n + 1; left++) {
        int right = left + size;
        dp[left][right] = INT_MAX;
        for (int cut = left + 1; cut < right; cut++) dp[left][right] = min(dp[left][right], cuts[right] - cuts[left] + dp[left][cut] + dp[cut][right]);
        if (dp[left][right] == INT_MAX) dp[left][right] = 0;
    }
    cout << dp[0][n + 1] << '\n';
    return 0;
}
