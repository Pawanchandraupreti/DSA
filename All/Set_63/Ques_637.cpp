// Coin Change Minimum Coins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int &coin : coins) cin >> coin;

    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int sum = 1; sum <= amount; sum++) {
        for (int coin : coins) {
            if (coin <= sum) dp[sum] = min(dp[sum], dp[sum - coin] + 1);
        }
    }
    cout << (dp[amount] > amount ? -1 : dp[amount]) << '\n';
    return 0;
}
