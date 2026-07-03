// Count number of ways to reach the end in a grid with obstacles

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const ll MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];

    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    if (grid[0][0] == '#') {
        cout << 0;
        return 0;
    }

    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') continue;
            if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }

    cout << dp[n - 1][m - 1] % MOD;
    return 0;
}

