// Minimum number of coins needed to make a target sum

#include <bits/stdc++.h>
using namespace std;

int minimumCoins(const vector<int>& coins, int target) {
    const int INF = 1e9;
    vector<int> dp(target + 1, INF);
    dp[0] = 0;

    for (int amount = 1; amount <= target; ++amount) {
        for (int coin : coins) {
            if (coin <= amount && dp[amount - coin] != INF) {
                dp[amount] = min(dp[amount], dp[amount - coin] + 1);
            }
        }
    }

    return dp[target] == INF ? -1 : dp[target];
}

int main() {
    int n, target;
    if (!(cin >> n >> target)) return 0;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    cout << minimumCoins(coins, target);
    return 0;
}

