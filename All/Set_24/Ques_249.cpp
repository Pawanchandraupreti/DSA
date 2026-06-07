// Minimum number of coins to make amount (unbounded coin change)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
    int m; if (!(cin >> m)) return 0;
    vector<int> coins(m);
    for (int i = 0; i < m; ++i) cin >> coins[i];
    int amount; if (!(cin >> amount)) return 0;
    const int INF = 1e9;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    for (int c : coins) {
        for (int x = c; x <= amount; ++x) dp[x] = min(dp[x], dp[x - c] + 1);
    }
    if (dp[amount] >= INF) cout << -1;
    else cout << dp[amount];
    return 0;
}
