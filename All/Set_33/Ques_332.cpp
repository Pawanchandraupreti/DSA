// Minimum coins to form sum (unbounded)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int m; long long target;
    if (!(cin >> m >> target)) return 0;
    vector<int> coins(m);
    for (int i = 0; i < m; ++i) cin >> coins[i];

    const long long INF = 1LL<<60;
    vector<long long> dp(target+1, INF);
    dp[0] = 0;
    for (int s = 1; s <= target; ++s) {
        for (int c : coins) if (c <= s && dp[s-c] != INF) dp[s] = min(dp[s], dp[s-c] + 1);
    }

    if (dp[target] == INF) cout << -1;
    else cout << dp[target];
    return 0;
}

