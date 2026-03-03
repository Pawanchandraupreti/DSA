// Coin Change – Minimum Coins (Unbounded Knapsack)

#include <iostream>
#include <climits>
using namespace std;

int main() {
    int coins[] = {1, 2, 5};
    int n = 3;
    int amount = 11;

    int dp[12];

    for (int i = 0; i <= amount; i++)
        dp[i] = INT_MAX;

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }

    if (dp[amount] == INT_MAX)
        cout << -1;
    else
        cout << dp[amount];

    return 0;
}
