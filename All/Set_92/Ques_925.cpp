// Minimum Path Sum in a Grid

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m));
    for (auto &row : dp) for (int &x : row) cin >> x;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (r == 0 && c == 0) continue;
            int best = INT_MAX;
            if (r) best = min(best, dp[r - 1][c]);
            if (c) best = min(best, dp[r][c - 1]);
            dp[r][c] += best;
        }
    }
    cout << dp[n - 1][m - 1] << '\n';
    return 0;
}
