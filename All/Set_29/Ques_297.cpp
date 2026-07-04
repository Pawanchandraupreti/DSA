// Minimum number of coins to make a sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    if (!(cin >> n >> target)) return 0;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];

    const int inf = 1e9;
    vector<int> dp(target + 1, inf);
    dp[0] = 0;

    for (int coin : coins) {
        for (int sum = coin; sum <= target; ++sum) {
            dp[sum] = min(dp[sum], dp[sum - coin] + 1);
        }
    }

    if (dp[target] == inf) cout << -1;
    else cout << dp[target];

    return 0;
}