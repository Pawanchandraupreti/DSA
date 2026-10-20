// Coin Change Number of Ways

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int &x : coins) cin >> x;
    vector<long long> dp(amount + 1);
    dp[0] = 1;
    for (int coin : coins) {
        for (int sum = coin; sum <= amount; sum++) dp[sum] += dp[sum - coin];
    }
    cout << dp[amount] << '\n';
    return 0;
}

