// Coin Change

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, amount;
    cin >> n;
    vector<int> coins(n);
    for (int &x : coins) cin >> x;
    cin >> amount;

    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i) dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    cout << (dp[amount] > amount ? -1 : dp[amount]) << '\n';
    return 0;
}
