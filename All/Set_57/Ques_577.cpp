// Coin Change

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n), dp(amount + 1, amount + 1);
    for (int &coin : coins) cin >> coin;
    dp[0] = 0;
    for (int value = 1; value <= amount; value++) {
        for (int coin : coins) {
            if (coin <= value) dp[value] = min(dp[value], dp[value - coin] + 1);
        }
    }
    cout << (dp[amount] > amount ? -1 : dp[amount]) << '\n';
    return 0;
}
